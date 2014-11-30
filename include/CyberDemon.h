
#ifndef _CYBERDEMON_H_
#define _CYBERDEMON_H_

#include "Monster.h"
#include "Sprite.h"
#include "Game.h"
#include "D2dedir.h"

class CyberDemon : public Monster {

public:

    CyberDemon(int _x, int _y, int _dir);
    virtual ~CyberDemon();

    virtual void draw(cgf::Game* game);
    virtual void think();
    virtual void kill();

private:

    int x;
    int y;
    int dir;

};

#endif // _CYBERDEMON_H_
