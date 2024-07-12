/***********************************************************************
 * Header File:
 *    Test DragonRight : Test the DragonRight class
 * Author:
 *    Cayden Lords
 * Summary:
 *    All the unit tests for DragonRight
 ************************************************************************/


#pragma once

#include "satellite.h"
#include "position.h"
#include "unitTest.h"
#include "DragonRight.h"

 /***************************************************
  * DragonRight TEST
  * Test the DragonRight class
  ***************************************************/
class TestDragonRight : public UnitTest
{
public:
   void run()
   {
      test_getPosition();
      test_setPosition();
      test_getAngle();
      report("DragonRight");
   }

private:
   void test_getPosition();
   void test_setPosition();
   void test_getAngle();

};