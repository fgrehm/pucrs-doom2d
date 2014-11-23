
#include "Monsters.h"

Monsters::Monsters(Player *pl):
player(pl)
{

}

Monsters::~Monsters(){
    for (int i=0; i<monsters.size(); ++i){
        delete monsters[i];
    }
}

void Monsters::update(){
}

void Monsters::draw(cgf::Game* game){

    for (int i=0; i< monsters.size(); ++i){
        monsters[i]->draw(game);
    }

}

void Monsters::spawnNew(Monster *proj){
    monsters.push_back(proj);
}

void Monsters::kill(const int index){
    monsters.erase(monsters.begin()+ index);
}
