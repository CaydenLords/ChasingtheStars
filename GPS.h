#pragma once
/***********************************************************************
 * Header File:
 *    GPS: Class which houses all the functionality of the GPS satellite
 * Author:
 *    Ryan Donaldson
 * Summary:
 *    This contains everything the game needs to implement GPS into the simulator
 ************************************************************************/

#include <iostream> 
#include "satellite.h"

class GPS : public Satellite
{
public:

   // Constructors
   GPS() : Satellite()
   {
      pos = Position(0.0, 0.0);
      angle = Angle(0);
      speed = Position(0.0, 0.0);
   }
   GPS(Position location, Angle ang, int rad, Position move) : Satellite(location, ang, rad, move)
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