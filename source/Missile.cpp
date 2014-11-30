
#include "Missile.h"

Missile::Missile(int _x, int _y, int _dir):
x(_x),
y(_y),
dir(_dir)
{

    sprite = new cgf::Sprite();
    sprite->load(getNameByDir());
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

const char *Missile::getNameByDir() const {

    if (dir == D2DEDIR_DOWN || dir == D2DEDIR_LEFTDOWN){
        return "data/img/missile_down.png";
    }

    if (dir == D2DEDIR_LEFT || dir == D2DEDIR_UPLEFT){
        return "data/img/missile_left.png";
    }

    if (dir == D2DEDIR_UP || dir == D2DEDIR_RIGHTUP){
        return "data/img/missile_up.png";
    }

    if (dir == D2DEDIR_RIGHT || dir == D2DEDIR_DOWNRIGHT){
        return "data/img/missile_right.png";
    }

}
