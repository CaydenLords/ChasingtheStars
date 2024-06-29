/***********************************************************************
 * Source File:
 *    TEST CHASER
 * Author:
 *    Cayden Lords
 * Summary:
 *    The unit tests for chaser
 ************************************************************************/

#include "testChaser.h"
#include "chaser.h"
#include "position.h"
#include <cassert>

 /*************************************
   * TEST SET POSITION : Chaser
   * Input: 0, 0
   * Output: 0, 0
   **************************************/
void TestChaser::test_setPosition()
{
   // SETUP
   Chaser chaser;

   // EXERCISE
   chaser.setPosition(0, 0);

   // VERIFY
   assertUnit(chaser.pos.getMetersX() == 0);
   assertUnit(chaser.pos.getMetersY() == 0);
   // TEARDOWN

}

/*************************************
 * TEST GET POSITION : Chaser
 * Input:
 * Output: 0, 0
 **************************************/
void TestChaser::test_getPosition()
{
   // SETUP
   Chaser chaser;
   chaser.setPosition(0, 0);

   // EXERCISE
   Position myPosition = chaser.getPosition();

   // VERIFY
   assertUnit(myPosition == Position(0, 0));
   // TEARDOWN

}

/*************************************
  * TEST GET ANGLE : Chaser
  * Input: 100
  * Output: 100.0
  **************************************/
void TestChaser::test_getAngle()
{
   // SETUP
   Position location(0, 0);
   Angle ang(100);
   Chaser chaser(location, ang, 10, location);

   // EXERCISE
   Angle myAngle = chaser.getAngle();

   // VERIFY
   assertUnit(myAngle.getDegrees() == 100.0);
   // TEARDOWN
}

/*************************************
  * TEST MOVE 1 : Chaser
  * Input: (-36515095.13, 21082000.0)
  * Output: (-36514424.0,  21081612.0)
  **************************************/
void TestChaser::test_move1()
{
   // SETUP
   Chaser chaser;
   chaser.setPosition(-36515095.13, 21082000.0);


   // EXERCISE
   chaser.move(false, false, false);

   Position posNew = chaser.getPosition();
   // VERIFY
   assertUnit(posNew.getMetersX() == -36514424.0);
   assertUnit(posNew.getMetersY() == 21081612.0);
   // TEARDOWN
}

/*************************************
  * TEST MOVE 2 : Chaser
  * Input: (10000000.0, 10000000.0)
  * Output: (9995125.0,  9995125.0)
  **************************************/
void TestChaser::test_move2()
{
   // SETUP
   Chaser chaser;
   chaser.setPosition(10000000.0, 10000000.0);

   // EXERCISE
   chaser.move(false, false, false);

   Position posNew = chaser.getPosition();
   // VERIFY
   assertUnit(posNew.getMetersX() == 9995125.0);
   assertUnit(posNew.getMetersY() == 9995125.0);
   // TEARDOWN
}

/*************************************
  * TEST MOVE 0 : Chaser
  * Input: (0.0, 0.0)
  * Output: (0.0,  8472.9)
  **************************************/
void TestChaser::test_move0()
{
   // SETUP
   Chaser chaser;
   chaser.setPosition(0.0, 0.0);

   // EXERCISE
   chaser.move(false, false, false);

   Position posNew = chaser.getPosition();
   // VERIFY
   assertUnit(posNew.getMetersX() == 0.0);
   assertUnit(round(posNew.getMetersY()) == 8473.0);
   // TEARDOWN
}

/*************************************
  * TEST TURN LEFT : Chaser
  * Input: 1, turn left
  * Output: 0.9 radians
  **************************************/

void TestChaser::test_turnLeft()
{
   // SETUP
   Position location(0, 0);
   Angle ang;
   ang.setRadians(1);
   Chaser chaser(location, ang, 10, location);
   // EXERCISE
   chaser.move(true, false, false);
   // VERIFY
   assertEquals(chaser.angle.getRadians(), .9);
   // TEARDOWN
}

/*************************************
  * TEST TURN RIGHT : Chaser
  * Input: 0, turn right
  * Output: 0.1 radians
  **************************************/

void TestChaser::test_turnRight()
{
   // SETUP
   Position location(0, 0);
   Angle ang;
   ang.setRadians(0);
   Chaser chaser(location, ang, 10, location);
   // EXERCISE
   chaser.move(false, true, false);
   // VERIFY
   assertEquals(chaser.angle.getRadians(), 0.1);
   // TEARDOWN
}

/*************************************
  * TEST THRUST Chaser
  * Input: (0, 0), Angle(0), Thrust
  * Output: (0, 15385)
  **************************************/

void TestChaser::test_thrust()
{
   // SETUP
   Chaser chaser;
   chaser.setPosition(0.0, 0.0);

   // EXERCISE
   chaser.move(false, false, true);

   Position posNew = chaser.getPosition();
   // VERIFY
   assertUnit(posNew.getMetersX() == 0.0);
   assertUnit(round(posNew.getMetersY()) == 15385.0);
   // TEARDOWN
}