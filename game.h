#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include "player.h"
#include "map.h"
#include "object.h"




class Game {
public:
    Game();
    ~Game();
    void loop();
    void input(bool &playing);
    void drawMap();
    void update();
    bool mapCollision(Player player, Object o);
    bool mapCollision(Player& player, Object& o, int dx, int dy);
    void createPlayer(SDL_Renderer *renderer);
    void drawPlayer();
    void render(SDL_Renderer *renderer, SDL_Texture *texture);

    void drawMapO(SDL_Renderer *renderer);
private:
    Player player_1;
    Player player_2;
    Object floor;
    Object platformL;
    Object platformR;
    Object platformM;
    Map gameMap;
    bool l, r, u = false, d, fall;


};


#endif