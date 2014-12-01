
#include "Shotgun.h"
#include "Pellets.h"

Shotgun::Shotgun(Projectiles* projs):
Weapon(projs, 20, "data/audio/shotgun.wav")
{
}

Shotgun::~Shotgun(){
}

void Shotgun::fire(int x, int y, int dir){
    if (ammo > 0){
        projectiles->spawnNew(new Pellets(x, y, dir));
        playSound();
        ammo--;
    }
}
