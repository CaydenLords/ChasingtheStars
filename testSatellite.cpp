/***********************************************************************
 * Source File:
 *    TEST SATELLITE
 * Author:
 *    Ryan Donaldson
 * Summary:
 *    The unit tests for satellite
 ************************************************************************/

#include "testSatellite.h"
#include "inertia.h"
#include "position.h"
#include <cassert>

 /*************************************
   * TEST SET POSITION : Satellite
   * Input: 0, 0
   * Output: 0, 0
   **************************************/
void TestSatellite::test_setPosition()
{
   // SETUP
   Satellite sat;

   // EXERCISE
   sat.setPosition(0, 0);

   // VERIFY
   assertUnit(sat.pos == Position(0, 0));
   // TEARDOWN

}

/*************************************
 * TEST GET POSITION : Satellite
 * Input:
 * Output: 0, 0
 **************************************/
void TestSatellite::test_getPosition()
{
   // SETUP
   Satellite sat;
   sat.pos = Position(0, 0);

   // EXERCISE
   Position myPosition = sat.getPosition();

   // VERIFY
   assertUnit(myPosition == Position(0, 0));
   // TEARDOWN

}

/*************************************
  * TEST GET ANGLE : Satellite
  * Input: 0, 0
  * Output: 0, 0
  **************************************/
void TestSatellite::test_getAngle()
{
   // SETUP
   Satellite inertia;
   inertia.angle = Angle(100);

   // EXERCISE
   Angle myAngle = inertia.getAngle();

   // VERIFY
   assertUnit(myAngle.getDegrees() == 100);
   // TEARDOWN
}