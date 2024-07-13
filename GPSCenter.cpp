/***********************************************************************
 * Source File:
 *    GPS Center: The GPS Center class for the simulation
 * Author:
 *    Cayden Lords
 * Summary:
 *    This contains all of the functionality for the center of the GPS satellite
 ************************************************************************/

#include "position.h"
#include "satellite.h"
#include "GPSCenter.h"
#include "uiDraw.h"

 /************************************************************************
  * Draw
  * Allows the Sputnik object to be drawn
  *************************************************************************/
void GPSCenter::draw(bool down)
{
   ogstream gout;
   gout.drawGPSCenter(pos, angle.getDegrees());
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
std::vector<Collidable*> GPSCenter::collide()
{
   std::vector<Collidable*> objects;

   std::vector<Collidable*> newFragments = makeFragments(objects, fragments);

   return newFragments;
};