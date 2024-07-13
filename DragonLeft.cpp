/***********************************************************************
 * Source File:
 *    Dragon Left: The Dragon Left class for the simulation
 * Author:
 *    Cayden Lords
 * Summary:
 *    This contains all of the functionality for the Left side of the Dragon satellite
 ************************************************************************/

#include "position.h"
#include "satellite.h"
#include "DragonLeft.h"
#include "uiDraw.h"

 /************************************************************************
  * Draw
  * Allows the Sputnik object to be drawn
  *************************************************************************/
void DragonLeft::draw(bool down)
{
   ogstream gout;
   gout.drawCrewDragonLeft(pos, angle.getDegrees());
};

/************************************************************************
 * Move
 * Moves the Dragon object
 *************************************************************************/
 //void Sputnik::move()
 //{
 //   Inertia::move();
 //};

 /************************************************************************
  * Collide
  * Checks if the Dragon object has collided with another object
  *************************************************************************/
std::vector<Collidable*> DragonLeft::collide()
{
   std::vector<Collidable*> objects;

   for (int i = 0; i < fragments; i++)
   {
      Fragment* piece = new Fragment(pos, angle, 2, speed, 0);
      objects.push_back(piece);
   }

   return objects;
};