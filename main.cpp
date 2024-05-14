#include <iostream>
#include <SDL.h>
#include "map.h"

int main(int argc, char *argv[]) {
    using namespace std;

    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Event event;

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        cout << "SDL initialization failed: " << SDL_GetError() << endl;
        return 1;
    }

    if (auto error = SDL_CreateWindowAndRenderer(1280, 720,
                                                 SDL_WINDOW_RESIZABLE, &window, &renderer)) {
        cout << "Failed to create window and renderer: " << SDL_GetError() << endl;
        SDL_Quit();
        return 1;
                                                 }

    SDL_Surface *surface = SDL_LoadBMP("C:/Users/mateu/CLionProjects/SDL/map_background.bmp");
    if (surface == nullptr) {
        cout << "Failed to load map background texture: " << SDL_GetError() << endl;
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    Map gameMap(72, 128);
    gameMap.generateMap();


    int playing = 1;
    while (playing) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    playing = false;
                break;
            }
        }

        SDL_RenderClear(renderer);
        gameMap.renderMap(renderer,texture,  10);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
