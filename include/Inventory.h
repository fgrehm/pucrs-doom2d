
#ifndef _INVENTORY_H_
#define _INVENTORY_H_

#include "InvItem.h"
#include "Weapon.h"

#include "Shotgun.h"
#include "Pistol.h"
#include "RocketLauncher.h"

#include <vector>
#include "Projectiles.h"

class InvItem;

class Inventory {

public:

    Inventory(Projectiles *projs);
    ~Inventory();

    // pistol stuff
    //void refillPiston(int qty);
    void addPistol();
    bool hasPistol();
    void selectPistol();

    // shotgun stuff
    void refillShotgun(int qty);
    void addShotgun();
    bool hasShotgun();
    void selectShotgun();

    // rocketlauncher stuff
    void refillRocketLauncher(int qty);
    void addRocketLauncher();
    bool hasRocketLauncher();
    void selectRocketLauncher();

    Weapon* getSelectedWeapon();

    void processInvItem(InvItem *newitem);

private:

    bool haspistol;
    bool hasshotgun;
    bool hasrocketlauncher;

    std::vector<InvItem*> inventory;

    Projectiles *projectiles;
    Weapon *pistol;
    Weapon *shotgun;
    Weapon *rocketlauncher;

    Weapon *selected;

};

#endif // _INVENTORY_H_
