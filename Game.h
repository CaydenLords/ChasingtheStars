#pragma once
/***********************************************************************
 * Header File:
 *    Game: An instance of the space simulation
 * Author:
 *    Cayden Lords
 * Summary:
 *    This contains everything we need in order to run the simulation.
 ************************************************************************/


#pragma once
#include <vector>
#include <iostream> 
#include <cmath>
#include "position.h"
#include "collidable.h"


class TestGame;
class Acceleration;
class Velocity;

/*********************************************
 * Game
 * The simulation
 *********************************************/

class Game {
public: 
   // constructors
   Game();
   Game(Position upperRight);

   // Game Runners
   void runPhysics(bool left, bool right, bool down);
   void moveInertia(bool left, bool right, bool down);
   void checkCollisions();
   void drawBodies(bool down);
protected: 
   //Star[] stars;
   vector<Collidable*> collidables;
};