/***********************************************************************
 * Source File:
 *    Game: An instance of the space simulation
 * Author:
 *    Cayden Lords
 * Summary:
 *    This contains everything we need in order to run the simulation.
 ************************************************************************/
#pragma once
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
#include "Earth.h"
#include "projectile.h"
#include <cassert>
#include <vector>

 /**********************************************
  * GAME: CONSTRUCTOR
  * Builds the start of a game
  * INPUT
  * upperRight: The upperRight corner of the screen. Knowing this allows us to randomize the locations of stars or other objects. 
  *********************************************/
Game::Game(Position upperRight) {
   collidables.push_back(new Earth());
   collidables.push_back(new Chaser(Position(-57600000.0, 57600000.0), Angle(0), 10, Position(-2.0, 0.0), 0));
   collidables.push_back(new Sputnik(Position(-36515095.13, 21082000.0), Angle(0), 4, Position(2050.0, 2684.68), 4));
   collidables.push_back(new GPS(Position(0.0, 26560000.0), Angle(), 12, Position(-3880.0, 0.0), 2));
   collidables.push_back(new GPS(Position(23001634.72, 13280000.0), Angle(0), 12, Position(-1940.00, 3360.18), 2));
   collidables.push_back(new GPS(Position(23001634.72, -13280000.0), Angle(0), 12, Position(1940.00, 3360.18), 2));
   collidables.push_back(new GPS(Position(0.0, -26560000.0), Angle(0), 12, Position(3880.0, 0.0), 2));
   collidables.push_back(new GPS(Position(-23001634.72, -13280000.0), Angle(0), 12, Position(1940.00, -3360.18), 2));
   collidables.push_back(new GPS(Position(-23001634.72, 13280000.0), Angle(0), 12, Position(-1940.00, -3360.18), 2));
   collidables.push_back(new Hubble(Position(0.0, -42164000.0), Angle(0), 10, Position(3100.0, 0.0), 0));
   collidables.push_back(new Dragon(Position(0.0, 8000000.0), Angle(0), 7, Position(-7900.0, 0.0), 2));
   collidables.push_back(new Starlink(Position(0.0, -13020000.0), Angle(0), 6, Position(5800.0, 0.0), 2));
}


 /**********************************************
  * GAME: RUN PHYSICS 
  * Call each collidable to be moved, then check for collisions, then draw each item. 
  *********************************************/
void Game::runPhysics(bool left, bool right, bool down, bool space)
{
   moveInertia(left, right, down);
   checkCollisions();
   drawBodies(down);
   addProjectiles(space);
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
   for (size_t i = 0; i < collidables.size(); i++)
   {
      for (size_t j = i + 1; j < collidables.size(); j++)
      {
         if (hasCollided(collidables[i], collidables[j]))
         {
            std::vector<Collidable*> new1 = collidables[i]->collide();
            std::vector<Collidable*> new2 = collidables[j]->collide();


            
            // Remove the collided objects from the list, exclude the Earth
            if (collidables[j]->radius != 160)
            {
               delete collidables[j];
            }
            if (collidables[i]->radius != 160)
            {
               delete collidables[i];
            }
            if (collidables[j]->radius != 160)
            {
                collidables.erase(collidables.begin() + j);
            }
            if (collidables[i]->radius != 160)
            {
               collidables.erase(collidables.begin() + i);
            }
            

            collidables.insert(collidables.end(), new1.begin(), new1.end());
            collidables.insert(collidables.end(), new2.begin(), new2.end());

            // Adjust the indices
            if (i > 0) i--;
            break;
         }
      }
   }
}

/**********************************************
 * GAME: DRAW BODIES
 * Draw every heavenly body in Game. 
 *********************************************/
void Game::drawBodies(bool down)
{
   ogstream gout;
   for (int i = 0; i < collidables.size(); i++) 
   {
      collidables[i]->draw(down);
   }
}

/**********************************************
 * GAME: ADD PROJECTILES
 * Shoots a projectile 
 *********************************************/
void Game::addProjectiles(bool space)
{
   if (space) 
   {
      if (chaserAlive) 
      {
         collidables.push_back(new Projectile(rotate(collidables[1]->getPos(), 0.0, 19.0, collidables[1]->getAngle().getRadians()),
            collidables[1]->getAngle(), 1, rotate(collidables[1]->getSpeed(), 0.0, 0.08, collidables[1]->getAngle().getRadians()), 0));
      }
   }
}

/**********************************************
 * GAME: HAS COLLIDED
 * Detects collisions between objects
 *********************************************/
bool Game::hasCollided(Collidable* a, Collidable* b)
{
   double xPos = a->pos.getMetersX() - b->pos.getMetersX();
   double yPos = a->pos.getMetersY() - b->pos.getMetersY();
   double distance = std::sqrt(xPos * xPos + yPos * yPos);

   double aRadiusMeters = a->radius * 128000.0;
   double bRadiusMeters = b->radius * 128000.0;

   //return distance <= (a->radius + b->radius);

   return distance <= (aRadiusMeters + bRadiusMeters);
}
