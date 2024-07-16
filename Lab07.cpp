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
#include "game.h" // for GAME
#include "test.h" // for TESTS
using namespace std;
#define TIME_DILATION 1440.0
#define TIME_PER_FRAME 48.0
#define TWO_PI 6.28318530718



/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(const Interface* pUI, void* p)
{

   Game* pGame = (Game*)p;
   bool right = pUI->isRight();
   bool left = pUI->isLeft();
   bool down = pUI->isDown();
   bool space = pUI->isSpace();

   pGame->runPhysics(left, right, down, space);

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
      "Chasing the Stars",   /* name on the window */
      ptUpperRight);
   testRunner();
   // Initialize the demo
   Game game(ptUpperRight);
   // set everything into action
   ui.run(callBack, &game);


   return 0;
}
