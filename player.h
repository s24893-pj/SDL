#ifndef PLAYER_H
#define PLAYER_H

#include <SDL.h>
#include <iostream>

class Player {
private:
    SDL_Rect dest;
    SDL_Rect src;
    SDL_Texture *text;
    bool solid;
    int id;
    int fuel;
public:
    Player();
    [[nodiscard]] SDL_Rect getDest() const {return dest;}
    [[nodiscard]] SDL_Rect getSource() const {return src;}
    void setFuel(int fuel);
    void setDest(int x, int y, int w, int h);
    void setDest(int x, int y);
    void setSource(int x, int y, int w, int h);
    void setImage(std::string filename, SDL_Renderer* renderer);
    [[nodiscard]] SDL_Texture* getText() const {return text;}

    [[nodiscard]] int getFuel() const {return fuel;}

    [[nodiscard]] int getDX() const {return dest.x;}
    [[nodiscard]] int getDY() const {return dest.y;}
    [[nodiscard]] int getDW() const {return dest.w;}
    [[nodiscard]] int getDH() const {return dest.h;}

    void setId(int i) {id = i;}
    [[nodiscard]] int getId() const {return id;}
};

#endif