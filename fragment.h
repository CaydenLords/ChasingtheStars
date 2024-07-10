#pragma once
/***********************************************************************
 * Header File:
 *    Fragment: class that houses all of the functionality of a satellite fragment
 * Author:
 *    Cayden Lords
 * Summary:
 *    This contains everything the game needs to implement satellite fragments into the simulator
 ************************************************************************/

#include <iostream> 
#include "fragile.h"

class Fragment : public Fragile
{
public:

   // Constructors
   Fragment() : Fragile()
   {
      pos = Position(0.0, 0.0);
      angle = Angle(0);
      speed = Position(0.0, 0.0);
   }
   Fragment(Position location, Angle ang, int rad, Position move) : Fragile(location, ang, rad, move)
   {
      pos = location;
      angle = ang;
      radius = rad;
      speed = move;
      framesLeft = random(50, 100);
   }

   void draw(bool down);
   void collide();
};