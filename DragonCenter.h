#pragma once
/***********************************************************************
 * Header File:
 *    Dragon Center: Class which houses all the functionality of the Center of the Dragon satellite
 * Author:
 *    Cayden Lords
 * Summary:
 *    This contains everything the game needs to implement the Center side of the Dragon into the simulator
 ************************************************************************/

#include <iostream> 
#include "satellite.h"

class DragonCenter : public Satellite
{
public:

   // Constructors
   DragonCenter() : Satellite()
   {
      pos = Position(0.0, 0.0);
      angle = Angle(0);
      speed = Position(0.0, 0.0);
   }
   DragonCenter(Position location, Angle ang, int rad, Position move, int pieces) : Satellite(location, ang, rad, move, pieces)
   {
      pos = location;
      angle = ang;
      radius = rad;
      speed = move;
      fragments = pieces;
   }

   void draw(bool down);
   //void move();
   std::vector<Collidable> collide() override;

};

