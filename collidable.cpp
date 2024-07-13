#include "collidable.h"
#include "fragment.h"
#include <random>

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
      Position newPos;
      if (0 <= angle.getDegrees() && angle.getDegrees() <= 89)
      {
         newPos.setMetersX(pos.getMetersX());
         newPos.setMetersY(pos.getMetersY() + 4);
      }
      else if (90 <= angle.getDegrees() && angle.getDegrees() <= 179)
      {
         newPos.setMetersX(pos.getMetersX() + 4);
         newPos.setMetersY(pos.getMetersY());
      }
      else if (180 <= angle.getDegrees() && angle.getDegrees() <= 269)
      {
         newPos.setMetersX(pos.getMetersX());
         newPos.setMetersY(pos.getMetersY() - 4);
      }
      else
      {
         newPos.setMetersX(pos.getMetersX() - 4);
         newPos.setMetersY(pos.getMetersY());
      }
      

      Fragment* piece = new Fragment(newPos, randAngle, 2, newerSpeed, 0);
      newFrags.push_back(piece);
   }

   return newFrags;

}
