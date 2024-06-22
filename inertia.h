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
#include "collidable.h"

class Inertia : public Collidable
{
public:
   void setPosition(double x, double y);
   Position getPosition();
   Angle getAngle();

   // Constructors
   Inertia()
   {
   };
   Inertia(Position location, Angle ang)
   {
      pos = location;
      angle = ang;
   }

   virtual void draw();
   void move();
   virtual void collide();


   Position pos;
   Angle angle;
   Position speed;

private:



};