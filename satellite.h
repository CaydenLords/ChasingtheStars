#pragma once
/***********************************************************************
 * Header File:
 *    Inertia: Class which runs all of the physics for the simulator
 * Author:
 *    Ryan Donaldson
 * Summary:
 *    This contains everything the game needs to simulate physics for the sattelites
 ************************************************************************/

#include <iostream> 
#include <cmath>
#include "body.h"
#include "inertia.h"

class Satellite : public Inertia
{
public:
   void setPosition(double x, double y);
   Position getPosition();
   Angle getAngle();

   // Constructors
   Satellite()
   {
   };
   Satellite(Position location, Angle ang)
   {
      pos = location;
      angle = ang;
   }

   Position pos;
   Angle angle;
   Position speed;

private:



};