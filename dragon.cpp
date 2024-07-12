/***********************************************************************
 * Source File:
 *    Dragon: The Dragon class for the simulation
 * Author:
 *    Ryan Donaldson
 * Summary:
 *    This contains all of the functionality for the Dragon satellite
 ************************************************************************/

#include "position.h"
#include "satellite.h"
#include "dragon.h"
#include "uiDraw.h"

 /************************************************************************
  * Draw
  * Allows the Dragon object to be drawn
  *************************************************************************/
void Dragon::draw(bool down)
{
   ogstream gout;
   gout.drawCrewDragon(pos, angle.getDegrees());
};

/************************************************************************
 * Move
 * Moves the Dragon object
 *************************************************************************/
 //void Dragon::move()
 //{
 //   Inertia::move();
 //};

 /************************************************************************
  * Collide
  * Checks if the Dragon object has collided with another object
  *************************************************************************/
std::vector<Collidable*> Dragon::collide()
{
   std::vector<Collidable*> objects;
   return objects;
};