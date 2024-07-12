/***********************************************************************
 * Source File:
 *    TEST HubbleRight
 * Author:
 *    Cayden Lords
 * Summary:
 *    The unit tests for HubbleRight satellite
 ************************************************************************/

#include "testHubbleRight.h"
#include "inertia.h"
#include "position.h"
#include <cassert>

 /*************************************
   * TEST SET POSITION : HubbleRight
   * Input: 0, 0
   * Output: 0, 0
   **************************************/
void TestHubbleRight::test_setPosition()
{
   // SETUP
   HubbleRight sat;

   // EXERCISE
   sat.setPosition(0, 0);

   // VERIFY
   assertUnit(sat.pos.getMetersX() == 0);
   assertUnit(sat.pos.getMetersY() == 0);
   // TEARDOWN

}

/*************************************
 * TEST GET POSITION : HubbleRight
 * Input:
 * Output: 0, 0
 **************************************/
void TestHubbleRight::test_getPosition()
{
   // SETUP
   HubbleRight sat;
   sat.pos = Position(0, 0);

   // EXERCISE
   Position myPosition = sat.getPosition();

   // VERIFY
   assertUnit(myPosition == Position(0, 0));
   // TEARDOWN

}

/*************************************
  * TEST GET ANGLE : HubbleRight
  * Input: 0, 0
  * Output: 0, 0
  **************************************/
void TestHubbleRight::test_getAngle()
{
   // SETUP
   HubbleRight inertia;
   inertia.angle = Angle(100);

   // EXERCISE
   Angle myAngle = inertia.getAngle();

   // VERIFY
   assertUnit(myAngle.getDegrees() == 100);
   // TEARDOWN
}

