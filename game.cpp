/***********************************************************************
 * Source File:
 *    Game: An instance of the space simulation
 * Author:
 *    Cayden Lords
 * Summary:
 *    This contains everything we need in order to run the simulation.
 ************************************************************************/

#include "game.h"
#include "uiDraw.h"     // for RANDOM and DRAW*
#include <cassert>

 /**********************************************
  * GAME: CONSTRUCTOR
  * Builds the start of a game
  * INPUT
  * upperRight: The upperRight corner of the screen. Knowing this allows us to randomize the locations of stars or other objects. 
  *********************************************/
Game::Game(Position upperRight) {

}


 /**********************************************
  * GAME: RUN PHYSICS 
  * Call each collidable to be moved, then check for collisions, then draw each item. 
  *********************************************/
void Game::runPhysics()
{
   moveInertia();
   checkCollisions();
   drawBodies();
}

/**********************************************
 * GAME: MOVE INTERTIA
 * Call each collidable to move
 *********************************************/
void Game::moveInertia()
{

}

/**********************************************
 * GAME: CHECK COLLISIONS
 * See if any collidables are within colliding distance. If they are, trigger their collision events
 *********************************************/
void Game::checkCollisions()
{

}

/**********************************************
 * GAME: DRAW BODIES
 * Draw every heavenly body in Game. 
 *********************************************/
void Game::drawBodies()
{
   ogstream gout;
   gout.drawEarth(Position(0,0),0);
}