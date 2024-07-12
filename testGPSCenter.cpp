/***********************************************************************
 * Source File:
 *    TEST GPSCenter
 * Author:
 *    Cayden Lords
 * Summary:
 *    The unit tests for GPSCenter satellite
 ************************************************************************/

#include "testGPSCenter.h"
#include "inertia.h"
#include "position.h"
#include <cassert>

 /*************************************
   * TEST SET POSITION : GPSCenter
   * Input: 0, 0
   * Output: 0, 0
   **************************************/
void TestGPSCenter::test_setPosition()
{
   // SETUP
   GPSCenter sat;

   // EXERCISE
   sat.setPosition(0, 0);

   // VERIFY
   assertUnit(sat.pos.getMetersX() == 0);
   assertUnit(sat.pos.getMetersY() == 0);
   // TEARDOWN

}

/*************************************
 * TEST GET POSITION : GPSCenter
 * Input:
 * Output: 0, 0
 **************************************/
void TestGPSCenter::test_getPosition()
{
   // SETUP
   GPSCenter sat;
   sat.pos = Position(0, 0);

   // EXERCISE
   Position myPosition = sat.getPosition();

   // VERIFY
   assertUnit(myPosition == Position(0, 0));
   // TEARDOWN

}

/*************************************
  * TEST GET ANGLE : GPSCenter
  * Input: 0, 0
  * Output: 0, 0
  **************************************/
void TestGPSCenter::test_getAngle()
{
   // SETUP
   GPSCenter inertia;
   inertia.angle = Angle(100);

   // EXERCISE
   Angle myAngle = inertia.getAngle();

   // VERIFY
   assertUnit(myAngle.getDegrees() == 100);
   // TEARDOWN
}

