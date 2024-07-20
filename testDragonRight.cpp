/***********************************************************************
 * Source File:
 *    TEST DragonRight
 * Author:
 *    Cayden Lords
 * Summary:
 *    The unit tests for DragonRight satellite
 ************************************************************************/

#include "testDragonRight.h"
#include "inertia.h"
#include "position.h"
#include <cassert>

 /*************************************
   * TEST SET POSITION : DragonRight
   * Input: 0, 0
   * Output: 0, 0
   **************************************/
void TestDragonRight::test_setPosition()
{
   // SETUP
   DragonRight sat;

   // EXERCISE
   sat.setPosition(0, 0);

   // VERIFY
   assertUnit(sat.pos == Position(0, 0));
   // TEARDOWN

}

/*************************************
 * TEST GET POSITION : DragonRight
 * Input:
 * Output: 0, 0
 **************************************/
void TestDragonRight::test_getPosition()
{
   // SETUP
   DragonRight sat;
   sat.pos = Position(0, 0);

   // EXERCISE
   Position myPosition = sat.getPosition();

   // VERIFY
   assertUnit(myPosition == Position(0, 0));
   // TEARDOWN

}

/*************************************
  * TEST GET ANGLE : DragonRight
  * Input: 0, 0
  * Output: 0, 0
  **************************************/
void TestDragonRight::test_getAngle()
{
   // SETUP
   DragonRight inertia;
   inertia.angle = Angle(100);

   // EXERCISE
   Angle myAngle = inertia.getAngle();

   // VERIFY
   assertUnit(myAngle.getDegrees() == 100);
   // TEARDOWN
}

/*************************************
  * TEST COLLIDE : DRAGONRIGHT
  * Input: Collision scenario
  * Output: List of new objects
  **************************************/
void TestDragonRight::test_collide()
{
   // SETUP
   DragonRight module(Position(1000, 1000), Angle(100), 0, Position(200, 200), 2);
   std::vector<Collidable*> myObjects;

   // EXERCISE
   myObjects = module.collide();

   // VERIFY
   assertUnit(myObjects.size() == 2);
   // TEARDOWN
}