
#ifndef _H_PELLETS_H_
#define _H_PELLETS_H_

#include "Game.h"
#include "Sprite.h"
#include "Projectile.h"

class Pellets : public Projectile {

public:

    Pellets(int _x, int _y, int _dir);
    ~Pellets();

    virtual void draw(cgf::Game* game);

private:

    int x;
    int y;
    int dir;

    cgf::Sprite *pelsprite;

};

#endif // _H_PELLETS_H_
