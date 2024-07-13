/***********************************************************************
 * Header File:
 *    Test Game : Test the Game class
 * Author:
 *    Ryan Donaldson
 * Summary:
 *    All the unit tests for Game
 ************************************************************************/

#include "unitTest.h"
#pragma once

 /***************************************************
   * GAME TEST
   * Test the GAME class
   ***************************************************/
class TestGame : public UnitTest
{
public:
   void run()
   {
      test_hasCollidedTrue();
      test_hasCollidedFalse();
      report("Game");
   }

private:
   void test_hasCollidedTrue();
   void test_hasCollidedFalse();


};

