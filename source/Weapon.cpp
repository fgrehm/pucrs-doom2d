
#include "Weapon.h"

Weapon::Weapon(Projectiles *projs, int init_ammo):
projectiles(projs),
ammo(init_ammo)
{
}

Weapon::~Weapon(){
}

void Weapon::replenishAmmo(int amqty){
    ammo += amqty;
}
