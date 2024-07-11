#pragma once
/***********************************************************************
 * Header File:
 *    Hubble Scope: Class which houses all the functionality of the Telescope of the Hubble satellite
 * Author:
 *    Cayden Lords
 * Summary:
 *    This contains everything the game needs to implement the Telescope side of the Hubble into the simulator
 ************************************************************************/

#include <iostream> 
#include "satellite.h"

class HubbleScope : public Satellite
{
public:

   // Constructors
   HubbleScope() : Satellite()
   {
      pos = Position(0.0, 0.0);
      angle = Angle(0);
      speed = Position(0.0, 0.0);
   }
   HubbleScope(Position location, Angle ang, int rad, Position move) : Satellite(location, ang, rad, move)
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
