#pragma once
/***********************************************************************
 * Header File:
 *    Collidable: An object that can hit other objects
 * Author:
 *    Cayden Lords
 * Summary:
 *    This contains the collision calculations of any object in our space simulations. 
 ************************************************************************/

#pragma once

#include <iostream> 
#include <cmath>
#include "position.h"
#include "body.h"
#include "angle.h"

class TestCollidable;
class Acceleration;
class Velocity;


/*********************************************
 * Collidable
 * Collidable: An object that can hit other objects
 *********************************************/

class Collidable : public Body
{
public:
   friend TestCollidable;
   // constructors
   Collidable() {
      pos = Position(0, 0);
      angle = 0;
      radius = 0;
   }
   Collidable(Position location, int rad)
   {
      pos = location;
      angle = Angle(0);
      radius = rad;
   }
   Collidable(Position location, Angle myAngle)
   {
      pos = location;
      angle = myAngle;
      radius = 0;
   }

   virtual void draw() {};
   virtual void move() {};
   //virtual void collide();

   //getter 
   Position getPos()
   {
      return pos;
   }
   //setter 
   void setPos(Position location) {
      pos = location;
   }

protected:
   Position pos;
   int radius;
   Angle angle;
};