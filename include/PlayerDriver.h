
#ifndef _PLAYERDRIVER_H_
#define _PLAYERDRIVER_H_

#include "Player.h"
#include "InputManager.h"

class PlayerDriver {

public:

    PlayerDriver(const Player &p, cgf::InputManager* _im);
    ~PlayerDriver();

    void receiveInput(const sf::Event &evt);

private:

    Player theplayer;
    cgf::InputManager* im;

};

#endif // _PLAYERDRIVER_H_
