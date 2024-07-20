/***********************************************************************
 * Source File:
 *    TEST DragonLeft
 * Author:
 *    Cayden Lords
 * Summary:
 *    The unit tests for DragonLeft satellite
 ************************************************************************/

#include "testDragonLeft.h"
#include "inertia.h"
#include "position.h"
#include <cassert>

 /*************************************
   * TEST SET POSITION : DragonLeft
   * Input: 0, 0
   * Output: 0, 0
   **************************************/
void TestDragonLeft::test_setPosition()
{
   // SETUP
   DragonLeft sat;

   // EXERCISE
   sat.setPosition(0, 0);

   // VERIFY
   assertUnit(sat.pos == Position(0, 0));
   // TEARDOWN

}

/*************************************
 * TEST GET POSITION : DragonLeft
 * Input:
 * Output: 0, 0
 **************************************/
void TestDragonLeft::test_getPosition()
{
   // SETUP
   DragonLeft sat;
   sat.pos = Position(0, 0);

   // EXERCISE
   Position myPosition = sat.getPosition();

   // VERIFY
   assertUnit(myPosition == Position(0, 0));
   // TEARDOWN

}

/*************************************
  * TEST GET ANGLE : DragonLeft
  * Input: 0, 0
  * Output: 0, 0
  **************************************/
void TestDragonLeft::test_getAngle()
{
   // SETUP
   DragonLeft inertia;
   inertia.angle = Angle(100);

   // EXERCISE
   Angle myAngle = inertia.getAngle();

   // VERIFY
   assertUnit(myAngle.getDegrees() == 100);
   // TEARDOWN
}

/*************************************
  * TEST COLLIDE : DRAGONLEFT
  * Input: Collision scenario
  * Output: List of new objects
  **************************************/
void TestDragonLeft::test_collide()
{
   // SETUP
   DragonLeft module(Position(1000, 1000), Angle(100), 0, Position(200, 200), 2);
   std::vector<Collidable*> myObjects;

   // EXERCISE
   myObjects = module.collide();

   // VERIFY
   assertUnit(myObjects.size() == 2);
   // TEARDOWN
}