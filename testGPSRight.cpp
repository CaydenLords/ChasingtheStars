/***********************************************************************
 * Source File:
 *    TEST GPSRight
 * Author:
 *    Cayden Lords
 * Summary:
 *    The unit tests for GPSRight satellite
 ************************************************************************/

#include "testGPSRight.h"
#include "inertia.h"
#include "position.h"
#include <cassert>

 /*************************************
   * TEST SET POSITION : GPSRight
   * Input: 0, 0
   * Output: 0, 0
   **************************************/
void TestGPSRight::test_setPosition()
{
   // SETUP
   GPSRight sat;

   // EXERCISE
   sat.setPosition(0, 0);

   // VERIFY
   assertUnit(sat.pos == Position(0, 0));
   // TEARDOWN

}

/*************************************
 * TEST GET POSITION : GPSRight
 * Input:
 * Output: 0, 0
 **************************************/
void TestGPSRight::test_getPosition()
{
   // SETUP
   GPSRight sat;
   sat.pos = Position(0, 0);

   // EXERCISE
   Position myPosition = sat.getPosition();

   // VERIFY
   assertUnit(myPosition == Position(0, 0));
   // TEARDOWN

}

/*************************************
  * TEST GET ANGLE : GPSRight
  * Input: 0, 0
  * Output: 0, 0
  **************************************/
void TestGPSRight::test_getAngle()
{
   // SETUP
   GPSRight inertia;
   inertia.angle = Angle(100);

   // EXERCISE
   Angle myAngle = inertia.getAngle();

   // VERIFY
   assertUnit(myAngle.getDegrees() == 100);
   // TEARDOWN
}

/*************************************
  * TEST COLLIDE : GPSRight
  * Input: Collision scenario
  * Output: List of new objects
  **************************************/
void TestGPSRight::test_collide()
{
   // SETUP
   GPSRight module(Position(1000, 1000), Angle(100), 0, Position(200, 200), 3);
   std::vector<Collidable*> myObjects;

   // EXERCISE
   myObjects = module.collide();

   // VERIFY
   assertUnit(myObjects.size() == 3);
   // TEARDOWN
}