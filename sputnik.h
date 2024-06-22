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
   Sputnik()
   {
   };
   Sputnik(Position location, Angle ang, int rad)
   {
      pos = location;
      angle = ang;
      rad = radius;
   }

   void draw();
   void move();
   void collide();

   Position pos =    Position(-36515095.13, 21082000.0);
   Angle angle;
   Position speed =  Position(2050.0, 2684.68);

private:



};