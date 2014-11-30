
#ifndef _H_ROCKETLAUNCHER_H_
#define _H_ROCKETLAUNCHER_H_

#include "Projectiles.h"
#include "Weapon.h"

class RocketLauncher : public Weapon {

public:

    RocketLauncher(Projectiles* projs);
    ~RocketLauncher();

    virtual void fire(int x, int y, int dir);

private:

};

#endif // _H_ROCKETLAUNCHER_H_
