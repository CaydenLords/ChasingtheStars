#pragma once
/***********************************************************************
 * Header File:
 *    Chaser: Class which houses all the functionality of our Chaser ship
 * Author:
 *    Ryan Donaldson
 * Summary:
 *    This contains everything the game needs to implement Chaser and control it 
 ************************************************************************/

#include <iostream> 
#include "satellite.h"

class Chaser : public Satellite
{
public:
   // Constructors
   Chaser() : Satellite()
   {
   }
   Chaser(Position location, Angle ang, int rad, Position move) : Satellite(location, ang, rad, move)
   {
      pos = location;
      angle = ang;
      radius = rad;
      speed = move;
   }

   void draw(bool down);
   void move(bool left, bool right, bool down);
   void collide();

};