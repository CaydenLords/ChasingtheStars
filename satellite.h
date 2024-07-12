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

   // Constructors
   Satellite(): Inertia()
   {
   }
   Satellite(Position location, Angle ang)
   {
      pos = location;
      angle = ang;
   }
   Satellite(Position location, Angle ang, int rad, Position move, int pieces): Inertia(location, ang, rad, move, pieces)
   {
      pos = location;
      angle = ang;
      radius = rad;
      speed = move;
      fragments = pieces;
   }

   virtual void draw(bool down);
   //void move();
   virtual std::vector<Collidable> collide();


};