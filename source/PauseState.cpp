/*
 *  PauseState.cpp
 *  Example "pause" state
 *
 *  Created by Marcelo Cohen on 04/11.
 *  Copyright 2011 PUCRS. All rights reserved.
 *
 */

#include <iostream>
#include <SDL.h>
#include "Graphics.h"
#include "CGame.h"
#include "CFont.h"
#include "PauseState.h"

PauseState PauseState::m_PauseState;

using namespace std;

void PauseState::init()
{
    pauseSprite = new CImage();
    pauseSprite->loadImage("data/img/paused.png");
    pauseSprite->setPosition(150,150);
    pauseFont = new CFont();
    pauseFont->loadFont("data/fonts/lucida12.png", 112, 208);
    cout << "PauseState Init Successful" << endl;
}

void PauseState::cleanup()
{
    delete pauseSprite;
	cout << "PauseState Clean Successful" << endl;
}

void PauseState::resume() {}

void PauseState::pause() {}

void PauseState::handleEvents(CGame* game)
{
	SDL_Event event;

	if (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_QUIT:
				game->quit();
				break;

            case SDL_KEYDOWN:
				switch(event.key.keysym.sym){
                    case SDLK_p:
                        game->popState();
                        break;
                    case SDLK_ESCAPE:
                        game->quit();
                        break;
                    default:
                        break;
				}
		}
	}
}

void PauseState::update(CGame* game)
{
}

void PauseState::draw(CGame* game)
{
    glClearColor(0,0,1,1); // blue
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    pauseSprite->setScale(1);
    pauseSprite->draw();
    glLoadIdentity();
    pauseFont->draw(250,300,"Press P to resume game");
    SDL_GL_SwapBuffers();
}

