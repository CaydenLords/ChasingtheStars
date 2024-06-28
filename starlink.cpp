/***********************************************************************
 * Source File:
 *    Starlink: The Starlink class for the simulation
 * Author:
 *    Ryan Donaldson
 * Summary:
 *    This contains all of the functionality for the Starlink satellite
 ************************************************************************/

#include "position.h"
#include "satellite.h"
#include "starlink.h"
#include "uiDraw.h"

 /************************************************************************
  * Draw
  * Allows the Starlink object to be drawn
  *************************************************************************/
void Starlink::draw(bool down)
{
   ogstream gout;
   gout.drawStarlink(pos, 0);
};

/************************************************************************
 * Move
 * Moves the Starlink object
 *************************************************************************/
 //void Starlink::move()
 //{
 //   Inertia::move();
 //};

 /************************************************************************
  * Collide
  * Checks if the Starlink object has collided with another object
  *************************************************************************/
void Starlink::collide() {};