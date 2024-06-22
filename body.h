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
#include "uiDraw.h"


class TestBody;
class Acceleration;
class Velocity;

/*********************************************
 * Body
 * A heavenly body (from astronomy)
 *********************************************/

class Body 
{
public:
   friend TestBody;
   // constructors
   Body() 
   {
      pos = Position(0, 0);
   };
   Body(Position location) 
   {
      pos = location;
   };

   //getter 
   Position getPos() 
   {
      return pos;
   };
   void draw(ogstream* gout) 
   {
   };
   //setter 
   void setPos(Position location) {
      pos = location;
   };

protected:
   Position pos;
};