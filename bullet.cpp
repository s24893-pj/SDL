#include "bullet.h"

Bullet::Bullet(int x, int y, int direction) : x(x), y(y), width(10), height(5), direction(direction) {

}

void Bullet::update() {
    x = x+direction;
}

void Bullet::render(SDL_Renderer *renderer) {
    SDL_Rect rect = {x, y, width, height};
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &rect);
}
