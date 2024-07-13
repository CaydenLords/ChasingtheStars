/***********************************************************************
 * Source File:
 *    TEST StarlinkArray
 * Author:
 *    Ryan Donaldson
 * Summary:
 *    The unit tests for StarlinkArray satellite
 ************************************************************************/

#include "testStarlinkArray.h"
#include "inertia.h"
#include "position.h"
#include <cassert>

 /*************************************
   * TEST SET POSITION : StarlinkArray
   * Input: 0, 0
   * Output: 0, 0
   **************************************/
void TestStarlinkArray::test_setPosition()
{
   // SETUP
   StarlinkArray sat;

   // EXERCISE
   sat.setPosition(0, 0);

   // VERIFY
   assertUnit(sat.pos.getMetersX() == 0);
   assertUnit(sat.pos.getMetersY() == 0);
   // TEARDOWN

}

/*************************************
 * TEST GET POSITION : StarlinkArray
 * Input:
 * Output: 0, 0
 **************************************/
void TestStarlinkArray::test_getPosition()
{
   // SETUP
   StarlinkArray sat;
   sat.pos = Position(0, 0);

   // EXERCISE
   Position myPosition = sat.getPosition();

   // VERIFY
   assertUnit(myPosition == Position(0, 0));
   // TEARDOWN

}

/*************************************
  * TEST GET ANGLE : StarlinkArray
  * Input: 0, 0
  * Output: 0, 0
  **************************************/
void TestStarlinkArray::test_getAngle()
{
   // SETUP
   StarlinkArray inertia;
   inertia.angle = Angle(100);

   // EXERCISE
   Angle myAngle = inertia.getAngle();

   // VERIFY
   assertUnit(myAngle.getDegrees() == 100);
   // TEARDOWN
}

/*************************************
  * TEST COLLIDE : STARLINKARRAY
  * Input: Collision scenario
  * Output: List of new objects
  **************************************/
void TestStarlinkArray::test_collide()
{
   // SETUP
   StarlinkArray module(Position(1000, 1000), Angle(100), 6, Position(200, 200), 3);
   std::vector<Collidable*> myObjects;

   // EXERCISE
   myObjects = module.collide();

   // VERIFY
   assertUnit(myObjects.size() == 3);
   // TEARDOWN
}