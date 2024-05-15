#include "player.h"

Player::Player() {

}


void Player::setDest(int x, int y, int w, int h) {
    dest.x=x;
    dest.y=y;
    dest.w=w;
    dest.h=h;
}
void Player::setDest(int x, int y) {
    dest.x=x;
    dest.y=y;
}
void Player::setSource(int x, int y, int w, int h) {
    src.x=x;
    src.y=y;
    src.w=w;
    src.h=h;
}
void Player::setImage(std::string filename, SDL_Renderer* ren) {

    SDL_Surface* surf;
    if(SDL_LoadBMP(filename.c_str()) < 0) {
        std::cout << "Failed at IMG_Load()" << std::endl;
    } else {
        surf= SDL_LoadBMP(filename.c_str());
    }
    text = SDL_CreateTextureFromSurface(ren, surf);

}