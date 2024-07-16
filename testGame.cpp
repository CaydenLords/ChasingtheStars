/***********************************************************************
 * Source File:
 *    TEST GAME
 * Author:
 *    Ryan Donaldson
 * Summary:
 *    The unit tests for Game
 ************************************************************************/

#include "testGame.h"
#include "game.h"
#include "inertia.h"
#include "position.h"
#include "collidable.h"
#include <cassert>

 /*************************************
   * TEST HAS COLLIDED TRUE : Game
   * Input: 0, 0
   * Output: 0, 0
   **************************************/
void TestGame::test_hasCollidedTrue()
{
   // setup
   Position ptUpperRight;
   ptUpperRight.setZoom(128000.0 /* 128km equals 1 pixel */);
   ptUpperRight.setPixelsX(1000.0);
   ptUpperRight.setPixelsY(1000.0);
   Game game(ptUpperRight);
   std::vector<Collidable*> objects;
   objects.push_back(new Collidable(Position(100, 100), 10));
   objects.push_back(new Collidable(Position(100, 100), 10));

   Collidable* sat1 = objects.at(0);
   Collidable* sat2 = objects.at(1);

   // exercise
   bool collided = game.hasCollided(sat1, sat2);
   // verify
   assertUnit(collided == true);
   // teardown
}

/*************************************
  * TEST HAS COLLIDED FALSE : Game
  * Input: 0, 0
  * Output: 0, 0
  **************************************/
void TestGame::test_hasCollidedFalse()
{
   // setup
   Position ptUpperRight;
   ptUpperRight.setZoom(128000.0 /* 128km equals 1 pixel */);
   ptUpperRight.setPixelsX(1000.0);
   ptUpperRight.setPixelsY(1000.0);
   Game game(ptUpperRight);
   std::vector<Collidable*> objects;
   objects.push_back(new Collidable(Position(10000000, 1000000), 5));
   objects.push_back(new Collidable(Position(-1000000000, -1000000000), 10));

   Collidable* sat1 = objects.at(0);
   Collidable* sat2 = objects.at(1);

   // exercise
   bool collided = game.hasCollided(sat1, sat2);

   // verify
   assertUnit(collided == false);
   // teardown
}