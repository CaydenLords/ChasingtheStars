/***********************************************************************
 * Source File:
 *    Hubble Computer: The Hubble Computer class for the simulation
 * Author:
 *    Cayden Lords
 * Summary:
 *    This contains all of the functionality for the Computer of the Hubble satellite
 ************************************************************************/

#include "position.h"
#include "satellite.h"
#include "HubbleComputer.h"
#include "uiDraw.h"

 /************************************************************************
  * Draw
  * Allows the Sputnik object to be drawn
  *************************************************************************/
void HubbleComputer::draw(bool down)
{
   ogstream gout;
   gout.drawHubbleComputer(pos, angle.getDegrees());
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
std::vector<Collidable*> HubbleComputer::collide()
{
   std::vector<Collidable*> objects;
   return objects;
};