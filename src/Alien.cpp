#include "Alien.h"
#include <iostream>

Alien::Alien()
{
  if (!beige_texture.loadFromFile("Data/Images/Alien UFO pack/PNG/shipBeige.png") ||
      !beige_damage1.loadFromFile("Data/Images/Alien UFO pack/PNG/shipBeige_damage1.png") ||
      !beige_damage2.loadFromFile("Data/Images/Alien UFO pack/PNG/shipBeige_damage2.png") ||
      !blue_texture.loadFromFile("Data/Images/Alien UFO pack/PNG/shipBlue.png") ||
      !blue_damage1.loadFromFile("Data/Images/Alien UFO pack/PNG/shipBlue_damage1.png") ||
      !blue_damage2.loadFromFile("Data/Images/Alien UFO pack/PNG/shipBlue_damage2.png") ||
      !green_texture.loadFromFile("Data/Images/Alien UFO pack/PNG/shipGreen.png") ||
      !green_damage1.loadFromFile("Data/Images/Alien UFO pack/PNG/shipGreen_damage1.png") ||
      !green_damage2.loadFromFile("Data/Images/Alien UFO pack/PNG/shipGreen_damage2.png") ||
      !pink_texture.loadFromFile("Data/Images/Alien UFO pack/PNG/shipPink.png") ||
      !pink_damage1.loadFromFile("Data/Images/Alien UFO pack/PNG/shipPink_damage1.png") ||
      !pink_damage2.loadFromFile("Data/Images/Alien UFO pack/PNG/shipPink_damage.png") ||
      !yellow_texture.loadFromFile("Data/Images/Alien UFO pack/PNG/shipYellow.png") ||
      !yellow_damage1.loadFromFile("Data/Images/Alien UFO pack/PNG/shipYellow_damage1.png") ||
      !yellow_damage2.loadFromFile("Data/Images/Alien UFO pack/PNG/shipYellow_damage2.png"))
  {
    std::cout << "Alien texture did not load!\n";
  }
  beige_texture.setSmooth(true);
  blue_texture.setSmooth(true);
  green_texture.setSmooth(true);
  pink_texture.setSmooth(true);
  yellow_texture.setSmooth(true);
}

Alien::~Alien()
{

}

bool Alien::getVisibility()
{
  return visible;
}

void Alien::setVisibility(bool v)
{
  visible = v;
}

void Alien::addTexture(Colours colour)
{
  if (colour == Colours::beige)
  {
    sprite->setTexture(beige_texture);

  }

  else if (colour == Colours::blue)
  {
    sprite->setTexture(blue_texture);
  }

  else if (colour == Colours::green)
  {
    sprite->setTexture(green_texture);
  }

  else if (colour == Colours::pink)
  {
    sprite->setTexture(pink_texture);
  }

  else if (colour == Colours::yellow)
  {
    sprite->setTexture(yellow_texture);
  }
}

void Alien::changeTexture(int alien_colour)
{
  switch (alien_colour)
  {
    case 0:
    {
      if (lives == 1)
      {
        sprite->setTexture(beige_damage2);
      }

      else if (lives == 2)
      {
        sprite->setTexture(beige_texture);
      }

//      else if (lives == 3)
//      {
//        sprite->setTexture(beige_texture);
//      }
      break;
    }

    case 1:
    {
      if (lives == 1)
      {
        sprite->setTexture(blue_damage2);
      }

      else if (lives == 2)
      {
        sprite->setTexture(blue_texture);
      }

//      else if (lives == 3)
//      {
//        sprite->setTexture(blue_texture);
//      }
      break;
    }

    case 2:
    {
      if (lives == 1)
      {
        sprite->setTexture(green_damage2);
      }

      else if (lives == 2)
      {
        sprite->setTexture(green_texture);
      }

//      else if (lives == 3)
//      {
//        sprite->setTexture(green_texture);
//      }
      break;
    }

    case 3:
    {
      if (lives == 1)
      {
        sprite->setTexture(pink_damage2);
      }

      else if (lives == 2)
      {
        sprite->setTexture(pink_texture);
      }

//      else if (lives == 3)
//      {
//        sprite->setTexture(pink_texture);
//      }
      break;
    }

    case 4:
    {
      if (lives == 1)
      {
        sprite->setTexture(yellow_damage2);
      }

      else if (lives == 2)
      {
        sprite->setTexture(yellow_texture);
      }

//      else if (lives == 3)
//      {
//        sprite->setTexture(yellow_texture);
//      }
      break;
    }
  }
}