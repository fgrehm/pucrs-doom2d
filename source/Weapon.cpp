
#include "Weapon.h"

Weapon::Weapon(Projectiles *projs, int init_ammo):
ammo(init_ammo)
{
    projectiles = projs;
}

Weapon::~Weapon(){
}

void Weapon::replenishAmmo(int amqty){
    ammo += amqty;
}
