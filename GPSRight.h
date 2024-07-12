#pragma once
#pragma once
/***********************************************************************
 * Header File:
 *    GPS Right: Class which houses all the functionality of the Right of the GPS satellite
 * Author:
 *    Cayden Lords
 * Summary:
 *    This contains everything the game needs to implement the right side of the GPS into the simulator
 ************************************************************************/

#include <iostream> 
#include "satellite.h"

class GPSRight: public Satellite
{
public:

   // Constructors
   GPSRight() : Satellite()
   {
      pos = Position(0.0, 0.0);
      angle = Angle(0);
      speed = Position(0.0, 0.0);
   }
   GPSRight(Position location, Angle ang, int rad, Position move, int pieces) : Satellite(location, ang, rad, move, pieces)
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