
#include "Pistol.h"
#include "Bullet.h"

Pistol::Pistol(Projectiles* projs):
Weapon(projs, 7)
{
}

Pistol::~Pistol(){
}

void Pistol::fire(int x, int y, int dir){
    if (ammo > 0){
        projectiles->spawnNew(new Bullet(x, y, dir));
        ammo--;
    }
}
