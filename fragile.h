#pragma once
/***********************************************************************
 * Header File:
 *    Fragile: Object which disappears after a short time. 
 * Author:
 *    Cayden Lords
 * Summary:
 *    This contains everything the game needs to simulate physics for the fragile items
 ************************************************************************/

#include <iostream> 
#include <cmath>
#include "body.h"
#include "inertia.h"

class Fragile : public Inertia {
public:
   Fragile() : Inertia() {
      pos = Position(0,0);
      angle = Angle(0);
      radius = 1;
      speed = Position(0,0);
      framesLeft = 10;
   }
   Fragile(Position location, Angle ang, int rad, Position move) : Inertia(location, ang, rad, move) {
      pos = location;
      angle = ang;
      radius = rad;
      speed = move;
      framesLeft = 10;
   }
   bool move(bool left, bool right, bool down);
   int framesLeft;
};
