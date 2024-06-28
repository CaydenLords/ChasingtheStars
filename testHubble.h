/***********************************************************************
 * Header File:
 *    Test Hubble : Test the Hubble class
 * Author:
 *    Ryan Donaldson
 * Summary:
 *    All the unit tests for Hubble
 ************************************************************************/


#pragma once

#include "satellite.h"
#include "position.h"
#include "unitTest.h"

 /***************************************************
  * HUBBLE TEST
  * Test the HUBBLE class
  ***************************************************/
class TestHubble : public UnitTest
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