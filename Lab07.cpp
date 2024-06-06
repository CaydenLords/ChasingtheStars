/*************************************************************
 * 1. Name:
 *      Demo
 * 2. Assignment Name:
 *      Lab 07: Orbit Simulator
 * 3. Assignment Description:
 *      Simulate satellites orbiting the earth
 * 4. What was the hardest part? Be as specific as possible.
 *      ??
 * 5. How long did it take for you to complete the assignment?
 *      ??
 *****************************************************************/

#include <cassert>      // for ASSERT
#include <math.h>       // For ATAN and a bunch of other math stuff
#include "uiInteract.h" // for INTERFACE
#include "uiDraw.h"     // for RANDOM and DRAW*
#include "position.h"      // for POINT
using namespace std;
#define TIME_DILATION 1440
#define TIME_PER_FRAME 48
#define TWO_PI 6.28318530718

/*************************************************************************
 * Demo
 * Test structure to capture the LM that will move around the screen
 *************************************************************************/
class Demo
{
public:
   Demo(Position ptUpperRight) :
      ptUpperRight(ptUpperRight)
   {
      ptHubble.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
      ptHubble.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));

      ptSputnik.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
      ptSputnik.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));

      ptStarlink.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
      ptStarlink.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));

      ptCrewDragon.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
      ptCrewDragon.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));

      ptShip.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
      ptShip.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));

      ptGPS.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
      ptGPS.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));

      ptStar.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
      ptStar.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));

      ptOrbitStation.setMetersX(0);
      ptOrbitStation.setMetersY(42164000);
      ptOrbitVelocity.setMetersX(-3100.0);
      ptOrbitVelocity.setMetersY(0.0);

      angleShip = 0.0;
      angleEarth = 0.0;
      phaseStar = 0;
   }

   Position ptHubble;
   Position ptSputnik;
   Position ptStarlink;
   Position ptCrewDragon;
   Position ptShip;
   Position ptGPS;
   Position ptStar;
   Position ptUpperRight;
   Position ptOrbitStation;
   Position ptOrbitVelocity;

   unsigned char phaseStar;

   double angleShip;
   double angleEarth;
};

double Position::metersFromPixels = 40.0;

/************************************************************************
 * Rotate Earth
 * Calculates the radians the Earth is rotating
 *  OUTPUT rotation  The radians the Earth is rotating 
 *************************************************************************/
float rotateEarth() 
{
   return (TWO_PI / -30.0) * (TIME_DILATION/86400.0);
}

/************************************************************************
 * Gravity
 * Calculates the acceleration of the gravity the Earth has at a certain height
 *  INPUT  height    The height above the Earth in meters
 *  OUTPUT gravity   The gravity's effect in acceleration
 *************************************************************************/
float gravity(float height)
{
   return 9.80665 * (6378000.0/(6378000.0+height));
}

/************************************************************************
 * Height Above Earth
 * Calculates the acceleration of the gravity the Earth has at a certain height
 *  INPUT  place    The x and y coordinates of the object, where the Earth is (0,0)
 *  OUTPUT height   How high the object is above the Earth
 *************************************************************************/
float heightAboveEarth(Position place) 
{
   return sqrt(place.getMetersX() * place.getMetersX() * place.getMetersY() * place.getMetersY()) - 6378000;
}

/************************************************************************
 * Direction of Gravity
 * Calculates what direction gravity is pulling (in radians) 
 *  INPUT  place       The x and y coordinates of the object, where the Earth is (0,0)
 *  OUTPUT direction   What direction gravity is pulling in radians 
 *************************************************************************/
float gravityDirection (Position place) 
{
   return atan2(0-place.getMetersX(), 0-place.getMetersY());
}

/************************************************************************
 * Get Horizontal 
 * calculates the horizontal component of acceleration 
 *  INPUT  accel    The total acceleration of the object due to gravity
 *  INPUT  angle    The direction the gravity is pulling in radians
 *  OUTPUT xAccel   The horizontal component of the acceleration
 *************************************************************************/
float getHorizontal(float accel, float angle) 
{
   return accel * sin(angle);
}

/************************************************************************
 * Get Vertical
 * calculates the vertical component of acceleration
 *  INPUT  accel    The total acceleration of the object due to gravity
 *  INPUT  angle    The direction the gravity is pulling in radians
 *  OUTPUT yAccel   The vertical component of the acceleration
 *************************************************************************/
float getVertical(float accel, float angle) 
{
   return accel * cos(angle);
}

/************************************************************************
 * Get Distance
 * calculates where an object moves 
 * INPUT  velocity   How fast the object is currently moving
 * INPUT  time       How much time has passed
 * INPUT  accel      The acceleration of the object due to gravity
 * INPUT  pos        The location of the object (either x or y) 
 * OUTPUT newPos     Where the object is now
 *************************************************************************/
float getDistance(float velocity, float time, float accel, float pos) 
{
   return pos + (velocity * time) + (0.5 * accel * time);
}

/************************************************************************
 * Get Velocity
 * calculates how fast an object is now moving
 * INPUT  velocity   How fast the object is currently moving
 * INPUT  accel      The acceleration of the object
 * INPUT  time       How much time has passed
 * OUTPUT newVel     How fast the object is now moving
 *************************************************************************/
float getVelocity(float velocity, float accel, float time)
{
   return velocity + (accel * time);
}

/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(const Interface* pUI, void* p)
{
   // the first step is to cast the void pointer into a game object. This
   // is the first step of every single callback function in OpenGL. 
   Demo* pDemo = (Demo*)p;

   //
   // accept input
   //

   // move by a little
   if (pUI->isUp())
      pDemo->ptShip.addPixelsY(1.0);
   if (pUI->isDown())
      pDemo->ptShip.addPixelsY(-1.0);
   if (pUI->isLeft())
      pDemo->ptShip.addPixelsX(-1.0);
   if (pUI->isRight())
      pDemo->ptShip.addPixelsX(1.0);


   //
   // perform all the game logic
   //

   // rotate the earth
   pDemo->angleEarth += rotateEarth();
   pDemo->angleShip += 0.02;
   pDemo->phaseStar++;

   //
   // draw everything
   //

   Position pt;
   ogstream gout(pt);

   // draw satellites
   gout.drawCrewDragon(pDemo->ptCrewDragon, pDemo->angleShip);
   gout.drawHubble(pDemo->ptHubble, pDemo->angleShip);
   gout.drawSputnik(pDemo->ptSputnik, pDemo->angleShip);
   gout.drawStarlink(pDemo->ptStarlink, pDemo->angleShip);
   gout.drawShip(pDemo->ptShip, pDemo->angleShip, pUI->isSpace());
   gout.drawGPS(pDemo->ptGPS, pDemo->angleShip);
   gout.drawGPS(pDemo->ptOrbitStation, pDemo->angleShip);

   // draw parts
   pt.setPixelsX(pDemo->ptCrewDragon.getPixelsX() + 20);
   pt.setPixelsY(pDemo->ptCrewDragon.getPixelsY() + 20);
   gout.drawCrewDragonRight(pt, pDemo->angleShip); // notice only two parameters are set
   pt.setPixelsX(pDemo->ptHubble.getPixelsX() + 20);
   pt.setPixelsY(pDemo->ptHubble.getPixelsY() + 20);
   gout.drawHubbleLeft(pt, pDemo->angleShip);      // notice only two parameters are set
   pt.setPixelsX(pDemo->ptGPS.getPixelsX() + 20);
   pt.setPixelsY(pDemo->ptGPS.getPixelsY() + 20);
   gout.drawGPSCenter(pt, pDemo->angleShip);       // notice only two parameters are set
   pt.setPixelsX(pDemo->ptStarlink.getPixelsX() + 20);
   pt.setPixelsY(pDemo->ptStarlink.getPixelsY() + 20);
   gout.drawStarlinkArray(pt, pDemo->angleShip);   // notice only two parameters are set

   // draw fragments
   pt.setPixelsX(pDemo->ptSputnik.getPixelsX() + 20);
   pt.setPixelsY(pDemo->ptSputnik.getPixelsY() + 20);
   gout.drawFragment(pt, pDemo->angleShip);
   pt.setPixelsX(pDemo->ptShip.getPixelsX() + 20);
   pt.setPixelsY(pDemo->ptShip.getPixelsY() + 20);
   gout.drawFragment(pt, pDemo->angleShip);

   // draw a single star
   gout.drawStar(pDemo->ptStar, pDemo->phaseStar);

   // draw the earth
   pt.setMeters(0.0, 0.0);
   gout.drawEarth(pt, pDemo->angleEarth);

   //get the height of the satellite above the Earth and the acceleration gravity causes
   float orbitHeight = heightAboveEarth(pDemo->ptOrbitStation);
   float orbitGravity = gravity(orbitHeight);

}


/*********************************
 * Initialize the simulation and set it in motion
 *********************************/
#ifdef _WIN32_X
#include <windows.h>
int WINAPI wWinMain(
   _In_ HINSTANCE hInstance,
   _In_opt_ HINSTANCE hPrevInstance,
   _In_ PWSTR pCmdLine,
   _In_ int nCmdShow)
#else // !_WIN32
int main(int argc, char** argv)
#endif // !_WIN32
{
   // Initialize OpenGL
   Position ptUpperRight;
   ptUpperRight.setZoom(128000.0 /* 128km equals 1 pixel */);
   ptUpperRight.setPixelsX(1000.0);
   ptUpperRight.setPixelsY(1000.0);
   Interface ui(0, NULL,
      "Demo",   /* name on the window */
      ptUpperRight);

   // Initialize the demo
   Demo demo(ptUpperRight);

   // set everything into action
   ui.run(callBack, &demo);


   return 0;
}
