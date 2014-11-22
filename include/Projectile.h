
#ifndef _PROJECTILE_H_
#define _PROJECTILE_H_

#include "Game.h"
#include "D2dedir.h"

class Projectile {

public:

    virtual void draw(cgf::Game* game) = 0;

protected:

    int getXMultFromDir(int dir);
    int getYMultFromDir(int dir);

private:

};

#endif // _PROJECTILE_H_
