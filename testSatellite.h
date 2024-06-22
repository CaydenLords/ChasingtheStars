/***********************************************************************
 * Header File:
 *    Test Satellite : Test the Satellite class
 * Author:
 *    Ryan Donaldson
 * Summary:
 *    All the unit tests for Satellite
 ************************************************************************/


#pragma once

#include "satellite.h"
#include "position.h"
#include "unitTest.h"

 /***************************************************
  * INERTIA TEST
  * Test the INERTIA class
  ***************************************************/
class TestSatellite : public UnitTest
{
public:
   void run()
   {
      test_getPosition();
      test_setPosition();
      test_getAngle();
   }

private:
   void test_getPosition();
   void test_setPosition();
   void test_getAngle();

};