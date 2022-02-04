#ifndef SPACEINVADERSSFML_ALIEN_H
#define SPACEINVADERSSFML_ALIEN_H
#include "GameObject.h"
#include "Vector2.h"
#include <SFML/Graphics.hpp>

class Alien : public GameObject
{
 public:
  Alien();
  ~Alien();

  bool getVisibility();
  void setVisibility(bool v);
  bool visible = true;

  enum Colours {beige, blue, green, pink, yellow};
  sf::Texture beige_texture;
  sf::Texture beige_damage1;
  sf::Texture beige_damage2;

  sf::Texture blue_texture;
  sf::Texture blue_damage1;
  sf::Texture blue_damage2;

  sf::Texture green_texture;
  sf::Texture green_damage1;
  sf::Texture green_damage2;

  sf::Texture pink_texture;
  sf::Texture pink_damage1;
  sf::Texture pink_damage2;

  sf::Texture yellow_texture;
  sf::Texture yellow_damage1;
  sf::Texture yellow_damage2;

  void addTexture(Colours colour);
  void changeTexture(int alien_colour);
  int current_colour;

  int alien_speed = 50;

  Vector2 alien_direction = {1.f, 0};

  int lives = 2;

};

#endif // SPACEINVADERSSFML_ALIEN_H
