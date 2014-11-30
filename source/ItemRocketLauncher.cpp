
#include "ItemRocketLauncher.h"

ItemRocketLauncher::ItemRocketLauncher(int _x, int _y):
x(_x),
y(_y)
{

    sprite = new cgf::Sprite();
    sprite->load("data/img/rocketlauncher.png");
    sprite->scale(1.2, 1.2);
    sf::Vector2f vpos = sf::Vector2f();
    vpos.x = x;
    vpos.y = y;
    sprite->setPosition(vpos);

}

ItemRocketLauncher::~ItemRocketLauncher(){
    if (sprite){
        delete sprite;
    }
}

void ItemRocketLauncher::visit(Inventory *iv) {
    iv->refillShotgun(8);
}

void ItemRocketLauncher::draw(cgf::Game* game){
    game->getScreen()->draw(*sprite);
}
