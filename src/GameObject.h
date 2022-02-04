
#ifndef SPACEINVADERS_GAMEOBJECT_H
#define SPACEINVADERS_GAMEOBJECT_H
#include <SFML/Graphics.hpp>


class GameObject
{
 public:
  GameObject();
  GameObject(sf::Sprite* spr);
  ~GameObject();

  bool initialiseSprite(sf::Texture &texture, std::string filename);
  sf::Sprite* getSprite();

 protected:
  sf::Sprite* sprite = nullptr;

};


#endif // SPACEINVADERS_GAMEOBJECT_H
