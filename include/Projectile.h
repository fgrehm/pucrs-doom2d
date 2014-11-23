
#ifndef _PROJECTILE_H_
#define _PROJECTILE_H_

#include "Sprite.h"
#include "Game.h"
#include "D2dedir.h"

class Projectile {

friend class PlayState;

public:

    Projectile();
    virtual ~Projectile(){}

    virtual void draw(cgf::Game* game) = 0;

protected:

    cgf::Sprite *sprite;
    int getXMultFromDir(int dir);
    int getYMultFromDir(int dir);

private:

};

#endif // _PROJECTILE_H_
