
#include "Pellets.h"

Pellets::Pellets(int _x, int _y, int _dir):
x(_x),
y(_y),
dir(_dir),
pelsprite(0)
{

    pelsprite = new cgf::Sprite();
    pelsprite->load("data/img/pellets.png");
    pelsprite->scale(0.5, 0.5);
    sf::Vector2f vpos = sf::Vector2f();
    vpos.x = x;
    vpos.y = y;
    pelsprite->setPosition(vpos);
    int dirx = getXMultFromDir(dir);
    int diry = getYMultFromDir(dir);
    pelsprite->setXspeed(dirx * 150);
    pelsprite->setYspeed(diry * 150);

}

Pellets::~Pellets(){
    if (pelsprite){
        delete pelsprite;
    }
}

void Pellets::draw(cgf::Game* game){
    game->getScreen()->draw(*pelsprite);
}
