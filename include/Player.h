
#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "D2dedir.h"

#include "Game.h"
#include "Sprite.h"

#include "Projectiles.h"
#include "Inventory.h"

#include <SFML/System/Vector2.hpp>

class Player {

public:

    Player(Projectiles *projs);
    ~Player();

    void setPosition(float x, float y);
    cgf::Sprite *getSprite();
    void draw(cgf::Game* gm);

    void impulseLeft();
    void impulseUp();
    void impulseRight();
    void impulseDown();
    void impulseHalt();

    void impulseShoot();

    const sf::Vector2f& getPosition();

    Inventory inventory;

private:

    int pdir;
    Projectiles *projectiles;
    cgf::Sprite *psprite;

};

#endif // _PLAYER_H_
