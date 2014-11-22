
#include "Inventory.h"

Inventory::Inventory(Projectiles *projs):
projectiles(projs),
shotgun(0),
selected(0)
{
}

Inventory::~Inventory(){
    for (int i=0; i<inventory.size(); ++i){
        delete inventory[i];
    }
    removeShotgun();
}

void Inventory::removeShotgun(){
    if (hasShotgun()){
        delete shotgun;
    }
}

void Inventory::addShotgun(){
    removeShotgun();
    shotgun = new Shotgun(projectiles);
}

void Inventory::refillShotgun(int qty){
    shotgun->replenishAmmo(qty);
}

bool Inventory::hasShotgun(){
    if (shotgun == 0){
        return false;
    } else {
        return true;
    }
}

void Inventory::selectShotgun(){
    // if no shotgun present, should throw exception
    selected = shotgun;
}

Weapon* Inventory::getSelectedWeapon(){
    return selected;
}

void Inventory::processInvItem(InvItem *newitem){
    newitem->visit(this);
}
