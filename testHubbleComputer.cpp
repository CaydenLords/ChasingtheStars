/***********************************************************************
 * Source File:
 *    TEST HubbleComputer
 * Author:
 *    Cayden Lords
 * Summary:
 *    The unit tests for HubbleComputer satellite
 ************************************************************************/

#include "testHubbleComputer.h"
#include "inertia.h"
#include "position.h"
#include <cassert>

 /*************************************
   * TEST SET POSITION : HubbleComputer
   * Input: 0, 0
   * Output: 0, 0
   **************************************/
void TestHubbleComputer::test_setPosition()
{
   // SETUP
   HubbleComputer sat;

   // EXERCISE
   sat.setPosition(0, 0);

   // VERIFY
   assertUnit(sat.pos.getMetersX() == 0);
   assertUnit(sat.pos.getMetersY() == 0);
   // TEARDOWN

}

/*************************************
 * TEST GET POSITION : HubbleComputer
 * Input:
 * Output: 0, 0
 **************************************/
void TestHubbleComputer::test_getPosition()
{
   // SETUP
   HubbleComputer sat;
   sat.pos = Position(0, 0);

   // EXERCISE
   Position myPosition = sat.getPosition();

   // VERIFY
   assertUnit(myPosition == Position(0, 0));
   // TEARDOWN

}

/*************************************
  * TEST GET ANGLE : HubbleComputer
  * Input: 0, 0
  * Output: 0, 0
  **************************************/
void TestHubbleComputer::test_getAngle()
{
   // SETUP
   HubbleComputer inertia;
   inertia.angle = Angle(100);

   // EXERCISE
   Angle myAngle = inertia.getAngle();

   // VERIFY
   assertUnit(myAngle.getDegrees() == 100);
   // TEARDOWN
}

