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
   for (int i = 0; i < pieces.size(); i++)
   {

      Collidable* currentPiece = pieces[i];
      // Create a new angle, speed, and position for the piece
      // New angle
      Angle randAngle(random(0, 360));
      int randSpeed = random(5000, 9000);
      // New speed
      Position newSpeed = Position((sin(randAngle.getRadians())*randSpeed),(cos(randAngle.getRadians()) * randSpeed));
      Position newerSpeed = Position(speed.getMetersX() + newSpeed.getMetersX(), speed.getMetersY() + newSpeed.getMetersY());

      // New position
      Position newPos = rotate(pos, 0, 16, randAngle.getRadians());

      currentPiece->setPos(newPos);
      currentPiece->setSpeed(newerSpeed);
      currentPiece->setAngle(randAngle);
   }
   for (int i = 0; i < frags; i++)
   {


      // Create a new angle, speed, and position for the fragment
      // New angle
      Angle randAngle(random(0, 360));
      int randSpeed = random(5000, 9000);
      // New speed
      Position newSpeed = Position((sin(randAngle.getRadians()) * randSpeed), (cos(randAngle.getRadians()) * randSpeed));
      Position newerSpeed = Position(speed.getMetersX() + newSpeed.getMetersX(), speed.getMetersY() + newSpeed.getMetersY());

      // New position
      Position newPos = rotate(pos, 0, 16, randAngle.getRadians());
      

      Fragment* piece = new Fragment(newPos, randAngle, 2, newerSpeed, 0);
      newFrags.push_back(piece);
   }

   newFrags.insert(newFrags.end(), pieces.begin(), pieces.end());

   return newFrags;
}
