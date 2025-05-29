#include <SDL2/SDL.h>

#define XSIZE 600
#define YSIZE 600
#define MS 10
#define NAVE_LEN 20
#define NAVE_VEL 10
#define MISIL_LEN 5
#define MISIL_VEL 5

typedef struct Nave Nave;
typedef struct Misil Misil;

struct Nave
{
    int x1, y1;
    int x2, y2;
    int x3, y3;
    int vx, vy;
    Misil *misiles;
};

struct Misil
{
    int x1, y1;
    int x2, y2;
    int vx, vy;
    Misil *siguiente;
};

// prototipos de funciones a utilizar
void pintarNave(Nave *nave, SDL_Renderer *renderer);
void dispararNave(Nave *nave);
void avanzarMisil(Misil *misil);
void borarMisilesObsoletos(Misil *misiles);

int main(int argc, char* args[])
{
    // iniciar el SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", SDL_GetError(), NULL);
        SDL_Quit();
        return -1;
    } else
    {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "OK", "SDL iniciado", NULL);
    }


    const unsigned char *keys;
    int typeEvent;
    int gameOver;
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Event event;
    Nave nave = {XSIZE/2, YSIZE/2, XSIZE/2-NAVE_LEN, YSIZE/2+NAVE_LEN, XSIZE/2+NAVE_LEN, YSIZE/2+NAVE_LEN, NAVE_LEN, NAVE_VEL, NULL};

    window = SDL_CreateWindow("Nave", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, XSIZE, YSIZE, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    gameOver = 0;
    keys = SDL_GetKeyboardState(NULL);

    while (!gameOver)
    {
        if (SDL_PollEvent(&event))
        {
            typeEvent = event.type;
            if (typeEvent == SDL_QUIT)
            {
                gameOver = 1;
            } else if (typeEvent == SDL_MOUSEBUTTONDOWN)
            {
                if (SDL_GetMouseState(NULL, NULL) && SDL_BUTTON(SDL_BUTTON_LEFT))
                {
                    // pendiente...
                    dispararNave(&nave);
                }
                
                SDL_BUTTON(SDL_BUTTON_LEFT);
            } else if (typeEvent == SDL_KEYDOWN)
            {
                if (keys[SDL_SCANCODE_ESCAPE])
                {
                    gameOver = 1;
                } else if (keys[SDL_SCANCODE_LEFT])
                {
                    /* code */
                    nave.x1 -= nave.vx;
                    nave.x2 -= nave.vx;
                    nave.x3 -= nave.vx;
                } else if (keys[SDL_SCANCODE_RIGHT])
                {
                    /* code */
                    nave.x1 += nave.vx;
                    nave.x2 += nave.vx;
                    nave.x3 += nave.vx;
                } else if (keys[SDL_SCANCODE_UP])
                {
                    /* code */
                    nave.y1 -= nave.vy;
                    nave.y2 -= nave.vy;
                    nave.y3 -= nave.vy;
                } else if (keys[SDL_SCANCODE_DOWN])
                {
                    /* code */
                    nave.y1 += nave.vy;
                    nave.y2 += nave.vy;
                    nave.y3 += nave.vy;
                } else if (keys[SDL_SCANCODE_SPACE])
                {
                    /* code */
                    dispararNave(&nave);
                }
            }
        }
        borarMisilesObsoletos(nave.misiles);
        // pantalla
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
        pintarNave(&nave, renderer);

        SDL_RenderPresent(renderer);
        SDL_Delay(MS);
        
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    
    return 0;
}

void pintarNave(Nave *nave, SDL_Renderer *renderer)
{
    //pintar misiles
    Misil *ixMisil = nave->misiles;
    while (ixMisil != NULL)
    {
        avanzarMisil(ixMisil);
        SDL_RenderDrawLine(renderer, ixMisil->x1, ixMisil->y1, ixMisil->x2, ixMisil->y2);
        ixMisil = ixMisil->siguiente;
    }    
    //pintar nave
    SDL_Point points[4] = {
        {nave->x1, nave->y1},
        {nave->x2, nave->y2},
        {nave->x3, nave->y3}
    };
    points[3] = points[0];
    SDL_RenderDrawLines(renderer, points, 4);
}

void dispararNave(Nave *nave)
{
    if (nave->misiles == NULL)
    {
        nave->misiles = (Misil *) SDL_malloc(sizeof(Misil));
        nave->misiles->x1 = nave->x1;
        nave->misiles->y1 = nave->y1;
        nave->misiles->x2 = nave->x1;
        nave->misiles->y2 = nave->y1 - MISIL_LEN;
        nave->misiles->vx = 0;
        nave->misiles->vy = -MISIL_VEL;
        nave->misiles->siguiente = NULL;
    } else {
        Misil *ixMisil = nave->misiles;
        while (ixMisil->siguiente != NULL)
        {
            ixMisil = ixMisil->siguiente;
        }
        ixMisil->siguiente = (Misil *) SDL_malloc(sizeof(Misil));
        ixMisil = ixMisil->siguiente;
        ixMisil->x1 = nave->x1;
        ixMisil->y1 = nave->y1;
        ixMisil->x2 = nave->x1;
        ixMisil->y2 = nave->y1 - MISIL_LEN;
        ixMisil->vx = 0;
        ixMisil->vy = -MISIL_VEL;
        ixMisil->siguiente = NULL;
        
    }
    
}

void avanzarMisil(Misil *misil)
{
    misil->x1 += misil->vx;
    misil->y1 += misil->vy;
    misil->x2 += misil->vx;
    misil->y2 += misil->vy;
}

void borarMisilesObsoletos(Misil *misiles)
{
    Misil *ixMisil = misiles;
    if (ixMisil == NULL)
    {
        return;
    }
    Misil *auxMisil;
    while (ixMisil->siguiente != NULL)
    {
        if (ixMisil->siguiente->y1 < 0)
        {
            auxMisil = ixMisil->siguiente->siguiente;
            SDL_free(ixMisil->siguiente);
            ixMisil->siguiente = auxMisil;
        } else 
        {
            ixMisil = ixMisil->siguiente;
        }
        
    }
    
    
}