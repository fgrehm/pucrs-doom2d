
#include "PinkDemon.h"

PinkDemon::PinkDemon(int _x, int _y, int _dir):
x(_x),
y(_y),
dir(_dir)
{

    sprite = new cgf::Sprite();
    sprite->load("data/img/pinkdemon.png");
    sprite->scale(1.3, 1.3);
    sf::Vector2f vpos = sf::Vector2f();
    vpos.x = x;
    vpos.y = y;
    sprite->setPosition(vpos);
    int dirx = getXMultFromDir(dir);
    int diry = getYMultFromDir(dir);

}

PinkDemon::~PinkDemon()
{
}

void PinkDemon::draw(cgf::Game* game){
    game->getScreen()->draw(*sprite);
}

void PinkDemon::think(){

}
