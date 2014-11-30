
#ifndef _BARONOFHELL_H_
#define _BARONOFHELL_H_

#include "Monster.h"
#include "Sprite.h"
#include "Game.h"
#include "D2dedir.h"

class BaronOfHell : public Monster {

public:

    BaronOfHell(int _x, int _y, int _dir);
    virtual ~BaronOfHell();

    virtual void draw(cgf::Game* game);
    virtual void think();
    virtual void kill();

private:

    int x;
    int y;
    int dir;

};

#endif // _BARONOFHELL_H_
