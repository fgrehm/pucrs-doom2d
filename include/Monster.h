
#ifndef _MONSTER_H_
#define _MONSTER_H_

#include "Sprite.h"
#include "Game.h"
#include "D2dedir.h"

class Monster {

friend class PlayState;

public:

    Monster(int x, int y, int dir, const char img[]);
    virtual ~Monster(){}

    void kill();

    void draw(cgf::Game* game);
    bool isAlive();
    void playKillSound();

protected:

    cgf::Sprite *sprite;
    int getXMultFromDir(int dir);
    int getYMultFromDir(int dir);
    int x, y, z, dir;

    const char* monsterImage;

    sf::SoundBuffer killSoundBuffer;
    sf::Sound killSound;

    bool alive;

private:

};

#endif // _MONSTER_H_
