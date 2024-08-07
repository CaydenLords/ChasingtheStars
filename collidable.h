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
#include "uiDraw.h"
#include <vector>

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
      fragments = 0;
   }
   Collidable(Position location, int rad)
   {
      pos = location;
      angle = Angle(0);
      radius = rad;
      fragments = 0;
   }
   Collidable(Position location, Angle myAngle, int pieces)
   {
      pos = location;
      angle = myAngle;
      radius = 0;
      fragments = pieces;
   }

   virtual void draw(bool down) {};
   virtual bool move(bool left, bool right, bool down) { return false; };
   virtual std::vector<Collidable*> collide();
   virtual std::vector<Collidable*> makeFragments(std::vector<Collidable*> pieces, int frags);

   //getter 
   Position getPos()
   {
      return pos;
   }
   //setter 
   void setPos(Position location)
   {
      pos = location;
   }
   Position getSpeed() { return speed; }
   void setSpeed(Position newSpeed) { speed = newSpeed; }
   Angle getAngle() { return angle; };
   void setAngle(Angle newAngle) { angle = newAngle; };
   Position pos;
   int radius;
   Angle angle;
   Position speed;
   int fragments;
};