#ifndef SPACEINVADERSSFML_SHIP_H
#define SPACEINVADERSSFML_SHIP_H
#include "GameObject.h"
#include <SFML/Graphics.hpp>
#include "Vector2.h"

class Ship : public GameObject
{
 public:
  Ship();
  ~Ship();

  enum Ships {Ship1_Blue, Ship1_Green, Ship1_Orange, Ship1_Red, Ship2_Blue,
    Ship2_Green, Ship2_Orange, Ship2_Red, Ship3_Blue, Ship3_Green, Ship3_Orange,
    Ship3_Red};
  sf::Texture Ship1_blue;
  sf::Texture Ship1_green;
  sf::Texture Ship1_orange;
  sf::Texture Ship1_red;

  sf::Texture Ship2_blue;
  sf::Texture Ship2_green;
  sf::Texture Ship2_orange;
  sf::Texture Ship2_red;

  sf::Texture Ship3_blue;
  sf::Texture Ship3_green;
  sf::Texture Ship3_orange;
  sf::Texture Ship3_red;

  void addTexture(Ships ship);

  Vector2 ship_direction = {0,0};

  int ship_speed = 300;

 private:

};

#endif // SPACEINVADERSSFML_SHIP_H
