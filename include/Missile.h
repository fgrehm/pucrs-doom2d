
#ifndef _H_MISSILE_H_
#define _H_MISSILE_H_

#include "D2dedir.h"

#include "Game.h"
#include "Sprite.h"
#include "Projectile.h"

class Missile : public Projectile {

public:

    Missile(int _x, int _y, int _dir);
    ~Missile();

    virtual void draw(cgf::Game* game);

private:

    int x;
    int y;
    int dir;

    const char *getNameByDir() const;

};

#endif // _H_MISSILE_H_
