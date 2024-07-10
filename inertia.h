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
   }
   Inertia(Position location, Angle ang)
   {
      pos = location;
      angle = ang;
   }
   Inertia(Position location, Angle ang, int rad, Position move){
      pos = location;
      angle = ang;
      radius = rad;
      speed = move;
   }

   virtual void draw(bool down);
   bool move(bool left, bool right, bool down);
   virtual void collide();


   Position pos;
   Angle angle;
   Position speed;

protected:
   float gravity(float height);
   float heightAboveEarth(Position place);
   float gravityDirection(Position place);
   float getHorizontal(float accel, float angle);
   float getVertical(float accel, float angle);
   float getDistance(float velocity, float time, float accel, float pos);
   float getVelocity(float velocity, float accel, float time);

};