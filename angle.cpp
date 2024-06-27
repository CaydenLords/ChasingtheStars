/***********************************************************************
 * Source File:
 *    Angle : The representation of a direction for an object
 * Author:
 *    Ryan Donaldson
 * Summary:
 *    Everything we need to know the angle (or direction) of a object
 ************************************************************************/


#define TWO_PI 6.28318530718
#define PI (TWO_PI / 2)
#include <cmath>    // for floor()
#include <iostream>  // for cout
#include <cassert>   // for assert()
using namespace std;

#include "angle.h"

// Insertion operator
std::ostream& operator<<(std::ostream& out, const Angle& rhs)
{
   rhs.display(out); // Call the display method of Angle
   return out;
}

// Extraction operator
std::istream& operator>>(std::istream& in, Angle& rhs)
{
   int newDegrees;
   in >> newDegrees;
   rhs.setDegrees(newDegrees);
   return in;
}