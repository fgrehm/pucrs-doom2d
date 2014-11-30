
#ifndef _PINKDEMON_H_
#define _PINKDEMON_H_

#include "Monster.h"
#include "Sprite.h"
#include "Game.h"
#include "D2dedir.h"

class PinkDemon : public Monster {

public:

    PinkDemon(int _x, int _y, int _dir);
    virtual ~PinkDemon();

    virtual void draw(cgf::Game* game);
    virtual void think();

private:

    int x;
    int y;
    int dir;

};

#endif // _PINKDEMON_H_
