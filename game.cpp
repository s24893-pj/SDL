#include "game.h"

Game::Game(): gameMap(1280, 720) {
    player_1.setId(1);
    player_2.setId(2);
}

Game::~Game() {

}


void Game::drawMap() {
    gameMap.generateMap();
}

void Game::render(SDL_Renderer *renderer, SDL_Texture *texture) {
    SDL_RenderClear(renderer);
    gameMap.renderMap(renderer, texture, 10);
    SDL_RenderCopyEx(renderer, player_1.getText(), &player_1.getSource(), &player_1.getDest(), 0, NULL, SDL_FLIP_NONE);
    SDL_RenderPresent(renderer);
}

void Game::createPlayer(SDL_Renderer *renderer) {
    player_1.setDest(100, 200, 40, 60);
    player_1.setImage("C:/Users/mateu/CLionProjects/SDL/img/player1_1.bmp", renderer);
    player_1.setSource(0, 0, 250, 500);
}



