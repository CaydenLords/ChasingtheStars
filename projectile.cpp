/***********************************************************************
 * Source File:
 *    Fragment: class that houses all of the functionality of a projectile
 * Author:
 *    Cayden Lords
 * Summary:
 *    This contains all of the functionality for a projectile
 ************************************************************************/

#include "position.h"
#include "fragile.h"
#include "projectile.h"
#include "uiDraw.h"

 /************************************************************************
  * Draw
  * Allows the Fragment object to be drawn
  *************************************************************************/
void Projectile::draw(bool down)
{
   ogstream gout;
   gout.drawFragment(pos, angle.getDegrees());
};

/************************************************************************
 * Collide
 * Checks if the Fragment object has collided with another object
 *************************************************************************/
void Projectile::collide() {};