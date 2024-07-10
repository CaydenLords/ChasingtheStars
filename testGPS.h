/***********************************************************************
 * Header File:
 *    Test GPS : Test the GPS class
 * Author:
 *    Ryan Donaldson
 * Summary:
 *    All the unit tests for GPS
 ************************************************************************/


#pragma once

#include "satellite.h"
#include "position.h"
#include "unitTest.h"
#include "GPS.h"

 /***************************************************
  * GPS TEST
  * Test the GPS class
  ***************************************************/
class TestGPS : public UnitTest
{
public:
   void run()
   {
      test_getPosition();
      test_setPosition();
      test_getAngle();
      report("GPS");
   }

private:
   void test_getPosition();
   void test_setPosition();
   void test_getAngle();

};