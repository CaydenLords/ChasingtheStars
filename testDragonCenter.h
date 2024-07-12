/***********************************************************************
 * Header File:
 *    Test DragonCenter : Test the DragonCenter class
 * Author:
 *    Cayden Lords
 * Summary:
 *    All the unit tests for DragonCenter
 ************************************************************************/


#pragma once

#include "satellite.h"
#include "position.h"
#include "unitTest.h"
#include "DragonCenter.h"

 /***************************************************
  * DragonCenter TEST
  * Test the DragonCenter class
  ***************************************************/
class TestDragonCenter : public UnitTest
{
public:
   void run()
   {
      test_getPosition();
      test_setPosition();
      test_getAngle();
      report("DragonCenter");
   }

private:
   void test_getPosition();
   void test_setPosition();
   void test_getAngle();

};