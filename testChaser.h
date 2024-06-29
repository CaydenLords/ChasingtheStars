/***********************************************************************
 * Header File:
 *    Test Inertia : Test the Chaser class
 * Author:
 *    Cayden Lords
 * Summary:
 *    All the unit tests for the player ship
 ************************************************************************/


#pragma once

#include "inertia.h"
#include "position.h"
#include "unitTest.h"

 /***************************************************
  * INERTIA TEST
  * Test the INERTIA class
  ***************************************************/
class TestChaser : public UnitTest
{
public:
   void run()
   {
      test_getPosition();
      test_setPosition();
      test_getAngle();
      test_move1();
      test_move2();
      test_move0();
      test_turnLeft();
      test_turnRight();
      test_thrust();
      report("Chaser");
   }

private:
   void test_getPosition();
   void test_setPosition();
   void test_getAngle();
   void test_move1();
   void test_move2();
   void test_move0();
   void test_turnLeft();
   void test_turnRight();
   void test_thrust();
};