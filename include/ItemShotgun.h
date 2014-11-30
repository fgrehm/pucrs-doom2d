
#ifndef _ITEMSHOTGUN_H_
#define _ITEMSHOTGUN_H_

#include "Inventory.h"
#include "InvItem.h"

class Inventory;

class ItemShotgun : public InvItem {

public:

    ItemShotgun(int _x, int _y);
    ~ItemShotgun();

    virtual void draw(cgf::Game* game);
    virtual void visit(Inventory *);

private:

    int x;
    int y;

};

#endif // _ITEMSHOTGUN_H_
