/***********************************************************************
 * Source File:
 *    GPS Right: The GPS Right class for the simulation
 * Author:
 *    Cayden Lords
 * Summary:
 *    This contains all of the functionality for the right side of the GPS satellite
 ************************************************************************/

#include "position.h"
#include "satellite.h"
#include "GPSRight.h"
#include "uiDraw.h"

 /************************************************************************
  * Draw
  * Allows the Sputnik object to be drawn
  *************************************************************************/
void GPSRight::draw(bool down)
{
   ogstream gout;
   gout.drawGPSRight(pos, angle.getDegrees());
};

/************************************************************************
 * Move
 * Moves the GPS object
 *************************************************************************/
 //void Sputnik::move()
 //{
 //   Inertia::move();
 //};

 /************************************************************************
  * Collide
  * Checks if the GPS object has collided with another object
  *************************************************************************/
std::vector<Collidable*> GPSRight::collide()
{
   std::vector<Collidable*> objects;
   return objects;
};