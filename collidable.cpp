#include "collidable.h"
#include "fragment.h"
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
std::vector<Collidable*> Collidable::makeFragments(std::vector<Collidable*> pieces, int frags)
{
   std::vector<Collidable*> newFrags;

   for (int i = 0; i < frags; i++)
   {


      // Create a new angle, speed, and position for the fragment
      // New angle
      Angle randAngle(random(0, 360));
      int randSpeed = (random(5000, 9000));

      // New speed
      Position newerSpeed = rotate(speed, 0, randSpeed/12800, randAngle.getRadians());

      // New position
      Position newPos = rotate(pos, 0, 16, randAngle.getRadians());
      

      Fragment* piece = new Fragment(newPos, randAngle, 2, newerSpeed, 0);
      newFrags.push_back(piece);
   }

   newFrags.insert(newFrags.end(), pieces.begin(), pieces.end());

   return newFrags;
}
