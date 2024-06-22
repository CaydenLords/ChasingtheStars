/***********************************************************************
 * Source File:
 *    Inertia: All the physics for the simulation.
 * Author:
 *    Ryan Donaldson
 * Summary:
 *    This contains everything we need in order to run the simulation.
 ************************************************************************/

#include <cassert>      // for ASSERT
#include <math.h>       // For ATAN and a bunch of other math stuff
#include "uiInteract.h" // for INTERFACE
#include "uiDraw.h"     // for RANDOM and DRAW*
#include "position.h"      // for POINT
#include "inertia.h"
using namespace std;
#define TIME_DILATION 1440.0
#define TIME_PER_FRAME 48.0
#define TWO_PI 6.28318530718

double Position::metersFromPixels = 40.0;

 /************************************************************************
  * Rotate Earth
  * Calculates the radians the Earth is rotating
  *  OUTPUT rotation  The radians the Earth is rotating
  *************************************************************************/
float rotateEarth()
{
   return (TWO_PI / -30.0) * (TIME_DILATION / 86400.0);
}

/************************************************************************
 * Gravity
 * Calculates the acceleration of the gravity the Earth has at a certain height
 *  INPUT  height    The height above the Earth in meters
 *  OUTPUT gravity   The gravity's effect in acceleration
 *************************************************************************/
float gravity(float height)
{
   return 9.80665 * ((6378000.0 / (6378000.0 + height) * (6378000.0 / (6378000.0 + height))));
}

/************************************************************************
 * Height Above Earth
 * Calculates the acceleration of the gravity the Earth has at a certain height
 *  INPUT  place    The x and y coordinates of the object, where the Earth is (0,0)
 *  OUTPUT height   How high the object is above the Earth
 *************************************************************************/
float heightAboveEarth(Position place)
{
   return sqrt(place.getMetersX() * place.getMetersX() + place.getMetersY() * place.getMetersY()) - 6378000.0;
}

/************************************************************************
 * Direction of Gravity
 * Calculates what direction gravity is pulling (in radians)
 *  INPUT  place       The x and y coordinates of the object, where the Earth is (0,0)
 *  OUTPUT direction   What direction gravity is pulling in radians
 *************************************************************************/
float gravityDirection(Position place)
{
   return atan2(0.0 - place.getMetersX(), 0.0 - place.getMetersY());
}

/************************************************************************
 * Get Horizontal
 * calculates the horizontal component of acceleration
 *  INPUT  accel    The total acceleration of the object due to gravity
 *  INPUT  angle    The direction the gravity is pulling in radians
 *  OUTPUT xAccel   The horizontal component of the acceleration
 *************************************************************************/
float getHorizontal(float accel, float angle)
{
   return accel * sin(angle);
}

/************************************************************************
 * Get Vertical
 * calculates the vertical component of acceleration
 *  INPUT  accel    The total acceleration of the object due to gravity
 *  INPUT  angle    The direction the gravity is pulling in radians
 *  OUTPUT yAccel   The vertical component of the acceleration
 *************************************************************************/
float getVertical(float accel, float angle)
{
   return accel * cos(angle);
}

/************************************************************************
 * Get Distance
 * calculates where an object moves
 * INPUT  velocity   How fast the object is currently moving
 * INPUT  time       How much time has passed
 * INPUT  accel      The acceleration of the object due to gravity
 * INPUT  pos        The location of the object (either x or y)
 * OUTPUT newPos     Where the object is now
 *************************************************************************/
float getDistance(float velocity, float time, float accel, float pos)
{
   return pos + (velocity * time) + (0.5 * accel * time * time);
}

/************************************************************************
 * Get Velocity
 * calculates how fast an object is now moving
 * INPUT  velocity   How fast the object is currently moving
 * INPUT  accel      The acceleration of the object
 * INPUT  time       How much time has passed
 * OUTPUT newVel     How fast the object is now moving
 *************************************************************************/
float getVelocity(float velocity, float accel, float time)
{
   return velocity + (accel * time);
}

/************************************************************************
 * Set Position
 * Sets the position of the inertia object
 *************************************************************************/
void Inertia::setPosition(double x, double y)
{
   Position myPosition(x, y);
   pos = myPosition;
}

/************************************************************************
 * Get Position
 * Retruns the position of the inertia object
 *************************************************************************/
Position Inertia::getPosition()
{
   return pos;
}

/************************************************************************
 * Get Angle
 * Retruns the angle of the inertia object
 *************************************************************************/
Angle Inertia::getAngle()
{
   return angle;
}

/************************************************************************
 * Draw
 * Allows the inertia object to be drawn
 *************************************************************************/
void Inertia::draw() {};

/************************************************************************
 * Move
 * Moves the inertia object
 *************************************************************************/
void Inertia::move() 
{
   //get the height of the satellite above the Earth and the acceleration gravity causes
   float orbitHeight = heightAboveEarth(pos);
   float orbitGravityAcceleration = gravity(orbitHeight);

   // Get the angle of gravity on the ship, horizontal and vertical components
   float gravityAngle = gravityDirection(pos);
   float xComp = getHorizontal(orbitGravityAcceleration, gravityAngle);
   float yComp = getVertical(orbitGravityAcceleration, gravityAngle);

   // Update ship's velocity
   speed.setMetersX(getVelocity(speed.getMetersX(), xComp, TIME_PER_FRAME));
   speed.setMetersY(getVelocity(speed.getMetersY(), yComp, TIME_PER_FRAME));

   // Move the Satellite
   pos.setMetersX(getDistance(speed.getMetersX(), TIME_PER_FRAME, xComp, pos.getMetersX()));
   pos.setMetersY(getDistance(speed.getMetersY(), TIME_PER_FRAME, yComp, pos.getMetersY()));
};

/************************************************************************
 * Collide
 * Checks if the inertia object has collided with another object
 *************************************************************************/
void Inertia::collide() {};