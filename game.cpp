#include "game.h"

Game::Game() {
    player_1.setId(1);
    player_2.setId(2);
}

Game::~Game() {
}

void Game::render(SDL_Renderer *renderer, SDL_Texture *texture) {
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, nullptr, nullptr);

    for (Bullet bullet: bullets) {
        bullet.render(renderer);
    }

    SDL_RenderCopyEx(renderer, player_1.getText(), &player_1.getSource(), &player_1.getDest(), 0, nullptr,
                     SDL_FLIP_NONE);
    SDL_RenderCopyEx(renderer, player_2.getText(), &player_2.getSource(), &player_2.getDest(), 0, nullptr,
                     SDL_FLIP_NONE);
    for (Object wall: walls) {
        SDL_RenderCopyEx(renderer, wall.getText(), &wall.getSource(), &wall.getDest(), 0, nullptr, SDL_FLIP_NONE);
        // SDL_RenderCopyEx(renderer, platformL.getText(), &platformL.getSource(), &platformL.getDest(), 0, nullptr,
        //                  SDL_FLIP_NONE);
        // SDL_RenderCopyEx(renderer, platformR.getText(), &platformR.getSource(), &platformR.getDest(), 0, nullptr,
        //                  SDL_FLIP_NONE);
    }

    SDL_RenderPresent(renderer);
}

void Game::createPlayer(SDL_Renderer *renderer) {
    player_1.setDest(60, 500, 40, 60);
    player_1.setImage("C:/Users/mateu/CLionProjects/SDL/img/player1_1.bmp", renderer);
    player_1.setSource(0, 0, 250, 500);

    player_2.setDest(1180, 500, 40, 60);
    player_2.setImage("C:/Users/mateu/CLionProjects/SDL/img/player2_1.bmp", renderer);
    player_2.setSource(0, 0, 250, 500);
}

void Game::drawMapO(SDL_Renderer *renderer) {
    floor.setDest(0, 695, 1280, 25);
    floor.setImage("C:/Users/mateu/CLionProjects/SDL/img/wall.bmp", renderer);
    floor.setSource(0, 0, 25, 25);
    walls.push_back(floor);

    platformL.setDest(150, 500, 200, 25);
    platformL.setImage("C:/Users/mateu/CLionProjects/SDL/img/wall.bmp", renderer);
    platformL.setSource(0, 0, 25, 25);
    walls.push_back(platformL);

    platformR.setDest(930, 500, 200, 25);
    platformR.setImage("C:/Users/mateu/CLionProjects/SDL/img/wall.bmp", renderer);
    platformR.setSource(0, 0, 25, 25);
    walls.push_back(platformR);

    platformM.setDest(380, 400, 520, 25);
    platformM.setImage("C:/Users/mateu/CLionProjects/SDL/img/wall.bmp", renderer);
    platformM.setSource(0, 0, 25, 25);
    walls.push_back(platformM);

    WallL.setDest(0, 0, 5, 720);
    WallL.setImage("C:/Users/mateu/CLionProjects/SDL/img/wall.bmp", renderer);
    WallL.setSource(0, 0, 25, 25);
    walls.push_back(WallL);

    WallR.setDest(1275, 0, 5, 720);
    WallR.setImage("C:/Users/mateu/CLionProjects/SDL/img/wall.bmp", renderer);
    WallR.setSource(0, 0, 25, 25);
    walls.push_back(WallR);
}


void Game::input(bool &playing) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) { playing = false; }
        if (event.type == SDL_KEYDOWN) {
            if (event.key.keysym.sym == SDLK_w) { u = true; }
            if (event.key.keysym.sym == SDLK_a) {
                l = true;
                r = false;
            }
            if (event.key.keysym.sym == SDLK_d) {
                r = true;
                l = false;
            }
            if (event.key.keysym.sym == SDLK_SPACE) {
                shoot(player_1);
            }
            if (event.key.keysym.sym == SDLK_UP) { u2 = true; }
            if (event.key.keysym.sym == SDLK_LEFT) {
                l2 = true;
                r2 = false;
            }
            if (event.key.keysym.sym == SDLK_RIGHT) {
                r2 = true;
                l2 = false;
            }
            if (event.key.keysym.sym == SDLK_SLASH) {
                shoot(player_2);
            }
        }
        if (event.type == SDL_KEYUP) {
            if (event.key.keysym.sym == SDLK_w) { u = false; }
            if (event.key.keysym.sym == SDLK_a) { l = false; }
            if (event.key.keysym.sym == SDLK_d) { r = false; }
            if (event.key.keysym.sym == SDLK_UP) { u2 = false; }
            if (event.key.keysym.sym == SDLK_LEFT) { l2 = false; }
            if (event.key.keysym.sym == SDLK_RIGHT) { r2 = false; }
        }
    }
}

void Game::updatePlayer(Player &player, int speed) {
    if (player.getId() == 1) {
        int newDX = player.getDX();
        int newDY = player.getDY();

        if (l) { newDX -= speed; }
        if (r) { newDX += speed; }

        if (!mapCollision(player, floor, newDX - player.getDX(), 0)
            && !mapCollision(player, platformL, newDX - player.getDX(), 0)
            && !mapCollision(player, platformR, newDX - player.getDX(),0)
            && !mapCollision(player, platformM, newDX - player.getDX(),0)
            && !mapCollision(player, WallL, newDX - player.getDX(),0)
            && !mapCollision(player, WallR, newDX - player.getDX(),0)) {
            player.setDest(newDX, player.getDY());
        }

        bool fall = true;
        if (u && player.getFuel() != 0) {
            newDY -= speed;
            player.setFuel(player.getFuel() - 1);
        } else { newDY += speed; }

        if (mapCollision(player, floor, 0, newDY - player.getDY())
            || mapCollision(player, platformL, 0, newDY - player.getDY())
            || mapCollision(player, platformR, 0, newDY - player.getDY())
            || mapCollision(player, platformM, 0, newDY - player.getDY())
            || mapCollision(player, WallL, 0, newDY - player.getDY())
            || mapCollision(player, WallR, 0, newDY - player.getDY())) {
            fall = false;
            player.setFuel(100);
        }

        if (!fall) {
            newDY = player_1.getDY();
        } else {
            player.setDest(player.getDX(), newDY);
        }

        if (!u && fall) {
            player.setDest(player.getDX(), player.getDY() + speed);
        }

        for (Bullet bullet: bullets)
            if (shootCollision(player_1, bullet, 0, 0)) {
                player_1.setDest(60, 500);
            }
    } else {
        int newDX = player.getDX();
        int newDY = player.getDY();

        if (l2) { newDX -= speed; }
        if (r2) { newDX += speed; }

        if (!mapCollision(player, floor, newDX - player.getDX(), 0)
            && !mapCollision(player, platformL, newDX - player.getDX(), 0)
            && !mapCollision(player, platformR, newDX - player.getDX(),0)
            && !mapCollision(player, platformM, newDX - player.getDX(),0)
            && !mapCollision(player, WallL, newDX - player.getDX(),0)
            && !mapCollision(player, WallR, newDX - player.getDX(),0)) {
            player.setDest(newDX, player.getDY());
        }

        bool fall = true;
        if (u2 && player.getFuel() != 0) {
            newDY -= speed;
            player.setFuel(player.getFuel() - 1);
        } else { newDY += speed; }

        if (mapCollision(player, floor, 0, newDY - player.getDY())
            || mapCollision(player, platformL, 0, newDY - player.getDY())
            || mapCollision(player, platformR, 0, newDY - player.getDY())
            || mapCollision(player, platformM, 0, newDY - player.getDY())
            || mapCollision(player, WallL, 0, newDY - player.getDY())
            || mapCollision(player, WallR, 0, newDY - player.getDY())) {
            fall = false;
            player.setFuel(100);
        }

        if (!fall) {
            newDY = player_1.getDY();
        } else {
            player.setDest(player.getDX(), newDY);
        }

        if (!u2 && fall) {
            player.setDest(player.getDX(), player.getDY() + speed);
        }
        for (Bullet bullet: bullets)
            if (shootCollision(player_2, bullet, 0, 0)) {
                player_2.setDest(1180, 500);
            }
    }
}


void Game::update() {
    int speed = 3;
    updatePlayer(player_1, speed);
    updatePlayer(player_2, speed);
    for (Bullet &bullet: bullets) {
        bullet.update();
    }
}

bool Game::mapCollision(Player &player, Object &o, int dx, int dy) {
    int playerLeft = player.getDX() + dx;
    int playerRight = player.getDX() + player.getDW() + dx;
    int playerTop = player.getDY() + dy;
    int playerBottom = player.getDY() + player.getDH() + dy;

    int objectLeft = o.getDX();
    int objectRight = o.getDX() + o.getDW();
    int objectTop = o.getDY();
    int objectBottom = o.getDY() + o.getDH();

    return (playerRight > objectLeft && playerLeft < objectRight &&
            playerBottom > objectTop && playerTop < objectBottom);
}

bool Game::shootCollision(Player &player, Bullet &o, int dx, int dy) {
    int playerLeft = player.getDX() + dx;
    int playerRight = player.getDX() + player.getDW() + dx;
    int playerTop = player.getDY() + dy;
    int playerBottom = player.getDY() + player.getDH() + dy;

    int objectLeft = o.getDX();
    int objectRight = o.getDX() + o.getDW();
    int objectTop = o.getDY();
    int objectBottom = o.getDY() + o.getDH();

    return (playerRight > objectLeft && playerLeft < objectRight &&
            playerBottom > objectTop && playerTop < objectBottom);
}

void Game::shoot(const Player &player) {
    if (player.getId() == 1) {
        Bullet bullet(player.getDX() + player.getDW() + 4, player.getDY() + player.getDH() / 2, 7);
        bullets.push_back(bullet);
    } else {
        Bullet bullet(player.getDX() - 10, player.getDY() + player.getDH() / 2, -7);
        bullets.push_back(bullet);
    }
}
