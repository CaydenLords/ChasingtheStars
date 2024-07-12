/***********************************************************************
 * Header File:
 *    Test HubbleLeft : Test the HubbleLeft class
 * Author:
 *    Cayden Lords
 * Summary:
 *    All the unit tests for HubbleLeft
 ************************************************************************/


#pragma once

#include "satellite.h"
#include "position.h"
#include "unitTest.h"
#include "HubbleLeft.h"

 /***************************************************
  * HubbleLeft TEST
  * Test the HubbleLeft class
  ***************************************************/
class TestHubbleLeft : public UnitTest
{
public:
   void run()
   {
      test_getPosition();
      test_setPosition();
      test_getAngle();
      report("HubbleLeft");
   }

private:
   void test_getPosition();
   void test_setPosition();
   void test_getAngle();

};