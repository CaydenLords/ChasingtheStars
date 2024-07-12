/***********************************************************************
 * Source File:
 *    Fragment: class that houses all of the functionality of a satellite fragment
 * Author:
 *    Cayden Lords
 * Summary:
 *    This contains all of the functionality for a satellite fragment
 ************************************************************************/

#include "position.h"
#include "fragile.h"
#include "fragment.h"
#include "uiDraw.h"

 /************************************************************************
  * Draw
  * Allows the Fragment object to be drawn
  *************************************************************************/
void Fragment::draw(bool down)
{
   ogstream gout;
   gout.drawFragment(pos, angle.getDegrees());
};

 /************************************************************************
  * Collide
  * Checks if the Fragment object has collided with another object
  *************************************************************************/
std::vector<Collidable*> Fragment::collide()
{
   std::vector<Collidable*> objects;
   return objects;
};