
#include "RocketLauncher.h"
#include "Missile.h"

RocketLauncher::RocketLauncher(Projectiles* projs):
Weapon(projs, 2)
{
}

RocketLauncher::~RocketLauncher(){
}

void RocketLauncher::fire(int x, int y, int dir){
    if (ammo > 0){
        projectiles->spawnNew(new Missile(x, y, dir));
        ammo--;
    }
}
