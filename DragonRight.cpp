/***********************************************************************
 * Source File:
 *    Dragon Right: The Dragon Right class for the simulation
 * Author:
 *    Cayden Lords
 * Summary:
 *    This contains all of the functionality for the Right of the Dragon satellite
 ************************************************************************/

#include "position.h"
#include "satellite.h"
#include "DragonRight.h"
#include "uiDraw.h"

 /************************************************************************
  * Draw
  * Allows the Dragon Right object to be drawn
  *************************************************************************/
void DragonRight::draw(bool down)
{
   ogstream gout;
   gout.drawCrewDragonRight(pos, angle.getDegrees());
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
void DragonRight::collide() {};