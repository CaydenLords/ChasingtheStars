/***********************************************************************
 * Source File:
 *    Chaser: Class which houses all the functionality of our Chaser ship
 * Author:
 *    Ryan Donaldson
 * Summary:
 *    This contains everything the game needs to implement Chaser and control it
 ************************************************************************/

#include "position.h"
#include "satellite.h"
#include "chaser.h"
#include "uiDraw.h"

#define TIME_PER_FRAME 48.0


 // /************************************************************************
 //  * Set Position
 //  * Sets the position of the Chaser satellite
 //  *************************************************************************/
 //void Chaser::setPosition(double x, double y)
 //{
 //   Position myPosition(x, y);
 //   pos = myPosition;
 //}
 //
 ///************************************************************************
 // * Get Position
 // * Retruns the position of the Chaser satellite
 // *************************************************************************/
 //Position Chaser::getPosition()
 //{
 //   return pos;
 //}
 //
 ///************************************************************************
 // * Get Angle
 // * Retruns the angle of the Chaser satellite
 // *************************************************************************/
 //Angle Chaser::getAngle()
 //{
 //   return angle;
 //}

 /************************************************************************
  * Draw
  * Allows the Chaser object to be drawn
  *************************************************************************/
void Chaser::draw(bool down)
{
   ogstream gout;
   gout.drawShip(pos, angle.getRadians(), down);
};

/************************************************************************
 * Move
 * Moves the Chaser object
 *************************************************************************/
 bool Chaser::move(bool left, bool right, bool down)
 {
    if (left) {
       angle.setRadians(angle.getRadians() - 0.1);
    }
    if (right) {
       angle.setRadians(angle.getRadians() + 0.1);
    }
    //get the height of the satellite above the Earth and the acceleration gravity causes
    float orbitHeight = heightAboveEarth(pos);
    float orbitGravityAcceleration = gravity(orbitHeight);

    // Get the angle of gravity on the ship, horizontal and vertical components
    float gravityAngle = gravityDirection(pos);
    float xComp = getHorizontal(orbitGravityAcceleration, gravityAngle);
    float yComp = getVertical(orbitGravityAcceleration, gravityAngle);
    if (down) {
       xComp = xComp + getHorizontal(2.0, angle.getRadians());
       yComp = yComp + getVertical(2.0, angle.getRadians());
    }

    // Update ship's velocity
    speed.setMetersX(getVelocity(speed.getMetersX(), xComp, TIME_PER_FRAME));
    speed.setMetersY(getVelocity(speed.getMetersY(), yComp, TIME_PER_FRAME));

    // Move the Satellite
    pos.setMetersX(getDistance(speed.getMetersX(), TIME_PER_FRAME, xComp, pos.getMetersX()));
    pos.setMetersY(getDistance(speed.getMetersY(), TIME_PER_FRAME, yComp, pos.getMetersY()));

    return false;
 };

 /************************************************************************
  * Collide
  * Checks if the Chaser object has collided with another object
  *************************************************************************/
 std::vector<Collidable*> Chaser::collide()
 {
    std::vector<Collidable*> objects;
    return objects;
 };