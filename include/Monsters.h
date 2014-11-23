
#ifndef _MONSTERS_H_
#define _MONSTERS_H_

#include "Player.h"
#include "GameState.h"
#include "Monster.h"
#include <vector>

class Monsters {

friend class PlayState;

public:

    Monsters(Player *pl);
    ~Monsters();

    void update();
    void draw(cgf::Game* game);

    void spawnNew(Monster *mon);

    void kill(const int);

private:

    std::vector<Monster*> monsters;
    Player *player;

};

#endif // _MONSTERS_H_
