#include "Game.h"
#include "TextureManager.h"


using std::cout;
using std::endl;

SDL_Texture* playerTexture;
SDL_Rect* srcR, DestR;


Game::Game()
{}
Game::~Game()
{}

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen) {
    int flags = 0;
    if (fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        cout << "SDL Initialized!" << endl;

        window = SDL_CreateWindow(title,xpos,ypos, width, height, flags);
        if (window)
        {
            cout << "Window Created!" << endl;
        }

        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
        if (renderer)
        {
            SDL_SetRenderDrawColor(renderer, 255, 255 ,255 , 255);
            cout << "Renderer Created!" << endl;
        }
        isRunning = true;
    } else{ isRunning = false; }

    playerTexture = TextureManager::LoadTexture("Assets/player.png",renderer);

}

void Game::update() {
    cnt++;
    DestR.h = 128;
    DestR.w = 128;
    DestR.x = cnt;
}

void Game::render() {
    SDL_RenderClear(renderer);
    // Add here to render things
    SDL_RenderCopy(renderer, playerTexture,NULL,&DestR);

    SDL_RenderPresent(renderer);
}

void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    cout << "Everything Cleaned!" << endl;
}

void Game::handleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type) {
        case SDL_QUIT:
            isRunning = false;
            break;

        default:
            break;
    }
}
