
#ifndef _WEAPON_H_
#define _WEAPON_H_

#include "Projectiles.h"

class Weapon
{
public:

    Weapon(Projectiles *projs, int init_ammo);
    ~Weapon();

    virtual void fire(int x, int y, int dir) = 0;
    void replenishAmmo(int amqty);

protected:

    Projectiles *projectiles;
    int ammo;

};

#endif // _WEAPON_H_
