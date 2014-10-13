
#ifndef _PLAYER_H_
#define _PLAYER_H_

class Player {

public:

    Player(); // mvtodo: get a pointer to the world obj? monster col? projectiles manager?
    ~Player();

    void impulseLeft();
    void impulseUp();
    void impulseRight();
    void impulseDown();

    // mvtodo: inventory
    // mvtodo: currently selected weapon

private:

};

#endif // _PLAYER_H_
