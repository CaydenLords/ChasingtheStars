#pragma once
#pragma once
/***********************************************************************
 * Header File:
 *    GPS Left: Class which houses all the functionality of the Left of the GPS satellite
 * Author:
 *    Cayden Lords
 * Summary:
 *    This contains everything the game needs to implement the left side of the GPS into the simulator
 ************************************************************************/

#include <iostream> 
#include "satellite.h"

class GPSLeft : public Satellite
{
public:

   // Constructors
   GPSLeft() : Satellite()
   {
      pos = Position(0.0, 0.0);
      angle = Angle(0);
      speed = Position(0.0, 0.0);
   }
   GPSLeft(Position location, Angle ang, int rad, Position move) : Satellite(location, ang, rad, move)
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