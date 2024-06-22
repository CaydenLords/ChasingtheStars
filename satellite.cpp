/***********************************************************************
 * Source File:
 *    Satellite: The Satellite class for the simulation
 * Author:
 *    Ryan Donaldson
 * Summary:
 *    This contains all of the functionality for the satellite object
 ************************************************************************/

#include "position.h"
#include "satellite.h"

 /************************************************************************
  * Set Position
  * Sets the position of the inertia object
  *************************************************************************/
void Satellite::setPosition(double x, double y)
{
   Position myPosition(x, y);
   pos = myPosition;
}

/************************************************************************
 * Get Position
 * Retruns the position of the inertia object
 *************************************************************************/
Position Satellite::getPosition()
{
   return pos;
}

/************************************************************************
 * Get Angle
 * Retruns the angle of the inertia object
 *************************************************************************/
Angle Satellite::getAngle()
{
   return angle;
}
