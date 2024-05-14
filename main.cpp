#include <SDL.h>
#include <iostream>

int main(int argc, char *argv[]) {
    using namespace std;

    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Event event;

    // SDL_Init(SDL_INIT_VIDEO);

    if (auto error = SDL_CreateWindowAndRenderer(1280, 720,
                                                 SDL_WINDOW_RESIZABLE, &window, &renderer)) {
        cout << "Nie udalo sie utworzyc okienka" << endl;
    }

    SDL_Surface *surface = SDL_LoadBMP("C:/Users/mateu/CLionProjects/SDL/map_background.bmp");
    if (surface == nullptr) {
        cout << "error ;(";
    }
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);


    int playing = 1;
    while (playing) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    playing = false;
                    break;

                default:
                    cout << event.type << endl;
                    break;
            }
        }


        SDL_SetRenderDrawColor(renderer, 0x00,0x00,0x00,0x00);

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, texture, nullptr, nullptr);
        SDL_RenderPresent(renderer);
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    //Quit SDL
    SDL_Quit();
    return 0;
}
