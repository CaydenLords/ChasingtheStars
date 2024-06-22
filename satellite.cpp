/***********************************************************************
 * Source File:
 *    Satellite: The Satellite class for the simulation
 * Author:
 *    Ryan Donaldson
 * Summary:
 *    This contains all of the functionality for the satellite object
 ************************************************************************/

#include "position.h"
#include "inertia.h"
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

/************************************************************************
 * Draw
 * Allows the Satellite object to be drawn
 *************************************************************************/
void Satellite::draw() {};

/************************************************************************
 * Move
 * Moves the Satellite object
 *************************************************************************/
void Satellite::move()
{
   Inertia::move();
};

/************************************************************************
 * Collide
 * Checks if the Satellite object has collided with another object
 *************************************************************************/
void Satellite::collide() {};