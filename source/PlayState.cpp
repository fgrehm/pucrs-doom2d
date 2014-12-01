/*
 *  PlayState.cpp
 *  Normal "play" state
 *
 *  Created by Marcelo Cohen on 08/13.
 *  Copyright 2013 PUCRS. All rights reserved.
 *
 */

#include <iostream>
#include <cmath>
#include "Game.h"
#include "PlayState.h"
#include "MenuState.h"
#include "InputManager.h"

#include "ItemShells.h"
#include "ItemShotgun.h"
#include "ItemRocketLauncher.h"
#include "ItemRocket.h"

#include "Player.h"
#include "PlayerDriver.h"

#include "Imp.h"
#include "CyberDemon.h"
#include "PinkDemon.h"
#include "BaronOfHell.h"

PlayState PlayState::m_PlayState;

using namespace std;

void PlayState::init()
{

    im = cgf::InputManager::instance();

    im->addKeyInput("left", sf::Keyboard::Left);
    im->addKeyInput("right", sf::Keyboard::Right);
    im->addKeyInput("up", sf::Keyboard::Up);
    im->addKeyInput("down", sf::Keyboard::Down);
    im->addKeyInput("one", sf::Keyboard::Num1);
    im->addKeyInput("two", sf::Keyboard::Num2);
    im->addKeyInput("three", sf::Keyboard::Num3);
    im->addKeyInput("quit", sf::Keyboard::Escape);
    im->addKeyInput("zoomin", sf::Keyboard::Z);
    im->addKeyInput("zoomout", sf::Keyboard::X);
    im->addMouseInput("rightclick", sf::Mouse::Right);

    map = new tmx::MapLoader("data/maps");
    //map->Load("dungeon-tilesets2.tmx");
    map->Load("level1.tmx");

    projectiles = new Projectiles();
    player = new Player(projectiles);
    playerdriver = new PlayerDriver(*player, im);
    monsters = new Monsters(player);
    items = new Items(player->getInventory());

    firstTime = true;

    // BEGIN MANUALLY SET MAP ENTITIES
    monsters->spawnNew(new Imp(150, 90, 3));
    monsters->spawnNew(new PinkDemon(500, 360, 3));
    monsters->spawnNew(new PinkDemon(300, 310, 3));
    monsters->spawnNew(new PinkDemon(360, 240, 3));
    monsters->spawnNew(new PinkDemon(950, 650, 3));
    monsters->spawnNew(new BaronOfHell(1000, 270, 3));
    monsters->spawnNew(new BaronOfHell(1200, 380, 3));

    monsters->spawnNew(new Imp(500, 630, 3));
    monsters->spawnNew(new Imp(340, 630, 3));
    monsters->spawnNew(new Imp(480, 760, 3));
    monsters->spawnNew(new Imp(300, 775, 3));

    monsters->spawnNew(new CyberDemon(1250, 900, 3));

    items->spawnNew(new ItemShotgun(700, 420));
    items->spawnNew(new ItemShells(740, 440));
    items->spawnNew(new ItemShells(770, 480));
    items->spawnNew(new ItemShells(670, 430));

    items->spawnNew(new ItemRocketLauncher(700, 750));
    items->spawnNew(new ItemRocket(90, 850));
    items->spawnNew(new ItemRocket(120, 900));
    items->spawnNew(new ItemRocket(170, 850));
    // END MANUALLY SET MAP ENTITIES

	cout << "PlayState Init Successful" << endl;
}

void PlayState::cleanup()
{
	cout << "PlayState Clean Successful" << endl;
	delete map;
	delete playerdriver;
	delete projectiles;
	delete monsters;
	delete items;
}

void PlayState::pause()
{
	cout << "PlayState Paused" << endl;
}

void PlayState::resume()
{
	cout << "PlayState Resumed" << endl;
}

void PlayState::handleEvents(cgf::Game* game)
{
    sf::Event event;
    sf::View view = screen->getView();

    while (screen->pollEvent(event)){

        if(event.type == sf::Event::Closed){
            game->quit();
        }

        if(event.key.code == sf::Keyboard::S){
            game->toggleStats();
        }
        playerdriver->receiveInput(event);
    }

    if(im->testEvent("quit") || im->testEvent("rightclick"))
        game->quit();

    if(im->testEvent("zoomin"))
    {
        view.zoom(1.01);
        screen->setView(view);
    }
    else if(im->testEvent("zoomout"))
    {
        view.zoom(0.99);
        screen->setView(view);
    }

}

void PlayState::update(cgf::Game* game)
{
    if(firstTime) {
        // Background audio from http://www.looperman.com/loops/detail/77776
        music.openFromFile("data/audio/background-loop.wav");
        music.setVolume(30);
        music.setLoop(true);
        music.play();
        firstTime = false;
    }

    screen = game->getScreen();
    checkCollision(2, game, player->getSprite());
    centerMapOnPlayer();

    // check projectile collisions.
    bool repeat_dreaded_bubble_sort = true;
    while (repeat_dreaded_bubble_sort){
        repeat_dreaded_bubble_sort = false;

        for (int i=0; i<projectiles->projectiles.size(); ++i){

            cgf::Sprite *prjspr = projectiles->projectiles[i]->sprite;

            // check against the map
            if (checkCollision(2, game, prjspr)){
                projectiles->kill(i);
                repeat_dreaded_bubble_sort = true;
                break;
            }

            // check against monsters
            bool i_wanna_cry = false;
            for (int j=0; j<monsters->monsters.size(); ++j){

                if (!(monsters->monsters[j]->isAlive())){
                    continue;
                }

                cgf::Sprite *monspr = monsters->monsters[j]->sprite;

                if (prjspr->circleCollision(*monspr)){
                    projectiles->kill(i);
                    monsters->kill(j);
                    i_wanna_cry = true;
                    break;
                }
            }
            if (i_wanna_cry){
                repeat_dreaded_bubble_sort = true;
                break;
            }
        }
    }

    // check collisions between player and any items
    items->checkCollisionsWithPlayer(player);
}

bool PlayState::checkCollision(u_int8_t layer, cgf::Game* game, cgf::Sprite* obj)
{
    int i, x1, x2, y1, y2;
    bool bump = false;

    // Get the limits of the map
    sf::Vector2u mapsize = map->GetMapSize();
    // Get the width and height of a single tile
    sf::Vector2u tilesize = map->GetMapTileSize();

    mapsize.x /= tilesize.x;
    mapsize.y /= tilesize.y;
    mapsize.x--;
    mapsize.y--;

    // Get the height and width of the object (in this case, 100% of a tile)
    sf::Vector2u objsize = obj->getSize();
    objsize.x *= obj->getScale().x;
    objsize.y *= obj->getScale().y;

    float px = obj->getPosition().x;
    float py = obj->getPosition().y;

    double deltaTime = game->getUpdateInterval();

    sf::Vector2f offset(obj->getXspeed()/1000 * deltaTime, obj->getYspeed()/1000 * deltaTime);

    float vx = offset.x;
    float vy = offset.y;

    // Test the horizontal movement first
    i = objsize.y > tilesize.y ? tilesize.y : objsize.y;

    for (;;)
    {
        x1 = (px + vx) / tilesize.x;
        x2 = (px + vx + objsize.x - 1) / tilesize.x;

        y1 = (py) / tilesize.y;
        y2 = (py + i - 1) / tilesize.y;

        if (x1 >= 0 && x2 <= mapsize.x && y1 >= 0 && y2 < mapsize.y)
        {
            if (vx > 0)
            {
                // Trying to move right

                int upRight   = getCellFromMap(layer, x2*tilesize.x, y1*tilesize.y);
                int downRight = getCellFromMap(layer, x2*tilesize.x, y2*tilesize.y);
                if (upRight || downRight)
                {
                    // Place the player as close to the solid tile as possible
                    px = x2 * tilesize.x;
                    px -= objsize.x;// + 1;
                    vx = 0;
                    bump = true;
                }
            }

            else if (vx < 0)
            {
                // Trying to move left

                int upLeft   = getCellFromMap(layer, x1*tilesize.x, y1*tilesize.y);
                int downLeft = getCellFromMap(layer, x1*tilesize.x, y2*tilesize.y);
                if (upLeft || downLeft)
                {
                    // Place the player as close to the solid tile as possible
                    px = (x1+1) * tilesize.x;
                    vx = 0;
                    bump = true;
                }
            }
        }

        if (i == objsize.y) // Checked player height with all tiles ?
        {
            break;
        }

        i += tilesize.y; // done, check next tile upwards

        if (i > objsize.y)
        {
            i = objsize.y;
        }
    }

    // Now test the vertical movement

    i = objsize.x > tilesize.x ? tilesize.x : objsize.x;

    for (;;)
    {
        x1 = (px / tilesize.x);
        x2 = ((px + i-1) / tilesize.x);

        y1 = ((py + vy) / tilesize.y);
        y2 = ((py + vy + objsize.y-1) / tilesize.y);

        if (x1 >= 0 && x2 < mapsize.x && y1 >= 0 && y2 <= mapsize.y)
        {
            if (vy > 0)
            {
                // Trying to move down
                int downLeft  = getCellFromMap(layer, x1*tilesize.x, y2*tilesize.y);
                int downRight = getCellFromMap(layer, x2*tilesize.x, y2*tilesize.y);
                if (downLeft || downRight)
                {
                    // Place the player as close to the solid tile as possible
                    py = y2 * tilesize.y;
                    py -= objsize.y;
                    vy = 0;
                    bump = true;
                }
            }

            else if (vy < 0)
            {
                // Trying to move up

                int upLeft  = getCellFromMap(layer, x1*tilesize.x, y1*tilesize.y);
                int upRight = getCellFromMap(layer, x2*tilesize.x, y1*tilesize.y);
                if (upLeft || upRight)
                {
                    // Place the player as close to the solid tile as possible
                    py = (y1 + 1) * tilesize.y;
                    vy = 0;
                    bump = true;
                }
            }
        }

        if (i == objsize.x)
        {
            break;
        }

        i += tilesize.x; // done, check next tile to the right

        if (i > objsize.x)
        {
            i = objsize.x;
        }
    }

    // Now apply the movement and animation

    obj->setPosition(px+vx,py+vy);
    px = obj->getPosition().x;
    py = obj->getPosition().y;

    obj->update(deltaTime, false); // only update animation

    // Check collision with edges of map
    if (px < 0)
        obj->setPosition(px,py);
    else if (px + objsize.x >= mapsize.x * tilesize.x)
        obj->setPosition(mapsize.x*tilesize.x - objsize.x - 1,py);

    if(py < 0)
        obj->setPosition(px,0);
    else if(py + objsize.y >= mapsize.y * tilesize.y)
        obj->setPosition(px, mapsize.y*tilesize.y - objsize.y - 1);

    return bump;
}

sf::Uint16 PlayState::getCellFromMap(uint8_t layernum, float x, float y)
{
    auto layers = map->GetLayers();
    tmx::MapLayer& layer = layers[layernum];
    sf::Vector2u mapsize = map->GetMapSize();
    sf::Vector2u tilesize = map->GetMapTileSize();
    mapsize.x /= tilesize.x;
    mapsize.y /= tilesize.y;
    int col = floor(x / tilesize.x);
    int row = floor(y / tilesize.y);
    return layer.tiles[row*mapsize.x + col].gid;
}

void PlayState::centerMapOnPlayer()
{
    sf::View view = screen->getView();
    sf::Vector2u mapsize = map->GetMapSize();
    sf::Vector2f viewsize = view.getSize();
    viewsize.x /= 2;
    viewsize.y /= 2;
    sf::Vector2f pos = player->getPosition();

    float panX = viewsize.x; // minimum pan
    if(pos.x >= viewsize.x)
        panX = pos.x;

    if(panX >= mapsize.x - viewsize.x)
        panX = mapsize.x - viewsize.x;

    float panY = viewsize.y; // minimum pan
    if(pos.y >= viewsize.y)
        panY = pos.y;

    if(panY >= mapsize.y - viewsize.y)
        panY = mapsize.y - viewsize.y;

    view.setCenter(sf::Vector2f(panX,panY));
    screen->setView(view);
}

void PlayState::draw(cgf::Game* game)
{
    //sf::View view = screen->getView();

    screen->clear(sf::Color(0,0,0));

    map->Draw(*screen, 0);
    projectiles->draw(game);
    map->Draw(*screen, 1);
    monsters->draw(game);
    items->draw(game);
    player->draw(game);

    //screen->draw(text);
}
