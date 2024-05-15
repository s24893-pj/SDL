#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include "player.h"
#include "map.h"




class Game {
public:
    Game();
    ~Game();
    void loop();
    void input();
    void drawMap();
    bool collision();
    void createPlayer(SDL_Renderer *renderer);
    void drawPlayer();
    void render(SDL_Renderer *renderer, SDL_Texture *texture);
private:
    Player player_1;
    Player player_2;
    Map gameMap;


};


#endif