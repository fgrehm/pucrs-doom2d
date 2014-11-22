
#ifndef _INVENTORY_H_
#define _INVENTORY_H_

#include "InvItem.h"
#include "Weapon.h"
#include "Shotgun.h"

#include <vector>
#include "Projectiles.h"

class Inventory {

public:

    Inventory(Projectiles *projs);
    ~Inventory();

    // shotgun stuff
    void refillShotgun(int qty);
    void addShotgun();
    bool hasShotgun();
    void removeShotgun();
    void selectShotgun();

    Weapon* getSelectedWeapon();

    void processInvItem(InvItem *newitem);

private:

    std::vector<InvItem*> inventory;

    Projectiles *projectiles;
    Weapon *shotgun;

    Weapon *selected;

};

#endif // _INVENTORY_H_
