#pragma once
/***********************************************************************
 * Header File:
 *    Satellite: Class which houses all the functionality of a satellite
 * Author:
 *    Ryan Donaldson
 * Summary:
 *    This contains everything the game needs to simulate physics for the sattelites
 ************************************************************************/

#include <iostream> 
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

   virtual void draw();
   virtual void move();
   virtual void collide();

   Position pos;
   Angle angle;
   Position speed;

private:



};