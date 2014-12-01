
#include "RocketLauncher.h"
#include "Missile.h"

RocketLauncher::RocketLauncher(Projectiles* projs):
Weapon(projs, 2, "data/audio/rocket-launcher.wav")
{
}

RocketLauncher::~RocketLauncher(){
}

void RocketLauncher::fire(int x, int y, int dir){
    if (ammo > 0){
        projectiles->spawnNew(new Missile(x, y, dir));
        playSound();
        ammo--;
    }
}
