#pragma once

/***********************************************************************
 * Header File:
 *    Test Body : Test the Body class
 * Author:
 *    Cayden Lords
 * Summary:
 *    All the unit tests for Body
 ************************************************************************/


#pragma once

#include "position.h"
#include "body.h"
#include "unitTest.h"

 /*******************************
  * TEST Position
  * A friend class for Position which contains the Position unit tests
  ********************************/
class TestBody : public UnitTest
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
   }
private:
   void defaultConstructor() {
      // setup
      // exercise
      Body body = Body();
      // verify
      assertUnit(body.pos == Position(0, 0));
      // teardown
   }
   void constructorZero()
   {
      // setup
      // exercise
      Body body(Position(0,0));
      // verify
      assertUnit(body.pos == Position(0, 0));
      // teardown
   }
   void constructorNegative()
   {
      // setup
      // exercise
      Body body(Position(-100, -100));
      // verify
      assertUnit(body.pos == Position(-100, -100));
      // teardown
   }
   void constructorFortyTwo()
   {
      // setup
      // exercise
      Body body(Position(42, 42));
      // verify
      assertUnit(body.pos == Position(42, 42));
      // teardown
   }
   void getPositionZero(){
      // setup
      Body body;
      body.pos = Position(0,0);
      // exercise
      Position pos = body.getPos();
      // verify
      assertUnit(pos == Position(0, 0));
      // teardown
   }
   void getPositionNegative() {
      // setup
      Body body;
      body.pos = Position(-100, -100);
      // exercise
      Position pos = body.getPos();
      // verify
      assertUnit(pos == Position(-100, -100));
      // teardown
   }
   void getPositionFortyTwo() {
      // setup
      Body body;
      body.pos = Position(42, 42);
      // exercise
      Position pos = body.getPos();
      // verify
      assertUnit(pos == Position(42, 42));
      // teardown
   }
   void setPositionZero() {
      // setup
      Body body;
      // exercise
      body.setPos(Position(0, 0));
      // verify
      assertUnit(body.pos == Position(0, 0));
      // teardown
   }
   void setPositionNegative() {
      // setup
      Body body;
      // exercise
      body.setPos(Position(-100, -100));
      // verify
      assertUnit(body.pos == Position(-100, -100));
      // teardown
   }
   void setPositionFortyTwo() {
      // setup
      Body body;
      // exercise
      body.setPos(Position(42, 42));
      // verify
      assertUnit(body.pos == Position(42, 42));
      // teardown
   }
};