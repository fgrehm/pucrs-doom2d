/*
 *  PlayState.h
 *  Normal "play" state
 *
 *  Created by Marcelo Cohen on 04/11.
 *  Copyright 2011 PUCRS. All rights reserved.
 *
 */

#ifndef PLAY_STATE_H_
#define PLAY_STATE_H_

#include "GameState.h"
#include "Sprite.h"
#include "InputManager.h"
#include <MapLoader.h>

class PlayState : public cgf::GameState
{
    public:

    void init();
    void cleanup();

    void pause();
    void resume();

    void handleEvents(cgf::Game* game);
    void update(cgf::Game* game);
    void draw(cgf::Game* game);

    // Implement Singleton Pattern
    static PlayState* instance()
    {
        return &m_PlayState;
    }

    protected:

    PlayState() {}

    private:

    static PlayState m_PlayState;

    // Get a cell GID from the map (x and y are view coords)
    sf::Uint16 getCellFromMap(u_int8_t layernum, float x, float y);

    // Centers the camera on the player position (if player is too close to the borders, stop)
    void centerMapOnPlayer();

    bool checkCollision(u_int8_t layer, cgf::Game* game, cgf::Sprite* obj);

    int x, y;
    int dirx, diry;
    cgf::Sprite player;
    sf::RenderWindow* screen;
    cgf::InputManager* im;
    tmx::MapLoader* map;
    sf::Font font;
    sf::Text text;
};

#endif
