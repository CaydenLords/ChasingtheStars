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
#include "hubble.h"

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
      test_collide();
      report("Hubble");
   }

private:
   void test_getPosition();
   void test_setPosition();
   void test_getAngle();
   void test_collide();

};