/***********************************************************************
 * Header File:
 *    Test HubbleComputer : Test the HubbleComputer class
 * Author:
 *    Cayden Lords
 * Summary:
 *    All the unit tests for HubbleComputer
 ************************************************************************/


#pragma once

#include "satellite.h"
#include "position.h"
#include "unitTest.h"
#include "HubbleComputer.h"

 /***************************************************
  * HubbleComputer TEST
  * Test the HubbleComputer class
  ***************************************************/
class TestHubbleComputer : public UnitTest
{
public:
   void run()
   {
      test_getPosition();
      test_setPosition();
      test_getAngle();
      report("HubbleComputer");
   }

private:
   void test_getPosition();
   void test_setPosition();
   void test_getAngle();

};