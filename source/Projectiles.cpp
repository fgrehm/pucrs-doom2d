
#include "Projectiles.h"

Projectiles::Projectiles(){
}

Projectiles::~Projectiles(){
    for (int i=0; i<projectiles.size(); ++i){
        delete projectiles[i];
    }
}

void Projectiles::update(){
}

void Projectiles::draw(cgf::Game* game){

    for (int i=0; i< projectiles.size(); ++i){
        projectiles[i]->draw(game);
    }

}

void Projectiles::spawnNew(Projectile *proj){
    projectiles.push_back(proj);
}
