
#ifndef _H_BULLET_H_
#define _H_BULLET_H_

#include "Game.h"
#include "Sprite.h"
#include "Projectile.h"

class Bullet : public Projectile {

public:

    Bullet(int _x, int _y, int _dir);
    ~Bullet();

    virtual void draw(cgf::Game* game);

private:

    int x;
    int y;
    int dir;

};

#endif // _H_BULLET_H_
