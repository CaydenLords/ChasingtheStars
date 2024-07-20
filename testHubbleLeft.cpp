/***********************************************************************
 * Source File:
 *    TEST HubbleLeft
 * Author:
 *    Cayden Lords
 * Summary:
 *    The unit tests for HubbleLeft satellite
 ************************************************************************/

#include "testHubbleLeft.h"
#include "inertia.h"
#include "position.h"
#include <cassert>

 /*************************************
   * TEST SET POSITION : HubbleLeft
   * Input: 0, 0
   * Output: 0, 0
   **************************************/
void TestHubbleLeft::test_setPosition()
{
   // SETUP
   HubbleLeft sat;

   // EXERCISE
   sat.setPosition(0, 0);

   // VERIFY
   assertUnit(sat.pos == Position(0, 0));
   // TEARDOWN

}

/*************************************
 * TEST GET POSITION : HubbleLeft
 * Input:
 * Output: 0, 0
 **************************************/
void TestHubbleLeft::test_getPosition()
{
   // SETUP
   HubbleLeft sat;
   sat.pos = Position(0, 0);

   // EXERCISE
   Position myPosition = sat.getPosition();

   // VERIFY
   assertUnit(myPosition == Position(0, 0));
   // TEARDOWN

}

/*************************************
  * TEST GET ANGLE : HubbleLeft
  * Input: 0, 0
  * Output: 0, 0
  **************************************/
void TestHubbleLeft::test_getAngle()
{
   // SETUP
   HubbleLeft inertia;
   inertia.angle = Angle(100);

   // EXERCISE
   Angle myAngle = inertia.getAngle();

   // VERIFY
   assertUnit(myAngle.getDegrees() == 100);
   // TEARDOWN
}

/*************************************
  * TEST COLLIDE : HUBBLELEFT
  * Input: Collision scenario
  * Output: List of new objects
  **************************************/
void TestHubbleLeft::test_collide()
{
   // SETUP
   HubbleLeft module(Position(1000, 1000), Angle(100), 0, Position(200, 200), 2);
   std::vector<Collidable*> myObjects;

   // EXERCISE
   myObjects = module.collide();

   // VERIFY
   assertUnit(myObjects.size() == 2);
   // TEARDOWN
}