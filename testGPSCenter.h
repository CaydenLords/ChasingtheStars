/***********************************************************************
 * Header File:
 *    Test GPSCenter : Test the GPSCenter class
 * Author:
 *    Cayden Lords
 * Summary:
 *    All the unit tests for GPSCenter
 ************************************************************************/


#pragma once

#include "satellite.h"
#include "position.h"
#include "unitTest.h"
#include "GPSCenter.h"

 /***************************************************
  * GPSCenter TEST
  * Test the GPSCenter class
  ***************************************************/
class TestGPSCenter : public UnitTest
{
public:
   void run()
   {
      test_getPosition();
      test_setPosition();
      test_getAngle();
      report("GPSCenter");
   }

private:
   void test_getPosition();
   void test_setPosition();
   void test_getAngle();

};