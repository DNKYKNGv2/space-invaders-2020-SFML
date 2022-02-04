
#ifndef SPACEINVADERS_GAME_H
#define SPACEINVADERS_GAME_H

#include "Alien.h"
#include "Laser.h"
#include "Ship.h"
#include "Vector2.h"
#include <SFML/Graphics.hpp>

class Game
{
 public:
  Game(sf::RenderWindow& window);
  ~Game();
  bool init();
  void update(float dt);
  void render();
  void mouseClicked(sf::Event event);
  void keyPressed(sf::Event event);
  void mouseMove(sf::Event event);
  void keyReleased(sf::Event event);
  void reset();

  sf::Font font;
  sf::Text intro_text;
  sf::Text pause_text;
  sf::Text play_option;
  sf::Text quit_option;
  sf::Text player_score_str;
  sf::Text lives_str;
  sf::Text high_menu_text;
  sf::Text play_again_text;
  sf::Text resume_text;
  sf::Text quit_text;
  sf::Text normal_mode_text;
  sf::Text gravity_mode_text;
  sf::Text quadratic_mode_text;
  sf::Text sine_mode_text;


  sf::Sprite background;
  sf::Texture background_texture;

  sf::Sprite title;
  sf::Texture title_texture;

  sf::Sprite fade_back;
  sf::Texture fade_texture;

  Alien* aliens;
  int alien_counter = 70;

  Ship* ship;

  Laser* laser;

  int grid_size_x = 14;
  int grid_size_y = 5;
  int player_score = 0;
  int highest_score = 0;
  int quad_mod = 1;

  sf::Clock alien_down;
  sf::Time timeSinceLastUpdate = sf::Time::Zero;
  sf::Time elapsed = alien_down.restart();

  bool in_menu;
  bool intro_menu;
  bool high_score_menu;
  bool pause_menu;
  bool in_game;
  bool play_selected = true;
  bool paused = false;
  bool resume_selected = true;
  bool game_mode_menu;
  bool normal_selected = true;
  bool gravity_selected = false;
  bool quadratic_selected = false;
  bool sine_selected = false;

  enum gameModes {Normal, Gravity, Quadratic, Sine};

  void gamemode(gameModes mode);

 private:
  sf::RenderWindow& window;


};

#endif // SPACEINVADERS_GAME_H
