/***********************************************************************
 * Source File:
 *    Hubble Left: The Hubble Left class for the simulation
 * Author:
 *    Cayden Lords
 * Summary:
 *    This contains all of the functionality for the Left side of the Hubble satellite
 ************************************************************************/

#include "position.h"
#include "satellite.h"
#include "HubbleLeft.h"
#include "uiDraw.h"

 /************************************************************************
  * Draw
  * Allows the Sputnik object to be drawn
  *************************************************************************/
void HubbleLeft::draw(bool down)
{
   ogstream gout;
   gout.drawHubbleLeft(pos, angle.getDegrees());
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
std::vector<Collidable*> HubbleLeft::collide()
{
   std::vector<Collidable*> objects;

   std::vector<Collidable*> newFragments = makeFragments(fragments);

   objects.insert(objects.end(), newFragments.begin(), newFragments.end());

   return objects;
};