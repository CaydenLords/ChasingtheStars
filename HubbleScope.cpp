/***********************************************************************
 * Source File:
 *    Hubble Telescope: The Hubble Telescope class for the simulation
 * Author:
 *    Cayden Lords
 * Summary:
 *    This contains all of the functionality for the Telescope of the Hubble satellite
 ************************************************************************/

#include "position.h"
#include "satellite.h"
#include "HubbleScope.h"
#include "uiDraw.h"

 /************************************************************************
  * Draw
  * Allows the Sputnik object to be drawn
  *************************************************************************/
void HubbleScope::draw(bool down)
{
   ogstream gout;
   gout.drawHubbleTelescope(pos, angle.getDegrees());
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
std::vector<Collidable*> HubbleScope::collide()
{
   std::vector<Collidable*> objects;

   std::vector<Collidable*> newFragments = makeFragments(objects, fragments);

   return newFragments;
};