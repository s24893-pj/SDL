#include "game.h"

Game::Game(): gameMap(710, 1270) {
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

void Game::input(bool &playing) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {playing = false;}
        if(event.type == SDL_KEYDOWN) {
            if(event.key.keysym.sym == SDLK_w){u = true;}
            if(event.key.keysym.sym == SDLK_a){l = true; r = false;}
            if(event.key.keysym.sym == SDLK_d){r = true; l = false;}
        }
        if(event.type == SDL_KEYUP) {
            if(event.key.keysym.sym == SDLK_w){u = false;}
            if(event.key.keysym.sym == SDLK_a){l = false;}
            if(event.key.keysym.sym == SDLK_d){r = false;}
        }
    }
}

void Game::update() {
    if (l){player_1.setDest(player_1.getDX()-1, player_1.getDY());}
    if (r){player_1.setDest(player_1.getDX()+1, player_1.getDY());}
    if (u){player_1.setDest(player_1.getDX(), player_1.getDY()-1);}
    // if (mapCollision(player_1)) {printf("XD");}
}

// bool Game::mapCollision(Player player) {
//     auto x = gameMap.getTiles();
//     if (x[gameMap.getRows()][gameMap.getCols()] == 1) {
//         if(player.getDY() < gameMap.getRows()) {
//             return true;
//         }
//     }else {return false;}
// }




