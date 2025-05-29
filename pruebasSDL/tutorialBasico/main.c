#include <SDL2/SDL.h> // inclusion de la libreria SDL version 2


#define XSIZE 600 // El ancho de la ventana, en coordenadas de pantalla.
#define YSIZE 600 // El alto de la ventana, en coordenadas de pantalla.
#define MS 10 //tiempo de espera

// prototipos de funciones a utilizar
/**
 * Inicializacion de la funcion principal para una APP SDL**/
int main(int argc, char* args[])
{
    /* Utilice esta función para inicializar la biblioteca SDL. 
       Debe llamarse antes de utilizar cualquiera de las otras funciones de SDL.
       Inicializa automáticamente los subsistemas de manejo de eventos, E / S de archivos 
       y subprocesamiento y toma un parámetro que especifica qué otros subsistemas inicializar.
       en este caso inicializa todos los subsistemas basicos (la mayoria)*/
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) // Devuelve 0 en caso de éxito o devuelve -1 si no pudo inicializar un subsistema. (un código de error negativo en caso de error).
    {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", SDL_GetError(), NULL); // Crear un cuadro de mensaje modal simple para indicar un error
        SDL_Quit(); // finaliza la biblioteca SDL.
        return -1;
    } else
    {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "OK", "SDL iniciado", NULL); // Crear un cuadro de mensaje modal simple para indicar que inicio SDL correctamente
    }


    const unsigned char *keys;// Un array de los estados de las clave del teclado.
    int typeEvent; // almacena el tipo de evento
    int running; // corre la ejecucion de la pantalla
    SDL_Window *window; // puntero de tipo ventana SDL
    SDL_Renderer *renderer; // puntero de tipo estado de presentación (estado del renderizador).
    SDL_Event event; // almacena un evento
    
    /*Crea una ventana con la posición, las dimensiones y las banderas especificadas.*/
    window = SDL_CreateWindow("Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, XSIZE, YSIZE, SDL_WINDOW_SHOWN);
    /*Crea un contexto de renderizado 2D para una ventana.*/
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    running = 0; // si running es 0, entonces entrara en el while
    keys = SDL_GetKeyboardState(NULL); // Obtiene una instantánea del estado actual del teclado y retorna un array de estados clave.

    while (!running)// mientras que sea = 0 seguira corriendo
    {
        if (SDL_PollEvent(&event)) // el siguiente evento se elimina de la cola y se almacena en esa dirección de memoria.
        {
            typeEvent = event.type; // guarda el tipo de evento
            if (typeEvent == SDL_QUIT) // si opcion cerrar ventana
            {
                running = 1;// termina la ejecución de la pantalla
            } else if (typeEvent == SDL_MOUSEBUTTONDOWN) // si presionar boton del raton
            {
                if (SDL_GetMouseState(NULL, NULL) && SDL_BUTTON(SDL_BUTTON_LEFT))//  estado del mouse y si presiono el boton izquierdo del mouse
                {
                    // pendiente...
                    running = 1;
                }
            }
            
        }
        // pantalla
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);// Establece el color utilizado para las operaciones de dibujo
        SDL_RenderClear(renderer); // Limpia el objetivo de reproducción actual con el color del dibujo
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_RenderDrawLine(renderer, 10, 10, 100, 100); // Dibuja una línea en el objetivo de renderizado actual

        SDL_RenderPresent(renderer); // Actualiza la pantalla con el renderizado realizado.
        SDL_Delay(MS); // Espera un número especificado de milisegundos antes de regresar.
        
    }
    SDL_DestroyRenderer(renderer); // Destruye el contexto de renderizado de una ventana y las texturas asociadas libres.
    SDL_DestroyWindow(window); // destruye una ventana
    SDL_Quit();// finaliza la biblioteca SDL.
    
    return 0;
}// fin función main
