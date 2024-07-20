/***********************************************************************
 * Source File:
 *    TEST GPSLeft
 * Author:
 *    Cayden Lords
 * Summary:
 *    The unit tests for GPSLeft satellite
 ************************************************************************/

#include "testGPSLeft.h"
#include "inertia.h"
#include "position.h"
#include <cassert>

 /*************************************
   * TEST SET POSITION : GPSLeft
   * Input: 0, 0
   * Output: 0, 0
   **************************************/
void TestGPSLeft::test_setPosition()
{
   // SETUP
   GPSLeft sat;

   // EXERCISE
   sat.setPosition(0, 0);

   // VERIFY
   assertUnit(sat.pos == Position(0, 0));
   // TEARDOWN

}

/*************************************
 * TEST GET POSITION : GPSLeft
 * Input:
 * Output: 0, 0
 **************************************/
void TestGPSLeft::test_getPosition()
{
   // SETUP
   GPSLeft sat;
   sat.pos = Position(0, 0);

   // EXERCISE
   Position myPosition = sat.getPosition();

   // VERIFY
   assertUnit(myPosition == Position(0, 0));
   // TEARDOWN

}

/*************************************
  * TEST GET ANGLE : GPSLeft
  * Input: 0, 0
  * Output: 0, 0
  **************************************/
void TestGPSLeft::test_getAngle()
{
   // SETUP
   GPSLeft inertia;
   inertia.angle = Angle(100);

   // EXERCISE
   Angle myAngle = inertia.getAngle();

   // VERIFY
   assertUnit(myAngle.getDegrees() == 100);
   // TEARDOWN
}

/*************************************
  * TEST COLLIDE : GPSLEFT
  * Input: Collision scenario
  * Output: List of new objects
  **************************************/
void TestGPSLeft::test_collide()
{
   // SETUP
   GPSLeft module(Position(1000, 1000), Angle(100), 0, Position(200, 200), 3);
   std::vector<Collidable*> myObjects;

   // EXERCISE
   myObjects = module.collide();

   // VERIFY
   assertUnit(myObjects.size() == 3);
   // TEARDOWN
}