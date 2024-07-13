/***********************************************************************
 * Source File:
 *    Hubble Right: The Hubble Right class for the simulation
 * Author:
 *    Cayden Lords
 * Summary:
 *    This contains all of the functionality for the right side of the Hubble satellite
 ************************************************************************/

#include "position.h"
#include "satellite.h"
#include "HubbleRight.h"
#include "uiDraw.h"

 /************************************************************************
  * Draw
  * Allows the Sputnik object to be drawn
  *************************************************************************/
void HubbleRight::draw(bool down)
{
   ogstream gout;
   gout.drawHubbleRight(pos, angle.getDegrees());
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
std::vector<Collidable*> HubbleRight::collide()
{
   std::vector<Collidable*> objects;

   std::vector<Collidable*> newFragments = makeFragments(objects, fragments);

   return newFragments;
};