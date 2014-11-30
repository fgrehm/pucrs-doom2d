
#include "CyberDemon.h"

CyberDemon::CyberDemon(int _x, int _y, int _dir):
x(_x),
y(_y),
dir(_dir)
{

    sprite = new cgf::Sprite();
    sprite->load("data/img/cyberdemon.png");
    sprite->scale(1.3, 1.3);
    sf::Vector2f vpos = sf::Vector2f();
    vpos.x = x;
    vpos.y = y;
    sprite->setPosition(vpos);
    int dirx = getXMultFromDir(dir);
    int diry = getYMultFromDir(dir);

}

CyberDemon::~CyberDemon()
{
}

void CyberDemon::draw(cgf::Game* game){
    game->getScreen()->draw(*sprite);
}

void CyberDemon::think(){

}

void CyberDemon::kill(){
    alive=false;
    sprite->load("data/img/cyberdemon_dead.png");
    sprite->scale(1.3, 1.3);
}
