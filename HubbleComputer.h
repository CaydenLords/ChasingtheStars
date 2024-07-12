#pragma once
/***********************************************************************
 * Header File:
 *    Hubble Computer: Class which houses all the functionality of the Computer of the Hubble satellite
 * Author:
 *    Cayden Lords
 * Summary:
 *    This contains everything the game needs to implement the Computer side of the Hubble into the simulator
 ************************************************************************/

#include <iostream> 
#include "satellite.h"

class HubbleComputer : public Satellite
{
public:

   // Constructors
   HubbleComputer() : Satellite()
   {
      pos = Position(0.0, 0.0);
      angle = Angle(0);
      speed = Position(0.0, 0.0);
   }
   HubbleComputer(Position location, Angle ang, int rad, Position move, int pieces) : Satellite(location, ang, rad, move, pieces)
   {
      pos = location;
      angle = ang;
      radius = rad;
      speed = move;
      fragments = pieces;
   }

   void draw(bool down);
   //void move();
   void collide();

}; 