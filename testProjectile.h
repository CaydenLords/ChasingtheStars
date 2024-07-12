/***********************************************************************
 * Header File:
 *    Test Projectile : Test the Projectile class
 * Author:
 *    Cayden Lords
 * Summary:
 *    All the unit tests for Projectile
 ************************************************************************/


#pragma once

#include "projectile.h"
#include "position.h"
#include "unitTest.h"

 /***************************************************
  * INERTIA TEST
  * Test the INERTIA class
  ***************************************************/
class TestProjectile : public UnitTest
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
      test_despawn();
      test_no_despawn();
      report("Projectile");
   }

private:
   void test_getPosition();
   void test_setPosition();
   void test_getAngle();
   void test_move1();
   void test_move2();
   void test_move0();
   void test_despawn();
   void test_no_despawn();
}; 