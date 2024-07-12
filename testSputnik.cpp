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
#include "satellite.h"
#include <cassert>

 /*************************************
   * TEST SET POSITION : Sputnik
   * Input: 0, 0
   * Output: 0, 0
   **************************************/
void TestSputnik::test_setPosition()
{
   // SETUP
   Sputnik sat;

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
   Sputnik sat;
   sat.pos = Position(0, 0);

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
   Sputnik inertia;
   inertia.angle = Angle(100);

   // EXERCISE
   Angle myAngle = inertia.getAngle();

   // VERIFY
   assertUnit(myAngle.getDegrees() == 100);
   // TEARDOWN
}

/*************************************
  * TEST COLLIDE : Sputnik
  * Input: 0, 0
  * Output: 0, 0
  **************************************/
void TestSputnik::test_collide()
{
   // SETUP
   Sputnik probe(Position(1000, 1000), Angle(100), 0, Position(200, 200), 4);
   std::vector<Collidable> myObjects;

   // EXERCISE
   myObjects = probe.collide();

   // VERIFY
   assertUnit(myObjects.size() == 4);
   // TEARDOWN
}
