#pragma once
/***********************************************************************
 * Header File:
 *    Starlink: Class which houses all the functionality of the Starlink satellite
 * Author:
 *    Ryan Donaldson
 * Summary:
 *    This contains everything the game needs to implement Starlink into the simulator
 ************************************************************************/

#include <iostream> 
#include "satellite.h"

class Starlink : public Satellite
{
public:

   // Constructors
   Starlink() : Satellite()
   {
      pos = Position(0.0, -13020000.0);
      angle = Angle(0);
      speed = Position(5800.0, 0.0);
   }
   Starlink(Position location, Angle ang, int rad, Position move, int pieces) : Satellite(location, ang, rad, move, pieces)
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