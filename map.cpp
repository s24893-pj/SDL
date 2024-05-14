#include "map.h"

Map::Map(int rows, int cols) : rows(rows), cols(cols) {
    tiles.resize(rows, std::vector<int>(cols, 0));
}


void Map::generateMap() {
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            if (row == 0 || row == rows - 1 || col == 0 || col == cols - 1) {
                tiles[row][col] = 1;
            } else {
                tiles[row][col] = 0;
            }
        }
    }
}

void Map::renderMap(SDL_Renderer* renderer, SDL_Texture* backgroundTexture, int tileSize) {
    SDL_Color wallColor = {0, 0, 0, 255};

    SDL_RenderCopy(renderer, backgroundTexture, nullptr, nullptr);

    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            int x = col * tileSize;
            int y = row * tileSize;

            if (tiles[row][col] == 1) {
                SDL_SetRenderDrawColor(renderer, wallColor.r, wallColor.g, wallColor.b, wallColor.a);
                SDL_Rect rect = {x, y, tileSize, tileSize};
                SDL_RenderFillRect(renderer, &rect);
            }

        }
    }
}
