/***********************************************************************
 * Source File:
 *    TEST GPS
 * Author:
 *    Ryan Donaldson
 * Summary:
 *    The unit tests for GPS satellite
 ************************************************************************/

#include "testGPS.h"
#include "inertia.h"
#include "position.h"
#include <cassert>

 /*************************************
   * TEST SET POSITION : GPS
   * Input: 0, 0
   * Output: 0, 0
   **************************************/
void TestGPS::test_setPosition()
{
   // SETUP
   GPS sat;

   // EXERCISE
   sat.setPosition(0, 0);

   // VERIFY
   assertUnit(sat.pos == Position(0, 0));
   // TEARDOWN

}

/*************************************
 * TEST GET POSITION : GPS
 * Input:
 * Output: 0, 0
 **************************************/
void TestGPS::test_getPosition()
{
   // SETUP
   GPS sat;
   sat.pos = Position(0, 0);

   // EXERCISE
   Position myPosition = sat.getPosition();

   // VERIFY
   assertUnit(myPosition == Position(0, 0));
   // TEARDOWN

}

/*************************************
  * TEST GET ANGLE : GPS
  * Input: 0, 0
  * Output: 0, 0
  **************************************/
void TestGPS::test_getAngle()
{
   // SETUP
   GPS inertia;
   inertia.angle = Angle(100);

   // EXERCISE
   Angle myAngle = inertia.getAngle();

   // VERIFY
   assertUnit(myAngle.getDegrees() == 100);
   // TEARDOWN
}

/*************************************
  * TEST COLLIDE : GPS
  * Input: Collision scenario
  * Output: List of new objects
  **************************************/
void TestGPS::test_collide()
{
   // SETUP
   GPS module(Position(1000, 1000), Angle(100), 0, Position(200, 200), 2);
   std::vector<Collidable*> myObjects;

   // EXERCISE
   myObjects = module.collide();

   // VERIFY
   assertUnit(myObjects.size() == 5);
   // TEARDOWN
}

