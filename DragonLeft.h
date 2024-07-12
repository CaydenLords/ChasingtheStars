#pragma once
/***********************************************************************
 * Header File:
 *    Dragon Left: Class which houses all the functionality of the Left of the Dragon satellite
 * Author:
 *    Cayden Lords
 * Summary:
 *    This contains everything the game needs to implement the Left side of the Dragon into the simulator
 ************************************************************************/

#include <iostream> 
#include "satellite.h"

class DragonLeft : public Satellite
{
public:

   // Constructors
   DragonLeft() : Satellite()
   {
      pos = Position(0.0, 0.0);
      angle = Angle(0);
      speed = Position(0.0, 0.0);
   }
   DragonLeft(Position location, Angle ang, int rad, Position move, int pieces) : Satellite(location, ang, rad, move, pieces)
   {
      pos = location;
      angle = ang;
      radius = rad;
      speed = move;
      fragments = pieces;
   }

   void draw(bool down);
   //void move();
   void collide();

};
