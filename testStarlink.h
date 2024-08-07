/***********************************************************************
 * Header File:
 *    Test Starlink : Test the Starlink class
 * Author:
 *    Ryan Donaldson
 * Summary:
 *    All the unit tests for Starlink
 ************************************************************************/


#pragma once

#include "satellite.h"
#include "position.h"
#include "unitTest.h"
#include "starlink.h"

 /***************************************************
  * STARLINK TEST
  * Test the Starlink class
  ***************************************************/
class TestStarlink : public UnitTest
{
public:
   void run()
   {
      test_getPosition();
      test_setPosition();
      test_getAngle();
      test_collide();
      report("Starlink");
   }

private:
   void test_getPosition();
   void test_setPosition();
   void test_getAngle();
   void test_collide();
};