#pragma once
/***********************************************************************
 * Header File:
 *    Dragon Right: Class which houses all the functionality of the Right of the Dragon satellite
 * Author:
 *    Cayden Lords
 * Summary:
 *    This contains everything the game needs to implement the Right side of the Dragon into the simulator
 ************************************************************************/

#include <iostream> 
#include "satellite.h"

class DragonRight : public Satellite
{
public:

   // Constructors
   DragonRight() : Satellite()
   {
      pos = Position(0.0, 0.0);
      angle = Angle(0);
      speed = Position(0.0, 0.0);
   }
   DragonRight(Position location, Angle ang, int rad, Position move) : Satellite(location, ang, rad, move)
   {
      pos = location;
      angle = ang;
      radius = rad;
      speed = move;
   }

   void draw(bool down);
   //void move();
   void collide();

};

