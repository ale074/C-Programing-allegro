#include <SDL2/SDL.h>
#include  <SDL2/SDL_ttf.h>

#define MS 10

void pintarCabeceraTabla(SDL_Renderer *renderer, char *msj);
void get_text_and_rect(SDL_Renderer *renderer, int x, int y, char *text,
        TTF_Font *font, SDL_Texture *texture, SDL_Rect rect);
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
    int runing = 0;
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Event event;

    window = SDL_CreateWindow("Función Polinómica", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 600, 600, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    TTF_Font* Sans = TTF_OpenFont("arial.ttf", 24); //this opens a font style and sets a size

    SDL_Color White = {255, 255, 255, 0};  // this is the color in rgb format, maxing out all would give you the color white, and it will be your text's color

    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Sans, "put your text here", White); // as TTF_RenderText_Solid could only be used on SDL_Surface then you have to create the surface first

    SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage); //now you can convert it into a texture
    
    SDL_Rect Message_rect; //create a rect
    Message_rect.x = 0;  //controls the rect's x coordinate 
    Message_rect.y = 0; // controls the rect's y coordinte
    Message_rect.w = 100; // controls the width of the rect
    Message_rect.h = 100; // controls the height of the rect

    keys = SDL_GetKeyboardState(NULL);

    while (!runing)
    {
        if (SDL_PollEvent(&event))
        {
            typeEvent = event.type;
            if (typeEvent == SDL_QUIT)
            {
                runing = 1;
            } else if (typeEvent == SDL_MOUSEBUTTONDOWN)
            {
                if (SDL_GetMouseState(NULL, NULL) && SDL_BUTTON(SDL_BUTTON_LEFT))
                {
                    // pendiente...
                }
                
                SDL_BUTTON(SDL_BUTTON_LEFT);
            } else if (typeEvent == SDL_KEYDOWN)
            {
                if (keys[SDL_SCANCODE_ESCAPE])
                {
                    runing = 1;
                } 
            }
        }
        // pantalla
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
        SDL_RenderCopy(renderer, Message, NULL, &Message_rect);
        SDL_RenderDrawLine(renderer, 10, 10, 100, 100); // Dibuja una línea en el objetivo de renderizado actual
        SDL_RenderPresent(renderer);
        SDL_Delay(MS);
        
    }
    SDL_FreeSurface(surfaceMessage);
    TTF_CloseFont(Sans);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();
    
    return 0;
}

void pintarCabeceraTabla(SDL_Renderer *renderer, char *msj)
{
    TTF_Font* Sans = TTF_OpenFont("Sans.ttf", 24); //this opens a font style and sets a size

    SDL_Color White = {255, 255, 255};  // this is the color in rgb format, maxing out all would give you the color white, and it will be your text's color

    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Sans, msj, White); // as TTF_RenderText_Solid could only be used on SDL_Surface then you have to create the surface first

    SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage); //now you can convert it into a texture

    SDL_Rect Message_rect; //create a rect
    Message_rect.x = 0;  //controls the rect's x coordinate 
    Message_rect.y = 0; // controls the rect's y coordinte
    Message_rect.w = 100; // controls the width of the rect
    Message_rect.h = 100; // controls the height of the rect

    //Mind you that (0,0) is on the top left of the window/screen, think a rect as the text's box, that way it would be very simple to understand

    //Now since it's a texture, you have to put RenderCopy in your game loop area, the area where the whole code executes

    SDL_RenderCopy(renderer, Message, NULL, &Message_rect); //you put the renderer's name first, the Message, the crop size(you can ignore this if you don't want to dabble with cropping), and the rect which is the size and coordinate of your texture

    //Don't forget to free your surface and texture
    SDL_FreeSurface(surfaceMessage);
    SDL_DestroyTexture(Message);
}
void get_text_and_rect(SDL_Renderer *renderer, int x, int y, char *text,
        TTF_Font *font, SDL_Texture *texture, SDL_Rect rect) {
    int text_width;
    int text_height;
    SDL_Surface *surface;
    SDL_Color textColor = {255, 255, 255, 0};

    surface = TTF_RenderText_Solid(font, text, textColor);
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    text_width = surface->w;
    text_height = surface->h;
    SDL_FreeSurface(surface);
    rect.x = x;
    rect.y = y;
    rect.w = text_width;
    rect.h = text_height;
}