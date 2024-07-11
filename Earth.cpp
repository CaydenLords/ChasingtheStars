/***********************************************************************
 * Source File:
 *    Earth: The Earth class for the simulation
 * Author:
 *    Cayden Lords
 * Summary:
 *    This contains all of the functionality for the Earth
 ************************************************************************/

#include "position.h"
#include "collidable.h"
#include "earth.h"
#include "uiDraw.h"

 /************************************************************************
  * Draw
  * Allows the Earth to be drawn
  *************************************************************************/
void Earth::draw(bool down)
{
   ogstream gout;
   gout.drawEarth(pos, angle.getDegrees());
};

/************************************************************************
 * Move
 * Moves the Earth
 *************************************************************************/
bool Earth::move(bool left, bool right, bool down)
 {
    angle.setRadians(angle.getRadians() + ((TWO_PI / -30.0) * (1440 / 86400.0) / 48));
    return false;
 };

 /************************************************************************
  * Collide
  * Checks if the Hubble object has collided with another object
  *************************************************************************/
void Earth::collide() {};