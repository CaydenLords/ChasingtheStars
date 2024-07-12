/***********************************************************************
 * Header File:
 *    Test Sputnik : Test the Sputnik class
 * Author:
 *    Ryan Donaldson
 * Summary:
 *    All the unit tests for Sputnik
 ************************************************************************/


#pragma once

#include "satellite.h"
#include "position.h"
#include "unitTest.h"
#include "sputnik.h"

 /***************************************************
  * SPUTNIK TEST
  * Test the SPUTNIK class
  ***************************************************/
class TestSputnik : public UnitTest
{
public:
   void run()
   {
      test_getPosition();
      test_setPosition();
      test_getAngle();
      test_collide();
      report("Sputnik");
   }

private:
   void test_getPosition();
   void test_setPosition();
   void test_getAngle();
   void test_collide();

};