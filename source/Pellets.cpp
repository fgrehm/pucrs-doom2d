
#include "Pellets.h"

Pellets::Pellets(int _x, int _y, int _dir):
x(_x),
y(_y),
dir(_dir)
{

    sprite = new cgf::Sprite();
    sprite->load("data/img/pellets.png");
    sprite->scale(0.5, 0.5);
    sf::Vector2f vpos = sf::Vector2f();
    vpos.x = x;
    vpos.y = y;
    sprite->setPosition(vpos);
    int dirx = getXMultFromDir(dir);
    int diry = getYMultFromDir(dir);
    sprite->setXspeed(dirx * 500);
    sprite->setYspeed(diry * 500);

}

Pellets::~Pellets(){
    if (sprite){
        delete sprite;
    }
}

void Pellets::draw(cgf::Game* game){
    game->getScreen()->draw(*sprite);
}
