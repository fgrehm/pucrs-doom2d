
#ifndef _IMP_H_
#define _IMP_H_

#include "Monster.h"
#include "Sprite.h"
#include "Game.h"
#include "D2dedir.h"

class Imp : public Monster {

public:

    Imp(int _x, int _y, int _dir);
    virtual ~Imp();

    virtual void draw(cgf::Game* game);
    virtual void think();
    virtual void kill();

private:

    int x;
    int y;
    int dir;

};

#endif // _IMP_H_
