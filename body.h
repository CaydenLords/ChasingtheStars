#pragma once
/***********************************************************************
 * Header File:
 *    Body: A heavenly body (from astronomy)
 * Author:
 *    Cayden Lords
 * Summary:
 *    This contains the location of any item in our space simulation. 
 ************************************************************************/


#pragma once

#include <iostream> 
#include <cmath>
#include "position.h"


class TestBody;
class Acceleration;
class Velocity;

/*********************************************
 * Body
 * A heavenly body (from astronomy)
 *********************************************/

class Body {
public:
   // constructors
   Body();
   Body(Position location) 
   {
      pos = location;
   };

   //getter 
   Position getPos() 
   {
      return pos;
   };
   //setter 
   void setPos(Position location) {};

protected:
   Position pos;
};