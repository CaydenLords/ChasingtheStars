#pragma once
/***********************************************************************
 * Header File:
 *    Starlink Body: Class which houses all the functionality of the Body of the Starlink satellite
 * Author:
 *    Cayden Lords
 * Summary:
 *    This contains everything the game needs to implement the Starlink Body into the simulator
 ************************************************************************/

#include <iostream> 
#include "satellite.h"

class StarlinkBody : public Satellite
{
public:

   // Constructors
   StarlinkBody() : Satellite()
   {
      pos = Position(0.0, 0.0);
      angle = Angle(0);
      speed = Position(0.0, 0.0);
   }
   StarlinkBody(Position location, Angle ang, int rad, Position move, int pieces) : Satellite(location, ang, rad, move, pieces)
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
