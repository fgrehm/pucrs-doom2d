
#include "Bullet.h"

Bullet::Bullet(int _x, int _y, int _dir):
x(_x),
y(_y),
dir(_dir)
{

    sprite = new cgf::Sprite();
    sprite->load("data/img/bullet.png");
    sprite->scale(0.7, 0.7);
    sf::Vector2f vpos = sf::Vector2f();
    vpos.x = x;
    vpos.y = y;
    sprite->setPosition(vpos);
    int dirx = getXMultFromDir(dir);
    int diry = getYMultFromDir(dir);
    sprite->setXspeed(dirx * 350);
    sprite->setYspeed(diry * 350);

}

Bullet::~Bullet(){
    if (sprite){
        delete sprite;
    }
}

void Bullet::draw(cgf::Game* game){
    game->getScreen()->draw(*sprite);
}
