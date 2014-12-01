
#include "Weapon.h"

Weapon::Weapon(Projectiles *projs, int init_ammo, const char projectileSoundPath[]):
ammo(init_ammo)
{
    projectiles = projs;
    projectileSoundBuffer.loadFromFile(projectileSoundPath);
    projectileSound.setBuffer(projectileSoundBuffer);
    projectileSound.setAttenuation(0);
}

Weapon::~Weapon(){
}

void Weapon::replenishAmmo(int amqty){
    ammo += amqty;
}

void Weapon::playSound() {
    projectileSound.play();
}
