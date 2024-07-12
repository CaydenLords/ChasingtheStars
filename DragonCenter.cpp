/***********************************************************************
 * Source File:
 *    Dragon Center: The Dragon Center class for the simulation
 * Author:
 *    Cayden Lords
 * Summary:
 *    This contains all of the functionality for the Center of the Dragon satellite
 ************************************************************************/

#include "position.h"
#include "satellite.h"
#include "DragonCenter.h"
#include "uiDraw.h"

 /************************************************************************
  * Draw
  * Allows the Sputnik object to be drawn
  *************************************************************************/
void DragonCenter::draw(bool down)
{
   ogstream gout;
   gout.drawCrewDragonCenter(pos, angle.getDegrees());
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
std::vector<Collidable*> DragonCenter::collide()
{
   std::vector<Collidable*> objects;
   return objects;
};