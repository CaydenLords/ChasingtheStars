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
#include "GPSCenter.h"
#include "GPSLeft.h"
#include "GPSRight.h"
#include "fragment.h"
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
std::vector<Collidable*> GPS::collide()
{
   std::vector<Collidable*> objects;

   GPSCenter* center = new GPSCenter(pos, angle, 7, speed, 0);
   GPSLeft* left = new GPSLeft(pos, angle, 8, speed, 0);
   GPSRight* right = new GPSRight(pos, angle, 8, speed, 0);

   objects.push_back(center);
   objects.push_back(left);
   objects.push_back(right);

   std::vector<Collidable*> newFragments = makeFragments(objects, fragments);

   newFragments.insert(objects.end(), newFragments.begin(), newFragments.end());

   return newFragments;
};