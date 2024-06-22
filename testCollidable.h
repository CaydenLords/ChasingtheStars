
/***********************************************************************
 * Header File:
 *    Test Collidable : Test the Collidable class
 * Author:
 *    Cayden Lords
 * Summary:
 *    All the unit tests for Collidable
 ************************************************************************/


#pragma once

#include "position.h"
#include "body.h"
#include "collidable.h"
#include "unitTest.h"

 /*******************************
  * TEST Collidable
  * A friend class for Collidable which contains the Collidable unit tests
  ********************************/
class TestCollidable : public UnitTest
{
public:
   void run()
   {
      defaultConstructor();
      constructorZero();
      constructorNegative();
      constructorFortyTwo();
      getPositionZero();
      getPositionNegative();
      getPositionFortyTwo();
      setPositionZero();
      setPositionNegative();
      setPositionFortyTwo();
      report("Collidable");
   }
private:
   void defaultConstructor() {
      // setup
      // exercise
      Collidable collidable;
      // verify
      assertUnit(collidable.pos == Position(0, 0));
      // teardown
   }
   void constructorZero()
   {
      // setup
      // exercise
      Collidable collidable(Position(0, 0), 0);
      // verify
      assertUnit(collidable.pos == Position(0, 0));
      // teardown
   }
   void constructorNegative()
   {
      // setup
      // exercise
      Collidable collidable(Position(-100, -100), 0);
      // verify
      assertUnit(collidable.pos == Position(-100, -100));
      // teardown
   }
   void constructorFortyTwo()
   {
      // setup
      // exercise
      Collidable collidable(Position(42, 42), 0);
      // verify
      assertUnit(collidable.pos == Position(42, 42));
      // teardown
   }
   void getPositionZero() {
      // setup
      Collidable collidable;
      collidable.pos = Position(0, 0);
      // exercise
      Position pos = collidable.getPos();
      // verify
      assertUnit(pos == Position(0, 0));
      // teardown
   }
   void getPositionNegative() {
      // setup
      Collidable collidable;
      collidable.pos = Position(-100, -100);
      // exercise
      Position pos = collidable.getPos();
      // verify
      assertUnit(pos == Position(-100, -100));
      // teardown
   }
   void getPositionFortyTwo() {
      // setup
      Collidable collidable;
      collidable.pos = Position(42, 42);
      // exercise
      Position pos = collidable.getPos();
      // verify
      assertUnit(pos == Position(42, 42));
      // teardown
   }
   void setPositionZero() {
      // setup
      Collidable collidable;
      // exercise
      collidable.setPos(Position(0, 0));
      // verify
      assertUnit(collidable.pos == Position(0, 0));
      // teardown
   }
   void setPositionNegative() {
      // setup
      Collidable collidable;
      // exercise
      collidable.setPos(Position(-100, -100));
      // verify
      assertUnit(collidable.pos == Position(-100, -100));
      // teardown
   }
   void setPositionFortyTwo() {
      // setup
      Collidable collidable;
      // exercise
      collidable.setPos(Position(42, 42));
      // verify
      assertUnit(collidable.pos == Position(42, 42));
      // teardown
   }
};