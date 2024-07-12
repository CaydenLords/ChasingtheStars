#pragma once
/***********************************************************************
 * Header File:
 *    Hubble: Class which houses all the functionality of the Hubble satellite
 * Author:
 *    Ryan Donaldson
 * Summary:
 *    This contains everything the game needs to implement Hubble into the simulator
 ************************************************************************/

#include <iostream> 
#include "satellite.h"

class Hubble : public Satellite
{
public:

   // Constructors
   Hubble() : Satellite()
   {
      pos = Position(0.0, -42164000.0);
      angle = Angle(0);
      speed = Position(3100.0, 0.0);
   }
   Hubble(Position location, Angle ang, int rad, Position move, int pieces) : Satellite(location, ang, rad, move, pieces)
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