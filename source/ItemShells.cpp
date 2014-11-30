
#include "ItemShells.h"

ItemShells::ItemShells(int _x, int _y):
x(_x),
y(_y)
{

    sprite = new cgf::Sprite();
    sprite->load("data/img/buckshot.png");
    sprite->scale(1.2, 1.2);
    sf::Vector2f vpos = sf::Vector2f();
    vpos.x = x;
    vpos.y = y;
    sprite->setPosition(vpos);

}

ItemShells::~ItemShells(){
    if (sprite){
        delete sprite;
    }
}

void ItemShells::visit(Inventory *iv) {
    iv->refillShotgun(8);
}

void ItemShells::draw(cgf::Game* game){
    game->getScreen()->draw(*sprite);
}
