/***********************************************************************
 * Source File:
 *    TEST INERTIA
 * Author:
 *    Ryan Donaldson
 * Summary:
 *    The unit tests for inertia
 ************************************************************************/

#include "testInertia.h"
#include "inertia.h"
#include "position.h"
#include <cassert>

 /*************************************
   * TEST SET POSITION : Inertia
   * Input: 0, 0
   * Output: 0, 0
   **************************************/
void TestInertia::test_setPosition()
{
   // SETUP
   Inertia inertia;

   // EXERCISE
   inertia.setPosition(0, 0);

   // VERIFY
   assertUnit(inertia.pos.getMetersX() == 0);
   assertUnit(inertia.pos.getMetersY() == 0);
   // TEARDOWN

}

 /*************************************
  * TEST GET POSITION : Inertia
  * Input:
  * Output: 0, 0
  **************************************/
void TestInertia::test_getPosition()
{
   // SETUP
   Inertia inertia;
   inertia.setPosition(0, 0);

   // EXERCISE
   Position myPosition = inertia.getPosition();

   // VERIFY
   assertUnit(myPosition == Position(0, 0));
   // TEARDOWN

}

/*************************************
  * TEST GET ANGLE : Inertia
  * Input: 0, 0
  * Output: 0, 0
  **************************************/
void TestInertia::test_getAngle()
{
   // SETUP
   Position location(0, 0);
   Angle ang(100);
   Inertia inertia(location, ang);

   // EXERCISE
   Angle myAngle = inertia.getAngle();

   // VERIFY
   assertUnit(myAngle.getRadians() == 100);
   // TEARDOWN
}