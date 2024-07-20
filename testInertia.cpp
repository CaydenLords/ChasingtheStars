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
   assertUnit(inertia.pos == Position(0, 0));
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
   inertia.pos = Position(0, 0);

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
   Inertia inertia;
   inertia.angle = Angle(100);

   // EXERCISE
   Angle myAngle = inertia.getAngle();

   // VERIFY
   assertUnit(myAngle.getDegrees() == 100);
   // TEARDOWN
}

/*************************************
  * TEST MOVE 1 : Inertia
  * Input: (-36515095.13, 21082000.0)
  * Output: (-36514424.0,  21081612.0)
  **************************************/
void TestInertia::test_move1()
{
   // SETUP
   Inertia satellite;
   satellite.pos = Position(-36515095.13, 21082000.0);

  
   // EXERCISE
   satellite.move(false, false, false);

   Position posNew = satellite.getPosition();
   // VERIFY
   assertUnit(posNew == Position(-36514424.0, 21081612.0));
   // TEARDOWN
}

/*************************************
  * TEST MOVE 2 : Inertia
  * Input: (10000000.0, 10000000.0)
  * Output: (9995125.0,  9995125.0)
  **************************************/
void TestInertia::test_move2()
{
   // SETUP
   Inertia satellite;
   satellite.pos = Position(10000000.0, 10000000.0);

   // EXERCISE
   satellite.move(false, false, false);

   Position posNew = satellite.getPosition();
   // VERIFY
   assertUnit(posNew == Position(9995125.0, 9995125.0));
   // TEARDOWN
}

/*************************************
  * TEST MOVE 0 : Inertia
  * Input: (0.0, 0.0)
  * Output: (0.0,  8472.9)
  **************************************/
void TestInertia::test_move0()
{
   // SETUP
   Inertia satellite;
   satellite.pos = Position(0.0, 0.0);
   
   // EXERCISE
   satellite.move(false, false, false);
   
   Position posNew = satellite.getPosition();
   // VERIFY
   assertUnit(posNew.getMetersX() == 0.0);
   assertUnit(round(posNew.getMetersY()) == 8473.0);
   // TEARDOWN
}