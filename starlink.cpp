/***********************************************************************
 * Source File:
 *    Starlink: The Starlink class for the simulation
 * Author:
 *    Ryan Donaldson
 * Summary:
 *    This contains all of the functionality for the Starlink satellite
 ************************************************************************/

#include "position.h"
#include "satellite.h"
#include "starlink.h"
#include "starlinkArray.h"
#include "starlinkBody.h"
#include "uiDraw.h"

 /************************************************************************
  * Draw
  * Allows the Starlink object to be drawn
  *************************************************************************/
void Starlink::draw(bool down)
{
   ogstream gout;
   gout.drawStarlink(pos, angle.getDegrees());
};

/************************************************************************
 * Move
 * Moves the Starlink object
 *************************************************************************/
 //void Starlink::move()
 //{
 //   Inertia::move();
 //};

 /************************************************************************
  * Collide
  * Checks if the Starlink object has collided with another object
  *************************************************************************/
std::vector<Collidable*> Starlink::collide()
{
   std::vector<Collidable*> objects;

   for (int i = 0; i < fragments; i++)
   {
      Fragment* piece = new Fragment(pos, angle, 2, speed, 0);
      objects.push_back(piece);
   }

   StarlinkArray* array = new StarlinkArray(pos, angle, 4, speed, 3);
   StarlinkBody* body = new StarlinkBody(pos, angle, 2, speed, 3);

   objects.push_back(array);
   objects.push_back(body);

   return objects;
};