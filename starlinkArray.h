#pragma once
/***********************************************************************
 * Header File:
 *    Starlink Array: Class which houses all the functionality of the Array of the Starlink satellite
 * Author:
 *    Cayden Lords
 * Summary:
 *    This contains everything the game needs to implement the Starlink Array into the simulator
 ************************************************************************/

#include <iostream> 
#include "satellite.h"

class StarlinkArray : public Satellite
{
public:

   // Constructors
   StarlinkArray() : Satellite()
   {
      pos = Position(0.0, 0.0);
      angle = Angle(0);
      speed = Position(0.0, 0.0);
   }
   StarlinkArray(Position location, Angle ang, int rad, Position move, int pieces) : Satellite(location, ang, rad, move, pieces)
   {
      pos = location;
      angle = ang;
      radius = rad;
      speed = move;
      fragments = pieces;
   }

   void draw(bool down);
   //void move();
   std::vector<Collidable*> collide() override;

};