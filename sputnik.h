#pragma once
/***********************************************************************
 * Header File:
 *    Sputnik: Class which houses all the functionality of the Sputnik satellite
 * Author:
 *    Ryan Donaldson
 * Summary:
 *    This contains everything the game needs to implement Sputnik into the simulator
 ************************************************************************/

#include <iostream> 
#include "satellite.h"

class Sputnik : public Satellite
{
public:

   // Constructors
   Sputnik(): Satellite()
   {
      pos = Position(-36515095.13, 21082000.0);
      angle = Angle(0);
      speed = Position(2050.0, 2684.68);
   }
   Sputnik(Position location, Angle ang, int rad, Position move): Satellite(location, ang, rad, move)
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