/***********************************************************************
 * Source File:
 *    TEST Fragment
 * Author:
 *    Cayden Lords
 * Summary:
 *    The unit tests for Fragment
 ************************************************************************/

#include "testFragment.h"
#include "Fragment.h"
#include "position.h"
#include <cassert>

 /*************************************
   * TEST SET POSITION : Fragment
   * Input: 0, 0
   * Output: 0, 0
   **************************************/
void TestFragment::test_setPosition()
{
   // SETUP
   Fragment inertia;

   // EXERCISE
   inertia.setPosition(0, 0);

   // VERIFY
   assertUnit(inertia.pos == Position(0, 0));
   // TEARDOWN

}

/*************************************
 * TEST GET POSITION : Fragment
 * Input:
 * Output: 0, 0
 **************************************/
void TestFragment::test_getPosition()
{
   // SETUP
   Fragment inertia;
   inertia.pos = Position(0, 0);

   // EXERCISE
   Position myPosition = inertia.getPosition();

   // VERIFY
   assertUnit(myPosition == Position(0, 0));
   // TEARDOWN

}

/*************************************
  * TEST GET ANGLE : Fragment
  * Input: 100
  * Output: 100.0
  **************************************/
void TestFragment::test_getAngle()
{
   // SETUP
   Fragment inertia;
   inertia.angle = Angle(100);

   // EXERCISE
   Angle myAngle = inertia.getAngle();

   // VERIFY
   assertUnit(myAngle.getDegrees() == 100);
   // TEARDOWN
}

/*************************************
  * TEST MOVE 1 : Fragment
  * Input: (-36515095.13, 21082000.0)
  * Output: (-36514424.0,  21081612.0)
  **************************************/
void TestFragment::test_move1()
{
   // SETUP
   Fragment satellite;
   satellite.pos = Position(-36515095.13, 21082000.0);


   // EXERCISE
   satellite.move(false, false, false);

   Position posNew = satellite.getPosition();
   // VERIFY
   assertUnit(posNew == Position(-36514424.0, 21081612.0));
   // TEARDOWN
}

/*************************************
  * TEST MOVE 2 : Fragment
  * Input: (10000000.0, 10000000.0)
  * Output: (9995125.0,  9995125.0)
  **************************************/
void TestFragment::test_move2()
{
   // SETUP
   Fragment satellite;
   satellite.pos = Position(10000000.0, 10000000.0);

   // EXERCISE
   satellite.move(false, false, false);

   Position posNew = satellite.getPosition();
   // VERIFY
   assertUnit(posNew == Position(9995125.0, 9995125.0));
   // TEARDOWN
}

/*************************************
  * TEST MOVE 0 : Fragment
  * Input: (0.0, 0.0)
  * Output: (0.0,  8472.9)
  **************************************/
void TestFragment::test_move0()
{
   // SETUP
   Fragment satellite;
   satellite.pos = Position(0.0, 0.0);

   // EXERCISE
   satellite.move(false, false, false);

   Position posNew = satellite.getPosition();
   // VERIFY
   assertUnit(posNew.getMetersX() == 0.0);
   assertUnit(round(posNew.getMetersY()) == 8473.0);
   // TEARDOWN
}

/*************************************
  * TEST DESPAWN: Fragment
  * Input: 0 framesLeft
  * Output: return true
  **************************************/
void TestFragment::test_despawn()
{
   // SETUP
   Fragment fragile;
   fragile.framesLeft = 0;

   // EXERCISE
   bool despawn = fragile.move(false, false, false);
   // VERIFY
   assertUnit(despawn == true);
   // TEARDOWN
}

/*************************************
  * TEST DESPAWN: Fragment
  * Input: 100 framesLeft
  * Output: return false
  **************************************/
void TestFragment::test_no_despawn()
{
   // SETUP
   Fragment fragile;
   fragile.framesLeft = 100;

   // EXERCISE
   bool despawn = fragile.move(false, false, false);
   // VERIFY
   assertUnit(despawn == false);
   // TEARDOWN
}
