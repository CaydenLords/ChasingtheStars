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
#include "testGPS.h"
#include "testHubble.h"
#include "testDragon.h"
#include "testStarlink.h"
#include "testChaser.h"
#include "testFragile.h"
#include "testProjectile.h"
#include "testFragment.h"
#include "testDragonLeft.h"
#include "testDragonCenter.h"
#include "testDragonRight.h"
#include "testGPSLeft.h"
#include "testGPSCenter.h"
#include "testGPSRight.h"
#include "testHubbleLeft.h"
#include "testHubbleRight.h"
#include "testHubbleComputer.h"
#include "testHubbleScope.h"
#include "testStarlinkBody.h"
#include "testStarlinkArray.h"
#include "testGame.h"

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
   TestGPS().run();
   TestGPSLeft().run();
   TestGPSCenter().run();
   TestGPSRight().run();
   TestHubble().run();
   TestHubbleLeft().run();
   TestHubbleRight().run();
   TestHubbleComputer().run();
   TestHubbleScope().run();
   TestDragon().run();
   TestDragonLeft().run();
   TestDragonCenter().run();
   TestDragonRight().run();
   TestStarlink().run();
   TestStarlinkBody().run();
   TestStarlinkArray().run();
   TestChaser().run();
   TestFragile().run();
   TestProjectile().run();
   TestFragment().run();
   TestGame().run();
}
