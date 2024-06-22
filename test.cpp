/***********************************************************************
 * Source File:
 *    Test : Test runner
 * Author:
 *    Br. Helfrich
 * Summary:
 *    The test runner for all the unit tests
 ************************************************************************/

#include "test.h"
#include "testPosition.h"
#include "testInertia.h"
#include "testSatellite.h"
#include "testSputnik.h"
#include "testBody.h"
#include "testCollidable.h"

/*****************************************************************
 * TEST RUNNER
 * Runs all the unit tests
 ****************************************************************/
void testRunner()
{
   TestPosition().run();
   TestInertia().run();
   TestBody().run();
   TestCollidable().run();
   TestSatellite().run();
   TestSputnik().run();
}
