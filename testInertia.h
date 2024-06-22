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
      report("Intertia");
   }

private:
   void test_getPosition();
   void test_setPosition();
   void test_getAngle();

};