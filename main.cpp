#include <iostream>
#include <SDL.h>

#include "map.h"
#include "player.h"
#include "game.h"

int main(int argc, char *argv[]) {
    using namespace std;

    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Event event;
    Game game;
    Player player;


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
    // player.setDest(100, 200, 40, 60);
    // player.setImage("C:/Users/mateu/CLionProjects/SDL/img/player1_1.bmp", renderer);
    // player.setSource(0, 0, 250, 500);
    game.createPlayer(renderer);

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

    // Map gameMap(72, 128);
    // gameMap.generateMap();

    game.drawMap();

    bool jump = false;

    int playing = 1;
    while (playing) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    playing = false;
                    break;
            }
            if (event.key.keysym.sym == SDLK_d) {
                player.setDest(player.getDX() + 1, player.getDY(), player.getDW(), player.getDH());
            }
            if (event.key.keysym.sym == SDLK_a) {
                player.setDest(player.getDX() - 1, player.getDY(), player.getDW(), player.getDH());
            }
        }

        // SDL_RenderClear(renderer);
        // gameMap.renderMap(renderer, texture, 10);
        // SDL_RenderCopyEx(renderer, player.getText(), &player.getSource(), &player.getDest(), 0, NULL, SDL_FLIP_NONE);
        // SDL_RenderPresent(renderer);
        game.render(renderer, texture);
    }

    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
