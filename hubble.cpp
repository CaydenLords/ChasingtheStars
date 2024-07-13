/***********************************************************************
 * Source File:
 *    Hubble: The Hubble class for the simulation
 * Author:
 *    Ryan Donaldson
 * Summary:
 *    This contains all of the functionality for the Hubble satellite
 ************************************************************************/

#include "position.h"
#include "satellite.h"
#include "hubble.h"
#include "HubbleComputer.h"
#include "HubbleLeft.h"
#include "HubbleRight.h"
#include "HubbleScope.h"
#include "uiDraw.h"

 /************************************************************************
  * Draw
  * Allows the Hubble object to be drawn
  *************************************************************************/
void Hubble::draw(bool down)
{
   ogstream gout;
   gout.drawHubble(pos, angle.getDegrees());
};

/************************************************************************
 * Move
 * Moves the Hubble object
 *************************************************************************/
 //void Hubble::move()
 //{
 //   Inertia::move();
 //};

 /************************************************************************
  * Collide
  * Checks if the Hubble object has collided with another object
  *************************************************************************/
std::vector<Collidable*> Hubble::collide()
{
   std::vector<Collidable*> objects;

   HubbleComputer* computer = new HubbleComputer(pos, angle, 7, speed, 2);
   HubbleLeft* left = new HubbleLeft(pos, angle, 8, speed, 2);
   HubbleRight* right = new HubbleRight(pos, angle, 8, speed, 2);
   HubbleScope* scope = new HubbleScope(pos, angle, 10, speed, 3);

   objects.push_back(computer);
   objects.push_back(left);
   objects.push_back(right);
   objects.push_back(scope);

   std::vector<Collidable*> newFragments = makeFragments(objects, fragments);

   return newFragments;
};