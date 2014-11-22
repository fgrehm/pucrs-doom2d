
#ifndef _PROJECTILES_H_
#define _PROJECTILES_H_

#include "GameState.h"
#include "Projectile.h"
#include <vector>

class Projectiles {

public:

    Projectiles();
    ~Projectiles();

    void update();
    void draw(cgf::Game* game);

    void spawnNew(Projectile *proj);

private:

    std::vector<Projectile*> projectiles;

};

#endif // _PROJECTILES_H_
