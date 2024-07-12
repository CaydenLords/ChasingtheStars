/***********************************************************************
 * Source File:
 *    TEST FRAGILE
 * Author:
 *    Cayden Lords
 * Summary:
 *    The unit tests for Fragile
 ************************************************************************/

#include "testFragile.h"
#include "Fragile.h"
#include "position.h"
#include <cassert>

 /*************************************
   * TEST SET POSITION : Fragile
   * Input: 0, 0
   * Output: 0, 0
   **************************************/
void TestFragile::test_setPosition()
{
   // SETUP
   Fragile inertia;

   // EXERCISE
   inertia.setPosition(0, 0);

   // VERIFY
   assertUnit(inertia.pos.getMetersX() == 0);
   assertUnit(inertia.pos.getMetersY() == 0);
   // TEARDOWN

}

/*************************************
 * TEST GET POSITION : Fragile
 * Input:
 * Output: 0, 0
 **************************************/
void TestFragile::test_getPosition()
{
   // SETUP
   Fragile inertia;
   inertia.pos = Position(0, 0);

   // EXERCISE
   Position myPosition = inertia.getPosition();

   // VERIFY
   assertUnit(myPosition == Position(0, 0));
   // TEARDOWN

}

/*************************************
  * TEST GET ANGLE : Fragile
  * Input: 100
  * Output: 100.0
  **************************************/
void TestFragile::test_getAngle()
{
   // SETUP
   Fragile inertia;
   inertia.angle = Angle(100);

   // EXERCISE
   Angle myAngle = inertia.getAngle();

   // VERIFY
   assertUnit(myAngle.getDegrees() == 100);
   // TEARDOWN
}

/*************************************
  * TEST MOVE 1 : Fragile
  * Input: (-36515095.13, 21082000.0)
  * Output: (-36514424.0,  21081612.0)
  **************************************/
void TestFragile::test_move1()
{
   // SETUP
   Fragile satellite;
   satellite.pos = Position(-36515095.13, 21082000.0);


   // EXERCISE
   satellite.move(false, false, false);

   Position posNew = satellite.getPosition();
   // VERIFY
   assertUnit(posNew.getMetersX() == -36514424.0);
   assertUnit(posNew.getMetersY() == 21081612.0);
   // TEARDOWN
}

/*************************************
  * TEST MOVE 2 : Fragile
  * Input: (10000000.0, 10000000.0)
  * Output: (9995125.0,  9995125.0)
  **************************************/
void TestFragile::test_move2()
{
   // SETUP
   Fragile satellite;
   satellite.pos = Position(10000000.0, 10000000.0);

   // EXERCISE
   satellite.move(false, false, false);

   Position posNew = satellite.getPosition();
   // VERIFY
   assertUnit(posNew.getMetersX() == 9995125.0);
   assertUnit(posNew.getMetersY() == 9995125.0);
   // TEARDOWN
}

/*************************************
  * TEST MOVE 0 : Fragile
  * Input: (0.0, 0.0)
  * Output: (0.0,  8472.9)
  **************************************/
void TestFragile::test_move0()
{
   // SETUP
   Fragile satellite;
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
  * TEST DESPAWN: Fragile
  * Input: 0 framesLeft
  * Output: return true
  **************************************/
void TestFragile::test_despawn()
{
   // SETUP
   Fragile fragile;
   fragile.framesLeft = 0;

   // EXERCISE
   bool despawn = fragile.move(false, false, false);
   // VERIFY
   assertUnit(despawn == true);
   // TEARDOWN
}

/*************************************
  * TEST DESPAWN: Fragile
  * Input: 100 framesLeft
  * Output: return false
  **************************************/
void TestFragile::test_no_despawn()
{
   // SETUP
   Fragile fragile;
   fragile.framesLeft = 100;

   // EXERCISE
   bool despawn = fragile.move(false, false, false);
   // VERIFY
   assertUnit(despawn == false);
   // TEARDOWN
}
