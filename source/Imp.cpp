
#include "Imp.h"

Imp::Imp(int _x, int _y, int _dir):
x(_x),
y(_y),
dir(_dir)
{

    sprite = new cgf::Sprite();
    sprite->load("data/img/imp.png");
    sprite->scale(1.3, 1.3);
    sf::Vector2f vpos = sf::Vector2f();
    vpos.x = x;
    vpos.y = y;
    sprite->setPosition(vpos);
    int dirx = getXMultFromDir(dir);
    int diry = getYMultFromDir(dir);

}

Imp::~Imp()
{
}

void Imp::draw(cgf::Game* game){
    game->getScreen()->draw(*sprite);
}

void Imp::think(){

}
