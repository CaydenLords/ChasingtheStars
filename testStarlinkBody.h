/***********************************************************************
 * Header File:
 *    Test Starlink Body : Test the Starlink Body class
 * Author:
 *    Cayden Lords
 * Summary:
 *    All the unit tests for Starlink Body
 ************************************************************************/


#pragma once

#include "satellite.h"
#include "position.h"
#include "unitTest.h"
#include "starlinkBody.h"

 /***************************************************
  * STARLINK TEST
  * Test the Starlink Body class
  ***************************************************/
class TestStarlinkBody : public UnitTest
{
public:
   void run()
   {
      test_getPosition();
      test_setPosition();
      test_getAngle();
      report("StarlinkBody");
   }

private:
   void test_getPosition();
   void test_setPosition();
   void test_getAngle();

};