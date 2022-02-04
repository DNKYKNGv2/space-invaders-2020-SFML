#ifndef SPACEINVADERSSFML_LASER_H
#define SPACEINVADERSSFML_LASER_H
#include "GameObject.h"
#include "Vector2.h"

class Laser : public GameObject
{
 public:
  Laser();
  ~Laser();

  Vector2 laser_direction = {0, 0};
  int laser_speed = 200;

  sf::Texture laser_texture;

  bool getVisibility();
  void setVisibility(bool v);
  bool visible = true;



 private:
};

#endif // SPACEINVADERSSFML_LASER_H
