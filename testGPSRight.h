/***********************************************************************
 * Header File:
 *    Test GPSRight : Test the GPSRight class
 * Author:
 *    Cayden Lords
 * Summary:
 *    All the unit tests for GPSRight
 ************************************************************************/


#pragma once

#include "satellite.h"
#include "position.h"
#include "unitTest.h"
#include "GPSRight.h"

 /***************************************************
  * GPSRight TEST
  * Test the GPSRight class
  ***************************************************/
class TestGPSRight : public UnitTest
{
public:
   void run()
   {
      test_getPosition();
      test_setPosition();
      test_getAngle();
      test_collide();
      report("GPSRight");
   }

private:
   void test_getPosition();
   void test_setPosition();
   void test_getAngle();
   void test_collide();

};