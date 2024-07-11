#pragma once
/***********************************************************************
 * Header File:
 *    Projectile: class that houses all of the functionality of a projectile
 * Author:
 *    Cayden Lords
 * Summary:
 *    This contains everything the game needs to implement projectiles into the simulator
 ************************************************************************/

#include <iostream> 
#include "fragile.h"

class Projectile : public Fragile
{
public:

   // Constructors
   Projectile() : Fragile()
   {
      pos = Position(0.0, 0.0);
      angle = Angle(0);
      speed = Position(0.0, 0.0);
   }
   Projectile(Position location, Angle ang, int rad, Position move) : Fragile(location, ang, rad, move)
   {
      pos = location;
      angle = ang;
      radius = rad;
      speed = move;
      framesLeft = 700000;
   }

   void draw(bool down);
   void collide();
};
