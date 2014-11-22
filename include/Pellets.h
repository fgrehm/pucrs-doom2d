
#ifndef _H_PELLETS_H_
#define _H_PELLETS_H_

#include "Projectile.h"

class Pellets : public Projectile {

public:

    Pellets(int _x, int _y, int _dir);
    ~Pellets();

private:

    int x;
    int y;
    int dir;

};

#endif // _H_PELLETS_H_
