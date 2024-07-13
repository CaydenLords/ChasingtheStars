/***********************************************************************
 * Source File:
 *    GPS Left: The GPS Left class for the simulation
 * Author:
 *    Cayden Lords
 * Summary:
 *    This contains all of the functionality for the left side of the GPS satellite
 ************************************************************************/

#include "position.h"
#include "satellite.h"
#include "GPSLeft.h"
#include "uiDraw.h"

 /************************************************************************
  * Draw
  * Allows the Sputnik object to be drawn
  *************************************************************************/
void GPSLeft::draw(bool down)
{
   ogstream gout;
   gout.drawGPSLeft(pos, angle.getDegrees());
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
std::vector<Collidable*> GPSLeft::collide()
{
   std::vector<Collidable*> objects;

   std::vector<Collidable*> newFragments = makeFragments(objects, fragments);

   return newFragments;
}