
#ifndef _ITEMS_H_
#define _ITEMS_H_

#include "Player.h"
#include "GameState.h"
#include "InvItem.h"
#include <vector>

#include "Inventory.h"

class Items {

public:

    Items(Inventory *inv);
    ~Items();

    void draw(cgf::Game* game);

    void spawnNew(InvItem *itm);

    void checkCollisionsWithPlayer(Player *pl);

private:

    std::vector<InvItem*> items;
    Inventory *inventory;

};

#endif // _ITEMS_H_
