/***********************************************************************
 * Source File:
 *    TEST SPUTNIK
 * Author:
 *    Ryan Donaldson
 * Summary:
 *    The unit tests for Sputnik satellite
 ************************************************************************/

#include "testSputnik.h"
#include "inertia.h"
#include "position.h"
#include <cassert>

 /*************************************
   * TEST SET POSITION : Sputnik
   * Input: 0, 0
   * Output: 0, 0
   **************************************/
void TestSputnik::test_setPosition()
{
   // SETUP
   Satellite sat;

   // EXERCISE
   sat.setPosition(0, 0);

   // VERIFY
   assertUnit(sat.pos.getMetersX() == 0);
   assertUnit(sat.pos.getMetersY() == 0);
   // TEARDOWN

}

/*************************************
 * TEST GET POSITION : Sputnik
 * Input:
 * Output: 0, 0
 **************************************/
void TestSputnik::test_getPosition()
{
   // SETUP
   Satellite sat;
   sat.setPosition(0, 0);

   // EXERCISE
   Position myPosition = sat.getPosition();

   // VERIFY
   assertUnit(myPosition == Position(0, 0));
   // TEARDOWN

}

/*************************************
  * TEST GET ANGLE : Sputnik
  * Input: 0, 0
  * Output: 0, 0
  **************************************/
void TestSputnik::test_getAngle()
{
   // SETUP
   Position location(0, 0);
   Angle ang(100);
   Inertia inertia(location, ang);

   // EXERCISE
   Angle myAngle = inertia.getAngle();

   // VERIFY
   assertUnit(myAngle.getDegrees() == 100);
   // TEARDOWN
}