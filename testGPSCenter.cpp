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

/*************************************
  * TEST COLLIDE : GPSCENTER
  * Input: Collision scenario
  * Output: List of new objects
  **************************************/
void TestGPSCenter::test_collide()
{
   // SETUP
   GPSCenter module(Position(1000, 1000), Angle(100), 0, Position(200, 200), 3);
   std::vector<Collidable*> myObjects;

   // EXERCISE
   myObjects = module.collide();

   // VERIFY
   assertUnit(myObjects.size() == 3);
   // TEARDOWN
}

