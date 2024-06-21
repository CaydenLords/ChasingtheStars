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
   }

private:
   Position test_getPosition();
   void test_setPosition();
   Angle test_getAngle();

};