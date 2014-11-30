
#ifndef _H_PISTOL_H_
#define _H_PISTOL_H_

#include "Projectiles.h"
#include "Weapon.h"

class Pistol : public Weapon {

public:

    Pistol(Projectiles* projs);
    ~Pistol();

    virtual void fire(int x, int y, int dir);

private:

};

#endif // _H_PISTOL_H_
