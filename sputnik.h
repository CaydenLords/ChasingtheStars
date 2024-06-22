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
   void setPosition(double x, double y);
   Position getPosition();
   Angle getAngle();

   // Constructors
   Sputnik(): Satellite()
   {
      pos = Position(-36515095.13, 21082000.0);
      angle = Angle(0);
      speed = Position(2050.0, 2684.68);
   };
   Sputnik(Position location, Angle ang, int rad, Position move): Satellite(location, ang, rad, move)
   {
      pos = location;
      angle = ang;
      rad = radius;
      speed = move;
   }

   void draw();
   void move();
   void collide();



private:
   Position pos;
   Angle angle;
   Position speed;


};