
#include "Inventory.h"

Inventory::Inventory(Projectiles *projs):
pistol(0),
shotgun(0),
rocketlauncher(0),
haspistol(false),
hasshotgun(false),
hasrocketlauncher(false),
selected(0)
{
    projectiles = projs;

    pistol = new Pistol(projectiles);
    shotgun = new Shotgun(projectiles);
    rocketlauncher = new RocketLauncher(projectiles);

}

Inventory::~Inventory(){
    for (int i=0; i<inventory.size(); ++i){
        delete inventory[i];
    }
    delete pistol;
    delete shotgun;
    delete rocketlauncher;
}

void Inventory::addShotgun(){
    hasshotgun=true;
}

void Inventory::refillShotgun(int qty){
    shotgun->replenishAmmo(qty);
}

bool Inventory::hasShotgun(){
    return hasshotgun;
}

void Inventory::selectShotgun(){
    // mvtodo: if no shotgun present, should throw exception
    if (hasshotgun){
        selected = shotgun;
    }
}

Weapon* Inventory::getSelectedWeapon(){
    return selected;
}

void Inventory::processInvItem(InvItem *newitem){
    newitem->visit(this);
}

void Inventory::addPistol(){
    haspistol=true;
}

bool Inventory::hasPistol(){
    return haspistol;
}

void Inventory::selectPistol(){
    // mvtodo: if no pistol present, should throw exception
    if (haspistol){
        selected = pistol;
    }
}

void Inventory::addRocketLauncher(){
    hasrocketlauncher = true;
}

void Inventory::refillRocketLauncher(int qty){
    rocketlauncher->replenishAmmo(qty);
}

bool Inventory::hasRocketLauncher(){
    return hasrocketlauncher;
}

void Inventory::selectRocketLauncher(){
    // mvtodo: if no rocketlauncher present, should throw exception
    if (hasrocketlauncher){
        selected = rocketlauncher;
    }
}
