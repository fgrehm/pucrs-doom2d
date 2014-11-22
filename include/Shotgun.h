
#ifndef _H_SHOTGUN_H_
#define _H_SHOTGUN_H_

#include "Projectiles.h"
#include "Weapon.h"

class Shotgun : public Weapon {

public:

    Shotgun(Projectiles* projs);
    ~Shotgun();

    virtual void fire(int x, int y, int dir);

private:

};

#endif // _H_SHOTGUN_H_
