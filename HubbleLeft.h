#pragma once
/***********************************************************************
 * Header File:
 *    Hubble Left: Class which houses all the functionality of the Left of the Hubble satellite
 * Author:
 *    Cayden Lords
 * Summary:
 *    This contains everything the game needs to implement the Left side of the Hubble into the simulator
 ************************************************************************/

#include <iostream> 
#include "satellite.h"

class HubbleLeft : public Satellite
{
public:

   // Constructors
   HubbleLeft() : Satellite()
   {
      pos = Position(0.0, 0.0);
      angle = Angle(0);
      speed = Position(0.0, 0.0);
   }
   HubbleLeft(Position location, Angle ang, int rad, Position move) : Satellite(location, ang, rad, move)
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
