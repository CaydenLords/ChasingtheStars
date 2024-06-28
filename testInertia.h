/***********************************************************************
 * Header File:
 *    Test Inertia : Test the Inertia class
 * Author:
 *    Ryan Donaldson
 * Summary:
 *    All the unit tests for Inertia
 ************************************************************************/


#pragma once

#include "inertia.h"
#include "position.h"
#include "unitTest.h"

 /***************************************************
  * INERTIA TEST
  * Test the INERTIA class
  ***************************************************/
class TestInertia : public UnitTest
{
public:
   void run()
   {
      test_getPosition();
      test_setPosition();
      test_getAngle();
      test_move();
      test_gravity();
      test_heightAboveEarth();
      test_gravityDirection();
      test_getHorizontal();
      test_getVertical();
      test_getDirection();
      test_getVelocity();
      report("Intertia");
   }

private:
   void test_getPosition();
   void test_setPosition();
   void test_getAngle();
   void test_move();
   void test_gravity();
   void test_heightAboveEarth();
   void test_gravityDirection();
   void test_getHorizontal();
   void test_getVertical();
   void test_getDirection();
   void test_getVelocity();

};