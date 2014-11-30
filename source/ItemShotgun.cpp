
#include "ItemShotgun.h"

ItemShotgun::ItemShotgun(int _x, int _y):
x(_x),
y(_y)
{

    sprite = new cgf::Sprite();
    sprite->load("data/img/shotgun.png");
    sprite->scale(1.2, 1.2);
    sf::Vector2f vpos = sf::Vector2f();
    vpos.x = x;
    vpos.y = y;
    sprite->setPosition(vpos);

}

ItemShotgun::~ItemShotgun(){
    if (sprite){
        delete sprite;
    }
}

void ItemShotgun::visit(Inventory *iv) {
    iv->addShotgun();
}

void ItemShotgun::draw(cgf::Game* game){
    game->getScreen()->draw(*sprite);
}
