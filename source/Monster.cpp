#include <string.h>
#include "Monster.h"

Monster::Monster(int x, int y, int dir, const char img[]):
x(x),
y(y),
dir(dir),
sprite(0),
alive(true),
monsterImage(img)
{
    sprite = new cgf::Sprite();

    char i[100];
    strcpy(i, "");
    strcat(i, "data/img/");
    strcat(i, monsterImage);
    strcat(i, ".png");
    sprite->load(i);

    sprite->scale(1.3, 1.3);
    sf::Vector2f vpos = sf::Vector2f();
    vpos.x = x;
    vpos.y = y;
    sprite->setPosition(vpos);
    int dirx = getXMultFromDir(dir);
    int diry = getYMultFromDir(dir);

    killSoundBuffer.loadFromFile("data/audio/kill.wav");
    killSound.setBuffer(killSoundBuffer);
    killSound.setAttenuation(0);
}

void Monster::draw(cgf::Game* game){
    game->getScreen()->draw(*sprite);
}

int Monster::getXMultFromDir(int dir){

    switch (dir){

        case D2DEDIR_LEFT:
            return -1;
            break;
        case D2DEDIR_DOWN:
            return 0;
            break;
        case D2DEDIR_RIGHT:
            return 1;
            break;
        case D2DEDIR_UP:
            return 0;
            break;
        case D2DEDIR_LEFTDOWN:
            return -1;
            break;
        case D2DEDIR_DOWNRIGHT:
            return 1;
            break;
        case D2DEDIR_RIGHTUP:
            return 1;
            break;
        case D2DEDIR_UPLEFT:
            return -1;
            break;
        default:
            break;

    }

}

int Monster::getYMultFromDir(int dir){

    switch (dir){

        case D2DEDIR_LEFT:
            return 0;
            break;
        case D2DEDIR_DOWN:
            return 1;
            break;
        case D2DEDIR_RIGHT:
            return 0;
            break;
        case D2DEDIR_UP:
            return -1;
            break;
        case D2DEDIR_LEFTDOWN:
            return 1;
            break;
        case D2DEDIR_DOWNRIGHT:
            return 1;
            break;
        case D2DEDIR_RIGHTUP:
            return -1;
            break;
        case D2DEDIR_UPLEFT:
            return -1;
            break;
        default:
            break;

    }

}

bool Monster::isAlive(){
    return alive;
}

void Monster::kill(){
    alive=false;

    char i[100];
    strcpy(i, "");
    strcat(i, "data/img/");
    strcat(i, monsterImage);
    strcat(i, "_dead.png");
    sprite->load(i);

    sprite->scale(1.3, 1.3);
    playKillSound();
}

void Monster::playKillSound(){
    killSound.play();
}
