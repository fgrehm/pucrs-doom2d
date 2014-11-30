
#include "PlayerDriver.h"

PlayerDriver::PlayerDriver(const Player &p, cgf::InputManager* _im):theplayer(p), im(_im){
}

PlayerDriver::~PlayerDriver(){
}

// precondition: this is only called when there is a key pressed
void PlayerDriver::receiveInput(const sf::Event &evt){

    if (evt.type ==sf::Event::KeyPressed){

        if (evt.key.code == sf::Keyboard::LControl){
            theplayer.impulseShoot();
        }

        if(im->testEvent("left")) {
            theplayer.impulseLeft();
        }

        if(im->testEvent("right")) {
            theplayer.impulseRight();
        }

        if(im->testEvent("up")) {
            theplayer.impulseUp();
        }

        if(im->testEvent("down")) {
            theplayer.impulseDown();
        }

        if (im->testEvent("one")){
            theplayer.impulseSelectPistol();
        }

        if (im->testEvent("two")){
            theplayer.impulseSelectShotgun();
        }

        if (im->testEvent("three")){
            theplayer.impulseSelectRocketLauncher();
        }

    } else if (evt.type == sf::Event::KeyReleased){
        if (evt.key.code == sf::Keyboard::Left || evt.key.code == sf::Keyboard::Right || evt.key.code == sf::Keyboard::Up || evt.key.code == sf::Keyboard::Down) {
            theplayer.impulseHalt();
        }
    }

}

