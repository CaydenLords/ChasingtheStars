/***********************************************************************
 * Source File:
 *    TEST STARLINK
 * Author:
 *    Ryan Donaldson
 * Summary:
 *    The unit tests for Starlink satellite
 ************************************************************************/

#include "testStarlink.h"
#include "inertia.h"
#include "position.h"
#include <cassert>

 /*************************************
   * TEST SET POSITION : Starlink
   * Input: 0, 0
   * Output: 0, 0
   **************************************/
void TestStarlink::test_setPosition()
{
   // SETUP
   Starlink sat;

   // EXERCISE
   sat.setPosition(0, 0);

   // VERIFY
   assertUnit(sat.pos == Position(0, 0));
   // TEARDOWN

}

/*************************************
 * TEST GET POSITION : Starlink
 * Input:
 * Output: 0, 0
 **************************************/
void TestStarlink::test_getPosition()
{
   // SETUP
   Starlink sat;
   sat.pos = Position(0, 0);

   // EXERCISE
   Position myPosition = sat.getPosition();

   // VERIFY
   assertUnit(myPosition == Position(0, 0));
   // TEARDOWN

}

/*************************************
  * TEST GET ANGLE : Starlink
  * Input: 0, 0
  * Output: 0, 0
  **************************************/
void TestStarlink::test_getAngle()
{
   // SETUP
   Starlink inertia;
   inertia.angle = Angle(100);

   // EXERCISE
   Angle myAngle = inertia.getAngle();

   // VERIFY
   assertUnit(myAngle.getDegrees() == 100);
   // TEARDOWN
}

/*************************************
  * TEST COLLIDE : STARLINK
  * Input: Collision scenario
  * Output: List of new objects
  **************************************/
void TestStarlink::test_collide()
{
   // SETUP
   Starlink module(Position(1000, 1000), Angle(100), 6, Position(200, 200), 2);
   std::vector<Collidable*> myObjects;

   // EXERCISE
   myObjects = module.collide();

   // VERIFY
   assertUnit(myObjects.size() == 4);
   // TEARDOWN
}