
#include "Player.h"

Player::Player(Projectiles *projs):
projectiles(projs),
inventory(projs),
pdir(D2DEDIR_DOWN)
{

    inventory.addPistol();
    inventory.selectPistol();

    psprite = new cgf::Sprite();

    psprite->loadXML("data/img/hunter.xml");
    psprite->setPosition(50,100);
    psprite->loadAnimation("data/img/hunteranim.xml");
    psprite->setAnimRate(15);

}

Player::~Player(){
    delete psprite;
}

void Player::setPosition(float x, float y){
    psprite->setPosition(x,y);
}

cgf::Sprite *Player::getSprite(){
    return psprite;
}

void Player::impulseLeft(){
    psprite->setAnimation("walk-left");
    psprite->play();
    psprite->setXspeed(-100);
    pdir =  D2DEDIR_LEFT;
}

void Player::impulseUp(){
    psprite->setAnimation("walk-up");
    psprite->play();
    psprite->setYspeed(-100);
    pdir = D2DEDIR_UP;
}

void Player::impulseRight(){
    psprite->setAnimation("walk-right");
    psprite->play();
    psprite->setXspeed(100);
    pdir = D2DEDIR_RIGHT;
}

void Player::impulseDown(){
    psprite->setAnimation("walk-down");
    psprite->play();
    psprite->setYspeed(100);
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
    inventory.getSelectedWeapon()->fire(ppos.x, ppos.y, pdir);
}

void Player::draw(cgf::Game* game){
    game->getScreen()->draw(*psprite);
}

const sf::Vector2f& Player::getPosition(){
    return psprite->getPosition();
}

Inventory * Player::getInventory(){
    return &(this->inventory);
}
