/***********************************************************************
 * Source File:
 *    Sputnik: The Sputnik class for the simulation
 * Author:
 *    Ryan Donaldson
 * Summary:
 *    This contains all of the functionality for the Sputnik satellite
 ************************************************************************/

#include "position.h"
#include "satellite.h"
#include "sputnik.h"
#include "uiDraw.h"

// /************************************************************************
//  * Set Position
//  * Sets the position of the Sputnik satellite
//  *************************************************************************/
//void Sputnik::setPosition(double x, double y)
//{
//   Position myPosition(x, y);
//   pos = myPosition;
//}
//
///************************************************************************
// * Get Position
// * Retruns the position of the Sputnik satellite
// *************************************************************************/
//Position Sputnik::getPosition()
//{
//   return pos;
//}
//
///************************************************************************
// * Get Angle
// * Retruns the angle of the Sputnik satellite
// *************************************************************************/
//Angle Sputnik::getAngle()
//{
//   return angle;
//}

/************************************************************************
 * Draw
 * Allows the Sputnik object to be drawn
 *************************************************************************/
void Sputnik::draw(bool down) 
{
   ogstream gout;
   gout.drawSputnik(pos, 0);
};

/************************************************************************
 * Move
 * Moves the Sputnik object
 *************************************************************************/
//void Sputnik::move()
//{
//   Inertia::move();
//};

/************************************************************************
 * Collide
 * Checks if the Sputnik object has collided with another object
 *************************************************************************/
void Sputnik::collide() {};