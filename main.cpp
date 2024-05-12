#include "game.h"
#include <SDL.h>
#include <iostream>
#define SDL_MAIN_HANDLED

int main(int argc, char *argv[])
{
	using namespace std;
	SDL_Init( SDL_INIT_EVERYTHING );
	SDL_Window *window;
	SDL_Renderer *renderer;
	if (auto error = SDL_CreateWindowAndRenderer( 1280, 720,
		 SDL_WINDOW_SHOWN, &window, &renderer )) {
		cout << "Nie udalo sie utworzyc okienka" << endl;
		 }
	SDL_Event event;
	int playing = 1;
	while (playing) {
		while (SDL_PollEvent(&event)) {
			switch (event.type)
			{
				case SDL_QUIT:
					playing = false;
				break;

				default:
					cout << event.type << endl;
				break;
			}
		}

		SDL_SetRenderDrawColor(renderer, 255,0,0,255);
		SDL_RenderClear(renderer);
		SDL_RenderPresent(renderer);
	}
	SDL_DestroyRenderer( renderer );
	SDL_DestroyWindow( window );
	//Quit SDL
	SDL_Quit();
	return 0;
}
