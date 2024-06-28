/***********************************************************************
 * Source File:
 *    TEST INERTIA
 * Author:
 *    Ryan Donaldson
 * Summary:
 *    The unit tests for inertia
 ************************************************************************/

#include "testInertia.h"
#include "inertia.h"
#include "position.h"
#include <cassert>

 /*************************************
   * TEST SET POSITION : Inertia
   * Input: 0, 0
   * Output: 0, 0
   **************************************/
void TestInertia::test_setPosition()
{
   // SETUP
   Inertia inertia;

   // EXERCISE
   inertia.setPosition(0, 0);

   // VERIFY
   assertUnit(inertia.pos.getMetersX() == 0);
   assertUnit(inertia.pos.getMetersY() == 0);
   // TEARDOWN

}

 /*************************************
  * TEST GET POSITION : Inertia
  * Input:
  * Output: 0, 0
  **************************************/
void TestInertia::test_getPosition()
{
   // SETUP
   Inertia inertia;
   inertia.setPosition(0, 0);

   // EXERCISE
   Position myPosition = inertia.getPosition();

   // VERIFY
   assertUnit(myPosition == Position(0, 0));
   // TEARDOWN

}

/*************************************
  * TEST GET ANGLE : Inertia
  * Input: 100
  * Output: 100.0
  **************************************/
void TestInertia::test_getAngle()
{
   // SETUP
   Position location(0, 0);
   Angle ang(100);
   Inertia inertia(location, ang);

   // EXERCISE
   Angle myAngle = inertia.getAngle();

   // VERIFY
   assertUnit(myAngle.getDegrees() == 100.0);
   // TEARDOWN
}

/*************************************
  * TEST MOVE : Inertia
  * Input: (-36515095.13, 21082000.0)
  * Output: (-36514424.0,  21081612.0)
  **************************************/
void TestInertia::test_move()
{
   // SETUP
   Inertia satellite;
   satellite.setPosition(-36515095.13, 21082000.0);

  
   // EXERCISE
   satellite.move(false, false, false);

   Position posNew = satellite.getPosition();
   // VERIFY
   assertUnit(posNew.getMetersX() == -36514424.0);
   assertUnit(posNew.getMetersY() ==  21081612.0);
   // TEARDOWN
}

/*************************************
  * TEST GRAVITY : Inertia
  * Input:
  * Output:
  **************************************/
void TestInertia::test_gravity()
{
   // SETUP


   // EXERCISE


   // VERIFY

   // TEARDOWN
}

/*************************************
  * TEST HEIGHT ABOVE EARTH : Inertia
  * Input:
  * Output:
  **************************************/
void TestInertia::test_heightAboveEarth()
{
   // SETUP


   // EXERCISE


   // VERIFY

   // TEARDOWN
}

/*************************************
  * TEST GRAVITY DIRECTION : Inertia
  * Input:
  * Output:
  **************************************/
void TestInertia::test_gravityDirection()
{
   // SETUP


   // EXERCISE


   // VERIFY

   // TEARDOWN
}

/*************************************
  * TEST GET HORIZONTAL : Inertia
  * Input:
  * Output:
  **************************************/
void TestInertia::test_getHorizontal()
{
   // SETUP


   // EXERCISE


   // VERIFY

   // TEARDOWN
}

/*************************************
  * TEST GET VERTICAL : Inertia
  * Input:
  * Output:
  **************************************/
void TestInertia::test_getVertical()
{
   // SETUP


   // EXERCISE


   // VERIFY

   // TEARDOWN
}

/*************************************
  * TEST GET DIRECTION : Inertia
  * Input:
  * Output:
  **************************************/
void TestInertia::test_getDirection()
{
   // SETUP


   // EXERCISE


   // VERIFY

   // TEARDOWN
}

/*************************************
  * TEST GET VELOCITY : Inertia
  * Input:
  * Output:
  **************************************/
void TestInertia::test_getVelocity()
{
   // SETUP


   // EXERCISE


   // VERIFY

   // TEARDOWN
}