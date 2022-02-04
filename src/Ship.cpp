#include "Ship.h"
#include <iostream>

Ship::Ship()
{
  if (!Ship1_blue.loadFromFile("Data/Images/SpaceShooterRedux/PNG/playerShip1_blue.png") ||
      !Ship1_green.loadFromFile("Data/Images/SpaceShooterRedux/PNG/playerShip1_green.png") ||
      !Ship1_orange.loadFromFile("Data/Images/SpaceShooterRedux/PNG/playerShip1_orange.png") ||
      !Ship1_red.loadFromFile("Data/Images/SpaceShooterRedux/PNG/playerShip1_red.png") ||
      !Ship2_blue.loadFromFile("Data/Images/SpaceShooterRedux/PNG/playerShip2_blue.png") ||
      !Ship2_green.loadFromFile("Data/Images/SpaceShooterRedux/PNG/playerShip2_green.png") ||
      !Ship2_orange.loadFromFile("Data/Images/SpaceShooterRedux/PNG/playerShip2_orange.png") ||
      !Ship2_red.loadFromFile("Data/Images/SpaceShooterRedux/PNG/playerShip2_red.png") ||
      !Ship3_blue.loadFromFile("Data/Images/SpaceShooterRedux/PNG/playerShip3_blue.png") ||
      !Ship3_green.loadFromFile("Data/Images/SpaceShooterRedux/PNG/playerShip3_green.png") ||
      !Ship3_orange.loadFromFile("Data/Images/SpaceShooterRedux/PNG/playerShip3_orange.png") ||
      !Ship3_red.loadFromFile("Data/Images/SpaceShooterRedux/PNG/playerShip3_red.png"))
  {
    std::cout << "Ship texture did not load!\n";
  }
}

Ship::~Ship()
{

}

void Ship::addTexture(Ships ship)
{
  if (ship == Ships::Ship1_Blue)
  {
    sprite->setTexture(Ship1_blue);
  }

  else if (ship == Ships::Ship1_Green)
  {
    sprite->setTexture(Ship1_green);
  }

  else if (ship == Ships::Ship1_Orange)
  {
    sprite->setTexture(Ship1_orange);
  }

  else if (ship == Ships::Ship1_Red)
  {
    sprite->setTexture(Ship1_red);
  }

  else if (ship == Ships::Ship2_Blue)
  {
    sprite->setTexture(Ship2_blue);
  }

  else if (ship == Ships::Ship2_Green)
  {
    sprite->setTexture(Ship2_green);
  }

  else if (ship == Ships::Ship2_Orange)
  {
    sprite->setTexture(Ship2_orange);
  }

  else if (ship == Ships::Ship2_Red)
  {
    sprite->setTexture(Ship2_red);
  }

  else if (ship == Ships::Ship3_Blue)
  {
    sprite->setTexture(Ship3_blue);
  }

  else if (ship == Ships::Ship3_Green)
  {
    sprite->setTexture(Ship3_green);
  }

  else if (ship == Ships::Ship3_Orange)
  {
    sprite->setTexture(Ship3_orange);
  }

  else if (ship == Ships::Ship3_Red)
  {
    sprite->setTexture(Ship3_red);
  }
}