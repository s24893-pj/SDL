#ifndef MAP_H
#define MAP_H

#include <vector>
#include <SDL.h>
#include "object.h"

class Map {
private:
    std::vector<std::vector<int> > tiles;
    int rows;
    int cols;
    // std::vector<object> test;
public:
    Map(int rows, int cols);

    void generateMap();

    void renderMap(SDL_Renderer *renderer, SDL_Texture *texture, int tileSize);

    void setRowsAndCols(int r, int c);

    [[nodiscard]] std::vector<std::vector<int> > getTiles() const { return tiles; }
    [[nodiscard]] int getRows() const { return rows; }
    [[nodiscard]] int getCols() const { return cols; }
};

#endif
