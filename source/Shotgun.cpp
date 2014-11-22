
#include "Shotgun.h"
#include "Pellets.h"

Shotgun::Shotgun(Projectiles* projs):
Weapon(projs, 20)
{
}

Shotgun::~Shotgun(){
}

void Shotgun::fire(int x, int y, int dir){
    if (ammo > 0){
        projectiles->spawnNew(new Pellets(x, y, dir));
        ammo--;
    }
}
