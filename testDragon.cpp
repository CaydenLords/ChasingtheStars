/***********************************************************************
 * Source File:
 *    TEST DRAGON
 * Author:
 *    Ryan Donaldson
 * Summary:
 *    The unit tests for Dragon satellite
 ************************************************************************/

#include "testDragon.h"
#include "inertia.h"
#include "position.h"
#include <cassert>

 /*************************************
   * TEST SET POSITION : Dragon
   * Input: 0, 0
   * Output: 0, 0
   **************************************/
void TestDragon::test_setPosition()
{
   // SETUP
   Dragon sat;

   // EXERCISE
   sat.setPosition(0, 0);

   // VERIFY
   assertUnit(sat.pos.getMetersX() == 0);
   assertUnit(sat.pos.getMetersY() == 0);
   // TEARDOWN

}

/*************************************
 * TEST GET POSITION : Dragon
 * Input:
 * Output: 0, 0
 **************************************/
void TestDragon::test_getPosition()
{
   // SETUP
   Dragon sat;
   sat.pos = Position(0, 0);

   // EXERCISE
   Position myPosition = sat.getPosition();

   // VERIFY
   assertUnit(myPosition == Position(0, 0));
   // TEARDOWN

}

/*************************************
  * TEST GET ANGLE : Dragon
  * Input: 0, 0
  * Output: 0, 0
  **************************************/
void TestDragon::test_getAngle()
{
   // SETUP
   Dragon inertia;
   inertia.angle = Angle(100);

   // EXERCISE
   Angle myAngle = inertia.getAngle();

   // VERIFY
   assertUnit(myAngle.getDegrees() == 100);
   // TEARDOWN
}

