#include <iostream>
#include <SDL.h>
using std::cout;
using std::endl;


int main(int argc, char* argv[]) {
    cout << "Hello, World!" << endl;
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window *sdlWindow = SDL_CreateWindow("FirstFrame",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,800, SDL_WINDOW_SHOWN);

    SDL_Renderer *sdlRenderer = SDL_CreateRenderer(sdlWindow, -1 , 0 );

    SDL_SetRenderDrawColor(sdlRenderer, 0 , 255 , 255 ,0);
    SDL_RenderClear(sdlRenderer);
    SDL_RenderPresent(sdlRenderer);

    SDL_Delay(3000);

    return 0;
}
