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
   // constructors
   Collidable();
   Collidable(Position location, int rad)
   {
      pos = location;
      radius = rad;
   };
   Collidable(Position location, Angle myAngle)
   {
      pos = location;
      angle = myAngle;
      radius = 0;
   }

   //getter 
   Position getPos()
   {
      return pos;
   };
   void move() {};
   //setter 
   void setPos(Position location) {};

protected:
   Position pos;
   int radius;
   Angle angle;
};