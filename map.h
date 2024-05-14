#ifndef MAP_H
#define MAP_H

#include <vector>
#include <SDL.h>

class Map {

private:
    std::vector<std::vector<int> > tiles;
    int rows;
    int cols;

public:
    Map(int rows, int cols);

    void generateMap();

    void renderMap(SDL_Renderer* renderer,SDL_Texture* texture , int tileSize);
};

#endif
