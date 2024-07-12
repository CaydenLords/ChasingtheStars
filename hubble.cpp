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
std::vector<Collidable> Hubble::collide() 
{
   std::vector<Collidable> objects;
   return objects;
};