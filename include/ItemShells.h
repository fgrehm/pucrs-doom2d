
#ifndef _ITEMSHELLS_H_
#define _ITEMSHELLS_H_

#include "Inventory.h"
#include "InvItem.h"

class Inventory;

class ItemShells : public InvItem {

public:

    ItemShells(int _x, int _y);
    ~ItemShells();

    virtual void draw(cgf::Game* game);
    virtual void visit(Inventory *);

private:

    int x;
    int y;

};

#endif // _ITEMSHELLS_H_
