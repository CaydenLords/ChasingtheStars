/***********************************************************************
 * Header File:
 *    Test DragonLeft : Test the DragonLeft class
 * Author:
 *    Cayden Lords
 * Summary:
 *    All the unit tests for DragonLeft
 ************************************************************************/


#pragma once

#include "satellite.h"
#include "position.h"
#include "unitTest.h"
#include "DragonLeft.h"

 /***************************************************
  * DragonLeft TEST
  * Test the DragonLeft class
  ***************************************************/
class TestDragonLeft : public UnitTest
{
public:
   void run()
   {
      test_getPosition();
      test_setPosition();
      test_getAngle();
      test_collide();
      report("DragonLeft");
   }

private:
   void test_getPosition();
   void test_setPosition();
   void test_getAngle();
   void test_collide();
};