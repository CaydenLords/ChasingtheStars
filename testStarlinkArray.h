/***********************************************************************
 * Header File:
 *    Test Starlink Array : Test the Starlink Array class
 * Author:
 *    Cayden Lords
 * Summary:
 *    All the unit tests for Starlink Array
 ************************************************************************/


#pragma once

#include "satellite.h"
#include "position.h"
#include "unitTest.h"
#include "starlinkArray.h"

 /***************************************************
  * STARLINK TEST
  * Test the Starlink Array class
  ***************************************************/
class TestStarlinkArray : public UnitTest
{
public:
   void run()
   {
      test_getPosition();
      test_setPosition();
      test_getAngle();
      report("StarlinkArray");
   }

private:
   void test_getPosition();
   void test_setPosition();
   void test_getAngle();

};