
#ifndef _ITEMROCKET_H_
#define _ITEMROCKET_H_

#include "Inventory.h"
#include "InvItem.h"

class Inventory;

class ItemRocket : public InvItem {

public:

    ItemRocket(int _x, int _y);
    ~ItemRocket();

    virtual void draw(cgf::Game* game);
    virtual void visit(Inventory *);

private:

    int x;
    int y;

};

#endif // _ITEMROCKET_H_
