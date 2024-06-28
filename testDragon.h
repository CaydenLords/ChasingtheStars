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
      report("Hubble");
   }

private:
   void test_getPosition();
   void test_setPosition();
   void test_getAngle();

};