/***********************************************************************
 * Source File:
 *    GPS: The GPS class for the simulation
 * Author:
 *    Ryan Donaldson
 * Summary:
 *    This contains all of the functionality for the GPS satellite
 ************************************************************************/

#include "position.h"
#include "satellite.h"
#include "GPS.h"
#include "uiDraw.h"

 /************************************************************************
  * Draw
  * Allows the Sputnik object to be drawn
  *************************************************************************/
void GPS::draw(bool down)
{
   ogstream gout;
   gout.drawGPS(pos, angle.getDegrees());
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
std::vector<Collidable> GPS::collide() 
{
   std::vector<Collidable> objects;
   return objects;
};