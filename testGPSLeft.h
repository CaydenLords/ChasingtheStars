/***********************************************************************
 * Header File:
 *    Test GPSLeft : Test the GPSLeft class
 * Author:
 *    Cayden Lords
 * Summary:
 *    All the unit tests for GPSLeft
 ************************************************************************/


#pragma once

#include "satellite.h"
#include "position.h"
#include "unitTest.h"
#include "GPSLeft.h"

 /***************************************************
  * GPSLeft TEST
  * Test the GPSLeft class
  ***************************************************/
class TestGPSLeft : public UnitTest
{
public:
   void run()
   {
      test_getPosition();
      test_setPosition();
      test_getAngle();
      report("GPSLeft");
   }

private:
   void test_getPosition();
   void test_setPosition();
   void test_getAngle();

};