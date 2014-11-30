
#include "Player.h"

#define PSPEED 200

Player::Player(Projectiles *projs):
psprite(0),
inventory(0),
pdir(D2DEDIR_DOWN)
{

    projectiles = projs;
    inventory =  new Inventory(projs);

    inventory->addPistol();
    inventory->selectPistol();

    psprite = new cgf::Sprite();

    psprite->load("data/img/hero_down.png");
    psprite->setPosition(50,100);

}

Player::~Player(){
    delete psprite;
    delete inventory;
}

void Player::setPosition(float x, float y){
    psprite->setPosition(x,y);
}

cgf::Sprite *Player::getSprite(){
    return psprite;
}

void Player::impulseLeft(){
    psprite->load("data/img/hero_left.png");
    psprite->play();
    psprite->setXspeed(-PSPEED);
    pdir =  D2DEDIR_LEFT;
}

void Player::impulseUp(){
    psprite->load("data/img/hero_up.png");
    psprite->play();
    psprite->setYspeed(-PSPEED);
    pdir = D2DEDIR_UP;
}

void Player::impulseRight(){
    psprite->load("data/img/hero_right.png");
    psprite->play();
    psprite->setXspeed(PSPEED);
    pdir = D2DEDIR_RIGHT;
}

void Player::impulseDown(){
    psprite->load("data/img/hero_down.png");
    psprite->play();
    psprite->setYspeed(PSPEED);
    pdir = D2DEDIR_DOWN;
}

void Player::impulseHalt(){
    psprite->setCurrentFrame(0);
    psprite->setYspeed(0);
    psprite->setXspeed(0);
    psprite->pause();
}

void Player::impulseShoot()
{
    sf::Vector2f ppos = psprite->getPosition();
    inventory->getSelectedWeapon()->fire(ppos.x, ppos.y, pdir);
}

void Player::draw(cgf::Game* game){
    game->getScreen()->draw(*psprite);
}

const sf::Vector2f& Player::getPosition(){
    return psprite->getPosition();
}

Inventory * Player::getInventory(){
    return this->inventory;
}

void Player::impulseSelectPistol(){
    this->inventory->selectPistol();
}

void Player::impulseSelectShotgun(){
    this->inventory->selectShotgun();
}

void Player::impulseSelectRocketLauncher(){
    this->inventory->selectRocketLauncher();
}
