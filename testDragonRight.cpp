/***********************************************************************
 * Source File:
 *    TEST DragonRight
 * Author:
 *    Cayden Lords
 * Summary:
 *    The unit tests for DragonRight satellite
 ************************************************************************/

#include "testDragonRight.h"
#include "inertia.h"
#include "position.h"
#include <cassert>

 /*************************************
   * TEST SET POSITION : DragonRight
   * Input: 0, 0
   * Output: 0, 0
   **************************************/
void TestDragonRight::test_setPosition()
{
   // SETUP
   DragonRight sat;

   // EXERCISE
   sat.setPosition(0, 0);

   // VERIFY
   assertUnit(sat.pos.getMetersX() == 0);
   assertUnit(sat.pos.getMetersY() == 0);
   // TEARDOWN

}

/*************************************
 * TEST GET POSITION : DragonRight
 * Input:
 * Output: 0, 0
 **************************************/
void TestDragonRight::test_getPosition()
{
   // SETUP
   DragonRight sat;
   sat.pos = Position(0, 0);

   // EXERCISE
   Position myPosition = sat.getPosition();

   // VERIFY
   assertUnit(myPosition == Position(0, 0));
   // TEARDOWN

}

/*************************************
  * TEST GET ANGLE : DragonRight
  * Input: 0, 0
  * Output: 0, 0
  **************************************/
void TestDragonRight::test_getAngle()
{
   // SETUP
   DragonRight inertia;
   inertia.angle = Angle(100);

   // EXERCISE
   Angle myAngle = inertia.getAngle();

   // VERIFY
   assertUnit(myAngle.getDegrees() == 100);
   // TEARDOWN
}

