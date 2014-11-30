
#include "Items.h"

Items::Items(Inventory *inv):
inventory(inv)
{
}

Items::~Items(){
    for (int i=0; i<items.size(); ++i){
        delete items[i];
    }
}

void Items::draw(cgf::Game* game){

    for (int i=0; i< items.size(); ++i){
        items[i]->draw(game);
    }

}

void Items::spawnNew(InvItem *itm){
    items.push_back(itm);
}

void Items::checkCollisionsWithPlayer(Player *pl){
    bool repeat=true;
    while (repeat){
        repeat=false;
        for (int i=0; i< items.size(); ++i){
            if (pl->getSprite()->circleCollision(*(items[i]->getSprite())) ) {
                items[i]->visit(inventory);
                items.erase(items.begin()+i);
                repeat=true;
                break;
            }
        }
    }
}
