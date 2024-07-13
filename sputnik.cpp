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
#include <vector>

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
   gout.drawSputnik(pos, angle.getDegrees());
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
 * Handles what happens after Sputnik hits something
 *************************************************************************/
std::vector<Collidable*> Sputnik::collide()
{
   std::vector<Collidable*> objects;

   std::vector<Collidable*> newFragments = makeFragments(fragments);

   objects.insert(objects.end(), newFragments.begin(), newFragments.end());

   return objects;
};