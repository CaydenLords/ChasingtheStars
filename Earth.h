#pragma once
/***********************************************************************
 * Header File:
 *    Earth: Class which houses all the functionality of Earth
 * Author:
 *    Cayden Lords
 * Summary:
 *    This contains everything the game needs to simulate physics for the Earth
 ************************************************************************/

#include <iostream> 
#include "inertia.h"

class Earth : public Collidable
{
public:

   // Constructors
   Earth() : Collidable()
   {
      pos = Position(0, 0);
      angle = Angle(0);
      radius = 160;
   }
   Earth(Position location, Angle ang)
   {
      pos = location;
      angle = ang;
   }
   Earth(Position location, Angle ang, int rad) : Collidable(location, rad) {
      pos = location;
      angle = ang;
      radius = rad;
   }

   virtual void draw(bool down);
   bool move(bool left, bool right, bool down);
   std::vector<Collidable*> collide() override;


};