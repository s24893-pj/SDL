#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include "player.h"
#include "object.h"
#include "bullet.h"




class Game {
public:
    Game();
    ~Game();
    // void loop();
    void input(bool &playing);
    // void drawMap();
    void update();
    // bool mapCollision(Player player, Object o);
    bool mapCollision(Player& player, Object& o, int dx, int dy);
    void createPlayer(SDL_Renderer *renderer);
    void updatePlayer(Player &player, int speed);
    void render(SDL_Renderer *renderer, SDL_Texture *texture);
    bool Game::shootCollision(Player &player, Bullet &b, int dx, int dy);
    void shoot(const Player &player);
    // void renderShoot();
    int z = 0;

    std::vector<Bullet> bullets;
    void drawMapO(SDL_Renderer *renderer);
private:
    Player player_1;
    Player player_2;
    Object floor;
    Object platformL;
    Object platformR;
    Object platformM;



    bool l, r, u = false, d, fall;
    bool l2, r2, u2 = false, d2;


};


#endif