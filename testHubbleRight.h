/***********************************************************************
 * Header File:
 *    Test HubbleRight : Test the HubbleRight class
 * Author:
 *    Cayden Lords
 * Summary:
 *    All the unit tests for HubbleRight
 ************************************************************************/


#pragma once

#include "satellite.h"
#include "position.h"
#include "unitTest.h"
#include "HubbleRight.h"

 /***************************************************
  * HubbleRight TEST
  * Test the HubbleRight class
  ***************************************************/
class TestHubbleRight : public UnitTest
{
public:
   void run()
   {
      test_getPosition();
      test_setPosition();
      test_getAngle();
      report("HubbleRight");
   }

private:
   void test_getPosition();
   void test_setPosition();
   void test_getAngle();

};