/***********************************************************************
 * Header File:
 *    Test Dragon : Test the Dragon class
 * Author:
 *    Ryan Donaldson
 * Summary:
 *    All the unit tests for Dragon
 ************************************************************************/


#pragma once

#include "satellite.h"
#include "position.h"
#include "unitTest.h"
#include "dragon.h"

 /***************************************************
  * DRAGON TEST
  * Test the DRAGON class
  ***************************************************/
class TestDragon : public UnitTest
{
public:
   void run()
   {
      test_getPosition();
      test_setPosition();
      test_getAngle();
      test_collide();
      report("Dragon");
   }

private:
   void test_getPosition();
   void test_setPosition();
   void test_getAngle();
   void test_collide();
};