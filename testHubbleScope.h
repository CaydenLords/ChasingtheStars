/***********************************************************************
 * Header File:
 *    Test HubbleScope : Test the HubbleScope class
 * Author:
 *    Cayden Lords
 * Summary:
 *    All the unit tests for HubbleScope
 ************************************************************************/


#pragma once

#include "satellite.h"
#include "position.h"
#include "unitTest.h"
#include "HubbleScope.h"

 /***************************************************
  * HubbleScope TEST
  * Test the HubbleScope class
  ***************************************************/
class TestHubbleScope : public UnitTest
{
public:
   void run()
   {
      test_getPosition();
      test_setPosition();
      test_getAngle();
      report("HubbleScope");
   }

private:
   void test_getPosition();
   void test_setPosition();
   void test_getAngle();

};