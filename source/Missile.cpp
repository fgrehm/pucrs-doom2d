
#include "Missile.h"

Missile::Missile(int _x, int _y, int _dir):
x(_x),
y(_y),
dir(_dir)
{

    sprite = new cgf::Sprite();
    sprite->load("data/img/missile.png");
    sprite->scale(1.2, 1.2);
    sf::Vector2f vpos = sf::Vector2f();
    vpos.x = x;
    vpos.y = y;
    sprite->setPosition(vpos);
    int dirx = getXMultFromDir(dir);
    int diry = getYMultFromDir(dir);
    sprite->setXspeed(dirx * 230);
    sprite->setYspeed(diry * 230);

}

Missile::~Missile(){
    if (sprite){
        delete sprite;
    }
}

void Missile::draw(cgf::Game* game){
    game->getScreen()->draw(*sprite);
}
