/***********************************************************************
 * Header File:
 *    Test Sputnik : Test the Sputnik class
 * Author:
 *    Ryan Donaldson
 * Summary:
 *    All the unit tests for Sputnik
 ************************************************************************/


#pragma once

#include "satellite.h"
#include "position.h"
#include "unitTest.h"

 /***************************************************
  * INERTIA TEST
  * Test the INERTIA class
  ***************************************************/
class TestSputnik : public UnitTest
{
public:
   void run()
   {
      test_getPosition();
      test_setPosition();
      test_getAngle();
      report("Sputnik");
   }

private:
   void test_getPosition();
   void test_setPosition();
   void test_getAngle();

};