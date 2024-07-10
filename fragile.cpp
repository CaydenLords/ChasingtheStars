/***********************************************************************
 * Source File:
 *    Fragile: Object which disappears after a short time. 
 * Author:
 *    Cayden Lords
 * Summary:
 *    This contains everything the game needs to simulate physics for the fragile items
 ************************************************************************/

#include <cassert>      // for ASSERT
#include <math.h>       // For ATAN and a bunch of other math stuff
#include "uiInteract.h" // for INTERFACE
#include "uiDraw.h"     // for RANDOM and DRAW*
#include "position.h"      // for POINT
#include "fragile.h"
using namespace std;
#define TIME_PER_FRAME 48.0


bool Fragile::move(bool left, bool right, bool down)
{
   //get the height of the fragile above the Earth and the acceleration gravity causes
   float orbitHeight = heightAboveEarth(pos);
   float orbitGravityAcceleration = gravity(orbitHeight);

   // Get the angle of gravity on the ship, horizontal and vertical components
   float gravityAngle = gravityDirection(pos);
   float xComp = getHorizontal(orbitGravityAcceleration, gravityAngle);
   float yComp = getVertical(orbitGravityAcceleration, gravityAngle);

   // Update ship's velocity
   speed.setMetersX(getVelocity(speed.getMetersX(), xComp, TIME_PER_FRAME));
   speed.setMetersY(getVelocity(speed.getMetersY(), yComp, TIME_PER_FRAME));

   // Move the fragile
   pos.setMetersX(getDistance(speed.getMetersX(), TIME_PER_FRAME, xComp, pos.getMetersX()));
   pos.setMetersY(getDistance(speed.getMetersY(), TIME_PER_FRAME, yComp, pos.getMetersY()));

   // Reduce the amount of framesLeft
   framesLeft--;
   if (framesLeft <= 0) {
      return true;
   }
   return false;
};