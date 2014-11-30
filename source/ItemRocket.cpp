
#include "ItemRocket.h"

ItemRocket::ItemRocket(int _x, int _y):
x(_x),
y(_y)
{

    sprite = new cgf::Sprite();
    sprite->load("data/img/rocket.png");
    sprite->scale(1.2, 1.2);
    sf::Vector2f vpos = sf::Vector2f();
    vpos.x = x;
    vpos.y = y;
    sprite->setPosition(vpos);

}

ItemRocket::~ItemRocket(){
    if (sprite){
        delete sprite;
    }
}

void ItemRocket::visit(Inventory *iv) {
    iv->refillRocketLauncher(1);
}

void ItemRocket::draw(cgf::Game* game){
    game->getScreen()->draw(*sprite);
}
