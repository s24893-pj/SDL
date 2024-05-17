#ifndef BULLET_H
#define BULLET_H

#include  <SDL.h>

class Bullet{
    private:
    int x, y, width, height, speed, direction;
    public:
    Bullet(int x, int y, int direction);
    void update();
    void render(SDL_Renderer *renderer);
    [[nodiscard]] int getDX() const {return x;}
    [[nodiscard]] int getDY() const {return y;}
    [[nodiscard]] int getDW() const {return height;}
    [[nodiscard]] int getDH() const {return width;}


};

#endif