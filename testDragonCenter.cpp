/***********************************************************************
 * Source File:
 *    TEST DragonCenter
 * Author:
 *    Cayden Lords
 * Summary:
 *    The unit tests for DragonCenter satellite
 ************************************************************************/

#include "testDragonCenter.h"
#include "inertia.h"
#include "position.h"
#include <cassert>

 /*************************************
   * TEST SET POSITION : DragonCenter
   * Input: 0, 0
   * Output: 0, 0
   **************************************/
void TestDragonCenter::test_setPosition()
{
   // SETUP
   DragonCenter sat;

   // EXERCISE
   sat.setPosition(0, 0);

   // VERIFY
   assertUnit(sat.pos.getMetersX() == 0);
   assertUnit(sat.pos.getMetersY() == 0);
   // TEARDOWN

}

/*************************************
 * TEST GET POSITION : DragonCenter
 * Input:
 * Output: 0, 0
 **************************************/
void TestDragonCenter::test_getPosition()
{
   // SETUP
   DragonCenter sat;
   sat.pos = Position(0, 0);

   // EXERCISE
   Position myPosition = sat.getPosition();

   // VERIFY
   assertUnit(myPosition == Position(0, 0));
   // TEARDOWN

}

/*************************************
  * TEST GET ANGLE : DragonCenter
  * Input: 0, 0
  * Output: 0, 0
  **************************************/
void TestDragonCenter::test_getAngle()
{
   // SETUP
   DragonCenter inertia;
   inertia.angle = Angle(100);

   // EXERCISE
   Angle myAngle = inertia.getAngle();

   // VERIFY
   assertUnit(myAngle.getDegrees() == 100);
   // TEARDOWN
}

