/***********************************************************************
 * Source File:
 *    TEST StarlinkBody
 * Author:
 *    Ryan Donaldson
 * Summary:
 *    The unit tests for StarlinkBody satellite
 ************************************************************************/

#include "testStarlinkBody.h"
#include "inertia.h"
#include "position.h"
#include <cassert>

 /*************************************
   * TEST SET POSITION : StarlinkBody
   * Input: 0, 0
   * Output: 0, 0
   **************************************/
void TestStarlinkBody::test_setPosition()
{
   // SETUP
   StarlinkBody sat;

   // EXERCISE
   sat.setPosition(0, 0);

   // VERIFY
   assertUnit(sat.pos.getMetersX() == 0);
   assertUnit(sat.pos.getMetersY() == 0);
   // TEARDOWN

}

/*************************************
 * TEST GET POSITION : StarlinkBody
 * Input:
 * Output: 0, 0
 **************************************/
void TestStarlinkBody::test_getPosition()
{
   // SETUP
   StarlinkBody sat;
   sat.pos = Position(0, 0);

   // EXERCISE
   Position myPosition = sat.getPosition();

   // VERIFY
   assertUnit(myPosition == Position(0, 0));
   // TEARDOWN

}

/*************************************
  * TEST GET ANGLE : StarlinkBody
  * Input: 0, 0
  * Output: 0, 0
  **************************************/
void TestStarlinkBody::test_getAngle()
{
   // SETUP
   StarlinkBody inertia;
   inertia.angle = Angle(100);

   // EXERCISE
   Angle myAngle = inertia.getAngle();

   // VERIFY
   assertUnit(myAngle.getDegrees() == 100);
   // TEARDOWN
}

