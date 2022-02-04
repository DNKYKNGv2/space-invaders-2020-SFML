#include "Laser.h"

Laser::Laser()
{

}

Laser::~Laser()
{

}

bool Laser::getVisibility()
{
  return visible;
}

void Laser::setVisibility(bool v)
{
  visible = v;
}