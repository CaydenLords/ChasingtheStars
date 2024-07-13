/***********************************************************************
 * Source File:
 *    Starlink Body: The Starlink Body class for the simulation
 * Author:
 *    Cayden Lords
 * Summary:
 *    This contains all of the functionality for the Body of the Starlink satellite
 ************************************************************************/

#include "position.h"
#include "satellite.h"
#include "starlinkBody.h"
#include "uiDraw.h"

 /************************************************************************
  * Draw
  * Allows the Starlink Body object to be drawn
  *************************************************************************/
void StarlinkBody::draw(bool down)
{
   ogstream gout;
   gout.drawStarlinkBody(pos, angle.getDegrees());
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
std::vector<Collidable*> StarlinkBody::collide()
{
   std::vector<Collidable*> objects;

   std::vector<Collidable*> newFragments = makeFragments(fragments);

   objects.insert(objects.end(), newFragments.begin(), newFragments.end());

   return objects;
};