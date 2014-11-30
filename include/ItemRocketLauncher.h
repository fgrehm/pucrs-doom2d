
#ifndef _ITEMROCKETLAUNCHER_H_
#define _ITEMROCKETLAUNCHER_H_

#include "Inventory.h"
#include "InvItem.h"

class Inventory;

class ItemRocketLauncher : public InvItem {

public:

    ItemRocketLauncher(int _x, int _y);
    ~ItemRocketLauncher();

    virtual void draw(cgf::Game* game);
    virtual void visit(Inventory *);

private:

    int x;
    int y;

};

#endif // _ITEMROCKETLAUNCHER_H_
