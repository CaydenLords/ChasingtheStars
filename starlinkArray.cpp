/***********************************************************************
 * Source File:
 *    Starlink Array: The Starlink Array class for the simulation
 * Author:
 *    Cayden Lords
 * Summary:
 *    This contains all of the functionality for the Array of the Starlink satellite
 ************************************************************************/

#include "position.h"
#include "satellite.h"
#include "starlinkArray.h"
#include "uiDraw.h"

 /************************************************************************
  * Draw
  * Allows the Starlink Array object to be drawn
  *************************************************************************/
void StarlinkArray::draw(bool down)
{
   ogstream gout;
   gout.drawStarlinkArray(pos, angle.getDegrees());
};

/************************************************************************
 * Move
 * Moves the Hubble object
 *************************************************************************/
 //void Sputnik::move()
 //{
 //   Inertia::move();
 //};

 /************************************************************************
  * Collide
  * Checks if the Hubble object has collided with another object
  *************************************************************************/
std::vector<Collidable> StarlinkArray::collide() 
{
   std::vector<Collidable> objects;
   return objects;
};