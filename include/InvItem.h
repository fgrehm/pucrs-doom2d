
#ifndef _INVITEM_H_
#define _INVITEM_H_

#include "Inventory.h"
#include "Sprite.h"
#include "Game.h"

class Inventory;

class InvItem {

public:

    InvItem();
    virtual ~InvItem(){}

    virtual void draw(cgf::Game* game) = 0;
    virtual void visit(Inventory *) = 0;

    cgf::Sprite *getSprite();

protected:

    cgf::Sprite *sprite;

};

#endif // _INVITEM_H_
