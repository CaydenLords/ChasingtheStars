/***********************************************************************
 * Source File:
 *    TEST HubbleScope
 * Author:
 *    Cayden Lords
 * Summary:
 *    The unit tests for HubbleScope satellite
 ************************************************************************/

#include "testHubbleScope.h"
#include "inertia.h"
#include "position.h"
#include <cassert>

 /*************************************
   * TEST SET POSITION : HubbleScope
   * Input: 0, 0
   * Output: 0, 0
   **************************************/
void TestHubbleScope::test_setPosition()
{
   // SETUP
   HubbleScope sat;

   // EXERCISE
   sat.setPosition(0, 0);

   // VERIFY
   assertUnit(sat.pos.getMetersX() == 0);
   assertUnit(sat.pos.getMetersY() == 0);
   // TEARDOWN

}

/*************************************
 * TEST GET POSITION : HubbleScope
 * Input:
 * Output: 0, 0
 **************************************/
void TestHubbleScope::test_getPosition()
{
   // SETUP
   HubbleScope sat;
   sat.pos = Position(0, 0);

   // EXERCISE
   Position myPosition = sat.getPosition();

   // VERIFY
   assertUnit(myPosition == Position(0, 0));
   // TEARDOWN

}

/*************************************
  * TEST GET ANGLE : HubbleScope
  * Input: 0, 0
  * Output: 0, 0
  **************************************/
void TestHubbleScope::test_getAngle()
{
   // SETUP
   HubbleScope inertia;
   inertia.angle = Angle(100);

   // EXERCISE
   Angle myAngle = inertia.getAngle();

   // VERIFY
   assertUnit(myAngle.getDegrees() == 100);
   // TEARDOWN
}

/*************************************
  * TEST COLLIDE : HUBBLESCOPE
  * Input: Collision scenario
  * Output: List of new objects
  **************************************/
void TestHubbleScope::test_collide()
{
   // SETUP
   HubbleScope module(Position(1000, 1000), Angle(100), 0, Position(200, 200), 3);
   std::vector<Collidable*> myObjects;

   // EXERCISE
   myObjects = module.collide();

   // VERIFY
   assertUnit(myObjects.size() == 3);
   // TEARDOWN
}