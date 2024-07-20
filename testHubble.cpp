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
   assertUnit(sat.pos == Position(0, 0));
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

/*************************************
  * TEST COLLIDE : HUBBLE
  * Input: Collision scenario
  * Output: List of new objects
  **************************************/
void TestHubble::test_collide()
{
   // SETUP
   Hubble module(Position(1000, 1000), Angle(100), 0, Position(200, 200), 0);
   std::vector<Collidable*> myObjects;

   // EXERCISE
   myObjects = module.collide();

   // VERIFY
   assertUnit(myObjects.size() == 4);
   // TEARDOWN
}
