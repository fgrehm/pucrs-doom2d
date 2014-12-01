
#ifndef _MONSTER_H_
#define _MONSTER_H_

#include "Sprite.h"
#include "Game.h"
#include "D2dedir.h"

class Monster {

friend class PlayState;

public:

    Monster();
    virtual ~Monster(){}

    virtual void think() = 0;
    virtual void kill() = 0;

    virtual void draw(cgf::Game* game) = 0;

    bool isAlive();
    void playKillSound();

protected:

    cgf::Sprite *sprite;
    int getXMultFromDir(int dir);
    int getYMultFromDir(int dir);

    sf::SoundBuffer killSoundBuffer;
    sf::Sound killSound;

    bool alive;

private:

};

#endif // _MONSTER_H_
