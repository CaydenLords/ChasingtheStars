/***********************************************************************
 * Source File:
 *    TEST HUBBLE
 * Author:
 *    Ryan Donaldson
 * Summary:
 *    The unit tests for Hubble satellite
 ************************************************************************/

#include "testHubble.h"
#include "inertia.h"
#include "position.h"
#include <cassert>

 /*************************************
   * TEST SET POSITION : Hubble
   * Input: 0, 0
   * Output: 0, 0
   **************************************/
void TestHubble::test_setPosition()
{
   // SETUP
   Hubble sat;

   // EXERCISE
   sat.setPosition(0, 0);

   // VERIFY
   assertUnit(sat.pos.getMetersX() == 0);
   assertUnit(sat.pos.getMetersY() == 0);
   // TEARDOWN

}

/*************************************
 * TEST GET POSITION : Hubble
 * Input:
 * Output: 0, 0
 **************************************/
void TestHubble::test_getPosition()
{
   // SETUP
   Hubble sat;
   sat.pos = Position(0, 0);

   // EXERCISE
   Position myPosition = sat.getPosition();

   // VERIFY
   assertUnit(myPosition == Position(0, 0));
   // TEARDOWN

}

/*************************************
  * TEST GET ANGLE : Hubble
  * Input: 0, 0
  * Output: 0, 0
  **************************************/
void TestHubble::test_getAngle()
{
   // SETUP
   Hubble inertia;
   inertia.angle = Angle(100);

   // EXERCISE
   Angle myAngle = inertia.getAngle();

   // VERIFY
   assertUnit(myAngle.getDegrees() == 100);
   // TEARDOWN
}

