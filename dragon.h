#pragma once
/***********************************************************************
 * Header File:
 *    Hubble: Class which houses all the functionality of the Dragon satellite
 * Author:
 *    Ryan Donaldson
 * Summary:
 *    This contains everything the game needs to implement Dragon into the simulator
 ************************************************************************/

#include <iostream> 
#include "satellite.h"

class Dragon : public Satellite
{
public:

   // Constructors
   Dragon() : Satellite()
   {
      pos = Position(0.0, 0.0);
      angle = Angle(0);
      speed = Position(-7900.0, 0.0);
   }
   Dragon(Position location, Angle ang, int rad, Position move, int pieces) : Satellite(location, ang, rad, move, pieces)
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