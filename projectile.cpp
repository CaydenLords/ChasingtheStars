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
   gout.drawProjectile(pos);
};

/************************************************************************
 * Collide
 * Checks if the Fragment object has collided with another object
 *************************************************************************/
std::vector<Collidable*> Projectile::collide()
{
   std::vector<Collidable*> objects;
   return objects;
};