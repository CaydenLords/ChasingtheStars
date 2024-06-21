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

#include <iostream> 
#include <cmath>
#include "position.h"


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
   Game() {}
   Game(Position upperRight) {};

   // Game Runners
   void runPhysics();
   void moveInertia();
   void checkCollisions();
   void drawBodies();
private: 
   //Star[] stars;
   //Collidable[] collidables;
};