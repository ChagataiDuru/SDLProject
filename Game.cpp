#include "Game.h"

using std::cout;
using std::endl;

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

        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer)
        {
            SDL_SetRenderDrawColor(renderer, 255, 255 ,0 , 255);
            cout << "Renderer Created!" << endl;
        }
        isRunning = true;
    } else{ isRunning = false; }


}

void Game::update() {
    cnt++;
    cout << cnt << endl;
}

void Game::render() {
    SDL_RenderClear(renderer);
    // Add here to render things
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
