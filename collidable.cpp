#include "collidable.h"
#include "fragment.h"
#include <random>
#define M_PI 3.14159265358979323846

std::vector<Collidable*> Collidable::collide()
{
   std::vector<Collidable*> objects;
   
   return objects;
}

/************************************************************************
 * makeFragment
 * Creates fragments for objects which collide
 *************************************************************************/
std::vector<Collidable*> Collidable::makeFragments(int frags)
{
   std::vector<Collidable*> newFrags;

   for (int i = 0; i < frags; i++)
   {
      // Randomly generate new angle and speed
      std::random_device rd;
      std::mt19937 gen(rd());
      std::uniform_int_distribution<> distrib(0, 360);
      std::uniform_int_distribution<> distrib2(5000, 9000);


      // Create a new angle, speed, and position for the fragment
      // New angle
      Angle randAngle(distrib(gen));
      int randSpeed = distrib2(gen);

      // New speed
      int oldSpeed = speed.getMetersX();
      int newSpeed = oldSpeed + randSpeed;
      Position newerSpeed(newSpeed, speed.getMetersY());

      // New position
      Position newPos = rotate(pos, 4, 4, randAngle.getDegrees() * M_PI / 180.0);
      

      Fragment* piece = new Fragment(newPos, randAngle, 2, newerSpeed, 0);
      newFrags.push_back(piece);
   }

   return newFrags;

}
