#ifndef OBJECT_H
#define OBJECT_H

#include <vector>
#include <SDL.h>
#include <string>
#include <iostream>
#include <ostream>
#include "object.h"

class Object {
private:
    SDL_Rect dest;
    SDL_Rect src;
    SDL_Texture *text;
public:
    Object();
    [[nodiscard]] SDL_Rect getDest() const {return dest;}
    [[nodiscard]] SDL_Rect getSource() const {return src;}
    void setDest(int x, int y, int w, int h);
    // void setDest(int x, int y);
    void setSource(int x, int y, int w, int h);
    void setImage(std::string filename, SDL_Renderer* renderer);
    [[nodiscard]] SDL_Texture* getText() const {return text;}

    [[nodiscard]] int getDX() const {return dest.x;}
    [[nodiscard]] int getDY() const {return dest.y;}
    [[nodiscard]] int getDW() const {return dest.w;}
    [[nodiscard]] int getDH() const {return dest.h;}
};


#endif
