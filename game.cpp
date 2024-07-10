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
#include "collidable.h"
#include "sputnik.h"
#include "chaser.h"
#include "GPS.h"
#include "hubble.h"
#include "dragon.h"
#include "starlink.h"
#include "fragment.h"
#include <cassert>
#include <vector>

 /**********************************************
  * GAME: CONSTRUCTOR
  * Builds the start of a game
  * INPUT
  * upperRight: The upperRight corner of the screen. Knowing this allows us to randomize the locations of stars or other objects. 
  *********************************************/
Game::Game(Position upperRight) {
   collidables.push_back(new Chaser(Position(-57600000.0, 57600000.0), Angle(0), 10, Position(-2.0, 0.0)));
   collidables.push_back(new Sputnik(Position(-36515095.13, 21082000.0), Angle(0), 4, Position(2050.0, 2684.68)));
   collidables.push_back(new GPS(Position(0.0, 26560000.0), Angle(), 12, Position(-3880.0, 0.0)));
   collidables.push_back(new GPS(Position(23001634.72, 13280000.0), Angle(0), 12, Position(-1940.00, 3360.18)));
   collidables.push_back(new GPS(Position(23001634.72, -13280000.0), Angle(0), 12, Position(1940.00, 3360.18)));
   collidables.push_back(new GPS(Position(0.0, -26560000.0), Angle(0), 12, Position(3880.0, 0.0)));
   collidables.push_back(new GPS(Position(-23001634.72, -13280000.0), Angle(0), 12, Position(1940.00, -3360.18)));
   collidables.push_back(new GPS(Position(-23001634.72, 13280000.0), Angle(0), 12, Position(-1940.00, -3360.18)));
   collidables.push_back(new Hubble(Position(0.0, -42164000.0), Angle(0), 10, Position(3100.0, 0.0)));
   collidables.push_back(new Dragon(Position(0.0, 8000000.0), Angle(0), 7, Position(-7900.0, 0.0)));
   collidables.push_back(new Starlink(Position(0.0, -13020000.0), Angle(0), 6, Position(5800.0, 0.0)));
}


 /**********************************************
  * GAME: RUN PHYSICS 
  * Call each collidable to be moved, then check for collisions, then draw each item. 
  *********************************************/
void Game::runPhysics(bool left, bool right, bool down)
{
   moveInertia(left, right, down);
   checkCollisions();
   drawBodies(down);
}

/**********************************************
 * GAME: MOVE INERTIA
 * Call each collidable to move
 *********************************************/
void Game::moveInertia(bool left, bool right, bool down)
{
   for (int i = 0; i < collidables.size(); i++) 
   {
      if (collidables[i]->move(left, right, down) == true) 
      {
         collidables.erase(std::next(collidables.begin(), i));
      }
   }
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
void Game::drawBodies(bool down)
{
   ogstream gout;
   gout.drawEarth(Position(0, 0), 0);
   for (int i = 0; i < collidables.size(); i++) 
   {
      collidables[i]->draw(down);
   }
}