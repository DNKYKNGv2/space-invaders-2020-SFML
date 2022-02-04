
#include "Game.h"
#include <iostream>
#include <sstream>
#include <random>
#include <cmath>
#include <string>

Game::Game(sf::RenderWindow& game_window)
  : window(game_window)
{
  srand(time(nullptr));

  intro_menu = true;
  in_menu = false;
  in_game = false;
  high_score_menu = false;
  pause_menu = false;
  paused = false;
  game_mode_menu = false;
}

Game::~Game()
{

}

bool Game::init()
{
  //Text font
  if (!font.loadFromFile("Data/Fonts/OpenSans-Bold.ttf"))
  {
    std::cout << "Font did not load \n";
  }

  //Background
  if (!background_texture.loadFromFile("Data/Images/SpaceShooterRedux/Backgrounds/blue.png"))
  {
    std::cout << "Background did not load \n";
  }
  background_texture.setRepeated(true);
  background.setTexture(background_texture);
  background.setTextureRect(sf::IntRect(0, 0, window.getSize().x, window.getSize().y));

  //Fade
  if (!fade_texture.loadFromFile("Data/Images/SpaceShooterRedux/Backgrounds/fade.png"))
  {
    std::cout << "Fade did not load \n";
  }
  fade_texture.setRepeated(true);
  fade_back.setTexture(fade_texture);
  fade_back.setTextureRect(sf::IntRect(0, 0, window.getSize().x, window.getSize().y));
  fade_back.setColor(sf::Color(10,10,10, 128));

  //Title
  if (!title_texture.loadFromFile("Data/Images/Title/Title.png"))
  {
    std::cout << "Title did not load \n";
  }
  title_texture.setSmooth(true);
  title.setTexture(title_texture);
  title.setPosition(
    window.getSize().x / 2 - title.getGlobalBounds().width / 2,
    window.getSize().y / 2 - title.getGlobalBounds().height / 2);

  //Text
  intro_text.setString("Press Space to continue");
  intro_text.setFont(font);
  intro_text.setCharacterSize(40);
  intro_text.setFillColor(sf::Color(255, 255, 255, 255));
  intro_text.setPosition (
    window.getSize().x / 2 - intro_text.getGlobalBounds().width / 2,
    (window.getSize().y / 8) * 6 - intro_text.getGlobalBounds().height / 2);

  play_option.setString("Start Game");
  play_option.setFont(font);
  play_option.setCharacterSize(40);
  play_option.setFillColor(sf::Color(60,215,28,255));
  play_option.setPosition(
    window.getSize().x / 2 - play_option.getGlobalBounds().width / 2,
    window.getSize().y / 10 * 4 - play_option.getGlobalBounds().height / 2);

  quit_option.setString("Quit");
  quit_option.setFont(font);
  quit_option.setCharacterSize(40);
  quit_option.setFillColor(sf::Color(139,30,30,100));
  quit_option.setPosition(
    window.getSize().x / 2 - quit_option.getGlobalBounds().width / 2,
    window.getSize().y / 10 * 6 - quit_option.getGlobalBounds().height / 2);

  pause_text.setString("Paused");
  pause_text.setFont(font);
  pause_text.setCharacterSize(60);
  pause_text.setFillColor(sf::Color(255,255,255,255));
  pause_text.setPosition (
    window.getSize().x / 2 - pause_text.getGlobalBounds().width / 2,
    window.getSize().y / 8 - pause_text.getGlobalBounds().height / 2);

  resume_text.setString("Resume");
  resume_text.setFont(font);
  resume_text.setCharacterSize(40);
  resume_text.setFillColor(sf::Color(255,255,255,255));
  resume_text.setPosition (
    window.getSize().x / 2 - resume_text.getGlobalBounds().width / 2,
    (window.getSize().y / 8 * 5) - resume_text.getGlobalBounds().height / 2);

  quit_text.setString("Quit");
  quit_text.setFont(font);
  quit_text.setCharacterSize(40);
  quit_text.setFillColor(sf::Color(255,255,255,100));
  quit_text.setPosition (
    window.getSize().x / 2 - quit_text.getGlobalBounds().width / 2,
    (window.getSize().y / 8 * 6) - quit_text.getGlobalBounds().height / 2);

  normal_mode_text.setString("Normal Mode");
  normal_mode_text.setFont(font);
  normal_mode_text.setCharacterSize(25);
  normal_mode_text.setFillColor(sf::Color(255, 255, 255, 255));
  normal_mode_text.setPosition(
    window.getSize().x / 10 * 7 - normal_mode_text.getGlobalBounds().width / 2,
    window.getSize().y / 10 * 4 - normal_mode_text.getGlobalBounds().height / 2);

  gravity_mode_text.setString("Gravity Mode");
  gravity_mode_text.setFont(font);
  gravity_mode_text.setCharacterSize(25);
  gravity_mode_text.setFillColor(sf::Color(255, 255, 255, 100));
  gravity_mode_text.setPosition(
    window.getSize().x / 10 * 9 - normal_mode_text.getGlobalBounds().width / 2,
    window.getSize().y / 10 * 4 - normal_mode_text.getGlobalBounds().height / 2);

  quadratic_mode_text.setString("Quadratic Mode");
  quadratic_mode_text.setFont(font);
  quadratic_mode_text.setCharacterSize(25);
  quadratic_mode_text.setFillColor(sf::Color(255, 255, 255, 100));
  quadratic_mode_text.setPosition(
    window.getSize().x / 10 * 7 - normal_mode_text.getGlobalBounds().width / 2,
    window.getSize().y / 10 * 6 - normal_mode_text.getGlobalBounds().height / 2);

  sine_mode_text.setString("Sine Mode");
  sine_mode_text.setFont(font);
  sine_mode_text.setCharacterSize(25);
  sine_mode_text.setFillColor(sf::Color(255, 255, 255, 100));
  sine_mode_text.setPosition(
    window.getSize().x / 10 * 9 - normal_mode_text.getGlobalBounds().width / 2,
    window.getSize().y / 10 * 6 - normal_mode_text.getGlobalBounds().height / 2);


  std::stringstream ps;
  ps << player_score;
  std::string player_num = ps.str();
  player_score_str.setString("Score: " + player_num);
  player_score_str.setFont(font);
  player_score_str.setCharacterSize(25);
  player_score_str.setFillColor(sf::Color(255,255,255,255));
  player_score_str.setPosition(5, 5);

  std::stringstream hh;
  hh << highest_score;
  std::string high_num = hh.str();
  high_menu_text.setString("Highscore: " + high_num);
  high_menu_text.setFont(font);
  high_menu_text.setCharacterSize(40);
  high_menu_text.setFillColor(sf::Color(255,255,255,255));
  high_menu_text.setPosition(
    window.getSize().x / 2 - high_menu_text.getGlobalBounds().width / 2,
    window.getSize().y / 8 * 3 - high_menu_text.getGlobalBounds().height / 2);




  //Sprites
  ship = new Ship();
  ship->addTexture(Ship::Ship1_Blue);
  ship->getSprite()->setScale(0.6,0.6);
  ship->getSprite()->setPosition(window.getSize().x / 2,
                                 window.getSize().y - ship->getSprite()->getGlobalBounds().height - 5);


  laser = new Laser[20];
  for (int i = 0; i < 20; i++)
  {
    int randnum = int (rand() % 3);
    switch (randnum)
    {
      case 0:
      {
        laser[i].initialiseSprite(laser[i].laser_texture, "Data/Images/SpaceShooterRedux/PNG/Lasers/laserBlue07.png");
        break;
      }

      case 1:
      {
        laser[i].initialiseSprite(laser[i].laser_texture, "Data/Images/SpaceShooterRedux/PNG/Lasers/laserGreen13.png");
        break;
      }

      case 2:
      {
        laser[i].initialiseSprite(laser[i].laser_texture, "Data/Images/SpaceShooterRedux/PNG/Lasers/laserRed07.png");
        break;
      }

      default:
      {
        std::cout << "Failed to load (Lasers) \n";
        break;
      }
    }
    laser[i].setVisibility(false);
    laser[i].getSprite()->setPosition(0 - laser[i].getSprite()->getGlobalBounds().width,window.getSize().y + laser[i].getSprite()->getGlobalBounds().height);
  }

  aliens = new Alien[grid_size_x * grid_size_y];
  for (int i = 0; i < grid_size_x; i++)
  {
    for (int j = 0; j < grid_size_y; j++)
    {
      aliens[i*grid_size_y+j].setVisibility(true);

      switch (j)
      {
        case 0:
        {
          aliens[i*grid_size_y+j].addTexture(Alien::Colours::beige);
          break;
        }

        case 1:
        {
          aliens[i*grid_size_y+j].addTexture(Alien::Colours::blue);
          break;
        }

        case 2:
        {
          aliens[i*grid_size_y+j].addTexture(Alien::Colours::green);
          break;
        }

        case 3:
        {
          aliens[i*grid_size_y+j].addTexture(Alien::Colours::pink);
          break;
        }

        case 4:
        {
          aliens[i*grid_size_y+j].addTexture(Alien::Colours::yellow);
          break;
        }

      }
      aliens[i*grid_size_y+j].getSprite()->setPosition(window.getSize().x / 8 * 2 - 120 * grid_size_y + 80*i + 160, 25 + 45*j);
      aliens[i*grid_size_y+j].getSprite()->setScale((124/aliens[i*grid_size_y+j].getSprite()->getGlobalBounds().width) / 5 * 2,
                                                    (80/aliens[i*grid_size_y+j].getSprite()->getGlobalBounds().height) / 5 * 2);
    }
  }

  return true;
}

void Game::update(float dt)
{
  ship->getSprite()->move(ship->ship_direction.x * ship->ship_speed * dt, 0);
  if (ship->getSprite()->getPosition().x > window.getSize().x - ship->getSprite()->getGlobalBounds().width || ship->getSprite()->getPosition().x < 0)
  {
    ship->ship_direction.x = 0.f;
  }

  for (int i = 0; i < grid_size_x; i++)
  {
    for (int j = 0; j < grid_size_y; j++)
    {
      if (aliens[i*grid_size_y+j].getVisibility())
      {
        aliens[i * grid_size_y + j].getSprite()->move(
          aliens->alien_direction.x * aliens->alien_speed * dt, aliens->alien_direction.y * aliens->alien_speed * dt);
        if (quadratic_selected)
        {
          aliens[i*grid_size_y+j].getSprite()->setPosition(aliens[i*grid_size_y+j].getSprite()->getPosition().x,
                                                           0.0001 * pow(aliens[i*grid_size_y+j].getSprite()->getPosition().x - window.getSize().x / 2, 2) + ((50 * j) + quad_mod));
        }

        else if (sine_selected)
        {
          aliens[i*grid_size_y+j].getSprite()->setPosition(aliens[i*grid_size_y+j].getSprite()->getPosition().x,
                                                           25 * sin(0.01 * (aliens[i*grid_size_y+j].getSprite()->getPosition().x - window.getSize().x / 2)) + ((50 * j) + quad_mod));
        }

        if (aliens[i*grid_size_y+j].getSprite()->getPosition().x > window.getSize().x - aliens[i*grid_size_y+j].getSprite()->getGlobalBounds().width)
        {
          if (quadratic_selected || sine_selected)
          {
            quad_mod = quad_mod + window.getSize().y / 10;
          }

          for (int d = 0; d < grid_size_x; d++)
          {
            for (int k = 0; k < grid_size_y; k++)
            {
              if (normal_selected)
              {
                aliens[d * grid_size_y + k].getSprite()->setPosition(
                  aliens[d * grid_size_y + k].getSprite()->getPosition().x,
                  aliens[d * grid_size_y + k].getSprite()->getPosition().y +
                    window.getSize().y / 10);
              }


              aliens[d*grid_size_y+k].alien_direction.x = -1.f;

              aliens[d*grid_size_y+k].alien_speed = aliens[d*grid_size_y+k].alien_speed + 25;
            }
          }
        }

        else if (aliens[i*grid_size_y+j].getSprite()->getPosition().x < 0)
        {
          if (quadratic_selected || sine_selected)
          {
            quad_mod = quad_mod + window.getSize().y / 10;
          }
          for (int d = 0; d < grid_size_x; d++)
          {
            for (int k = 0; k < grid_size_y; k++)
            {
              if (normal_selected)
              {
                aliens[d * grid_size_y + k].getSprite()->setPosition(
                  aliens[d * grid_size_y + k].getSprite()->getPosition().x,
                  aliens[d * grid_size_y + k].getSprite()->getPosition().y +
                    window.getSize().y / 10);
              }
              aliens[d*grid_size_y+k].alien_direction.x = 1.f;

              aliens[d*grid_size_y+k].alien_speed = aliens[d*grid_size_y+k].alien_speed + 25;
            }
          }
        }

        else if (aliens[i*grid_size_y+j].getSprite()->getPosition().y > window.getSize().y - aliens[i*grid_size_y+j].getSprite()->getGlobalBounds().height)
        {
          intro_menu = false;
          in_menu = false;
          in_game = false;
          high_score_menu = true;
          pause_menu = false;
          paused = false;
        }
      }
    }
  }

  for (int i = 0; i < 20; i++)
  {
    if (laser[i].getVisibility())
    {
      laser[i].getSprite()->move(
        0, laser[i].laser_direction.y * laser[i].laser_speed * dt);

      if (laser[i].getSprite()->getPosition().y < 0)
      {
        player_score = player_score - 50;
        std::stringstream ps;
        ps << player_score;
        std::string player_num = ps.str();
        player_score_str.setString("Score: " + player_num);
        laser[i].laser_direction = {0.f, 0.f};
        laser[i].getSprite()->setPosition(0 - laser[i].getSprite()->getGlobalBounds().width,window.getSize().y + laser[i].getSprite()->getGlobalBounds().height);
        laser[i].setVisibility(false);
      }

      for (int j = 0; j < grid_size_x; j++)
      {
        for (int k = 0; k < grid_size_y; k++)
        {
          if (aliens[j*grid_size_y+k].getVisibility())
          {
            if (laser[i].getSprite()->getGlobalBounds().intersects(aliens[j*grid_size_y+k].getSprite()->getGlobalBounds()))
            {
              player_score = player_score + 100;
              std::stringstream ps;
              ps << player_score;
              std::string player_num = ps.str();
              player_score_str.setString("Score: " + player_num);
              laser[i].laser_direction = {0.f, 0.f};
              laser[i].getSprite()->setPosition(0 - laser[i].getSprite()->getGlobalBounds().width,window.getSize().y + laser[i].getSprite()->getGlobalBounds().height);
              laser[i].setVisibility(false);

              aliens[j*grid_size_y+k].lives = aliens[j*grid_size_y+k].lives - 1;
              if (aliens[j*grid_size_y+k].lives > 0)
              {
                aliens[j*grid_size_y+k].changeTexture(k);
              }
              else
              {
                aliens[j * grid_size_y + k].setVisibility(false);
                alien_counter -= 1;

                if (alien_counter == 0)
                {
                  intro_menu = false;
                  in_menu = false;
                  in_game = false;
                  high_score_menu = true;
                  pause_menu = false;
                  paused = false;
                }
              }
            }
          }
        }
      }
    }
  }


  //Collision

}

void Game::render()
{
  if (intro_menu)
  {
    window.draw(background);

    title.setScale(1, 1);
    title.setPosition(
      window.getSize().x / 2 - title.getGlobalBounds().width / 2,
      window.getSize().y / 2 - title.getGlobalBounds().height / 2);
    window.draw(title);

    window.draw(intro_text);
  }

  else if (in_menu)
  {
    window.draw(background);
    title.setScale(0.6, 0.6);
    title.setPosition(
      window.getSize().x / 2 - title.getGlobalBounds().width / 2,
      window.getSize().y / 8 - title.getGlobalBounds().height / 2);
    window.draw(title);
    window.draw(play_option);
    window.draw(quit_option);
  }

  else if (game_mode_menu)
  {
    window.draw(background);
    title.setScale(0.6, 0.6);
    title.setPosition(
      window.getSize().x / 2 - title.getGlobalBounds().width / 2,
      window.getSize().y / 8 - title.getGlobalBounds().height / 2);
    window.draw(title);
    window.draw(play_option);
    window.draw(quit_option);

    window.draw(normal_mode_text);
    window.draw(gravity_mode_text);
    window.draw(quadratic_mode_text);
    window.draw(sine_mode_text);

  }

  else if (pause_menu)
  {
    window.draw(background);
    window.draw(*(ship->getSprite()));
    for (int i = 0; i < grid_size_x; i++)
    {
      for (int j = 0; j < grid_size_y; j++)
      {
        if (aliens[i*grid_size_y+j].getVisibility())
        {
          window.draw(*(aliens[i * grid_size_y + j].getSprite()));
        }
      }
    }
    for (int i = 0; i < 20; i++)
    {
      if (laser[i].getVisibility())
      {
        window.draw(*(laser[i].getSprite()));
      }
    }
    window.draw(player_score_str);
    window.draw(fade_back);
    window.draw(pause_text);
    window.draw(resume_text);
    window.draw(quit_text);
  }

  else if (high_score_menu)
  {
    window.draw(background);
    player_score_str.setCharacterSize(70);
    player_score_str.setPosition(window.getSize().x / 2 - player_score_str.getGlobalBounds().width / 2,
                                 window.getSize().y / 8 - player_score_str.getGlobalBounds().height / 2);
    window.draw(player_score_str);
    if (player_score > highest_score)
    {
      highest_score = player_score;
    }
    std::stringstream hh;
    hh << highest_score;
    std::string high_num = hh.str();
    high_menu_text.setString("Highscore: " + high_num);
    high_menu_text.setPosition(
      window.getSize().x / 2 - high_menu_text.getGlobalBounds().width / 2,
      window.getSize().y / 8 * 3 - high_menu_text.getGlobalBounds().height / 2);
    window.draw(high_menu_text);
    window.draw(intro_text);
  }

  else if (in_game)
  {
    window.draw(background);
    window.draw(*(ship->getSprite()));
    for (int i = 0; i < grid_size_x; i++)
    {
      for (int j = 0; j < grid_size_y; j++)
      {
        if (aliens[i*grid_size_y+j].getVisibility())
        {
          window.draw(*(aliens[i * grid_size_y + j].getSprite()));
        }
      }
    }
    for (int i = 0; i < 20; i++)
    {
      if (laser[i].getVisibility())
      {
        window.draw(*(laser[i].getSprite()));
      }
    }

    player_score_str.setCharacterSize(25);
    player_score_str.setPosition(5,
                                 5);
    window.draw(player_score_str);
  }
}

void Game::keyPressed(sf::Event event)
{
  if (in_menu &&
      (event.key.code == sf::Keyboard::Up) ||
      (event.key.code == sf::Keyboard::Down) ||
      (event.key.code == sf::Keyboard::W) ||
      (event.key.code == sf::Keyboard::S))
  {
    if (!game_mode_menu)
    {
      play_selected = !play_selected;
      if (play_selected)
      {
        play_option.setFillColor(sf::Color(60, 215, 28, 255));
        quit_option.setFillColor(sf::Color(139, 30, 30, 100));
      }

      else
      {
        play_option.setFillColor(sf::Color(40, 158, 15, 100));
        quit_option.setFillColor(sf::Color(177, 38, 38, 255));
      }
    }
  }

  if ((game_mode_menu) &&
        (event.key.code == sf::Keyboard::Up) ||
        (event.key.code == sf::Keyboard::Down) ||
        (event.key.code == sf::Keyboard::W) ||
        (event.key.code == sf::Keyboard::S))
  {
    if (!in_game)
    {
      if (normal_selected)
      {
        normal_selected    = false;
        gravity_selected   = false;
        quadratic_selected = true;
        sine_selected      = false;

        normal_mode_text.setFillColor(sf::Color(255, 255, 255, 100));
        gravity_mode_text.setFillColor(sf::Color(255, 255, 255, 100));
        quadratic_mode_text.setFillColor(sf::Color(255, 255, 255, 255));
        sine_mode_text.setFillColor(sf::Color(255, 255, 255, 100));
      }
      else if (gravity_selected)
      {
        normal_selected    = false;
        gravity_selected   = false;
        quadratic_selected = false;
        sine_selected      = true;

        normal_mode_text.setFillColor(sf::Color(255, 255, 255, 100));
        gravity_mode_text.setFillColor(sf::Color(255, 255, 255, 100));
        quadratic_mode_text.setFillColor(sf::Color(255, 255, 255, 100));
        sine_mode_text.setFillColor(sf::Color(255, 255, 255, 255));
      }
      else if (quadratic_selected)
      {
        normal_selected    = true;
        gravity_selected   = false;
        quadratic_selected = false;
        sine_selected      = false;

        normal_mode_text.setFillColor(sf::Color(255, 255, 255, 255));
        gravity_mode_text.setFillColor(sf::Color(255, 255, 255, 100));
        quadratic_mode_text.setFillColor(sf::Color(255, 255, 255, 100));
        sine_mode_text.setFillColor(sf::Color(255, 255, 255, 100));
      }
      else if (sine_selected)
      {
        normal_selected    = false;
        gravity_selected   = true;
        quadratic_selected = false;
        sine_selected      = false;

        normal_mode_text.setFillColor(sf::Color(255, 255, 255, 100));
        gravity_mode_text.setFillColor(sf::Color(255, 255, 255, 255));
        quadratic_mode_text.setFillColor(sf::Color(255, 255, 255, 100));
        sine_mode_text.setFillColor(sf::Color(255, 255, 255, 100));
      }
    }
  }

  if ((game_mode_menu) &&
        (event.key.code == sf::Keyboard::Left) ||
        (event.key.code == sf::Keyboard::Right) ||
        (event.key.code == sf::Keyboard::A) ||
        (event.key.code == sf::Keyboard::D))
  {
    if (!in_game)
    {
      if (normal_selected)
      {
        normal_selected    = false;
        gravity_selected   = true;
        quadratic_selected = false;
        sine_selected      = false;

        normal_mode_text.setFillColor(sf::Color(255, 255, 255, 100));
        gravity_mode_text.setFillColor(sf::Color(255, 255, 255, 255));
        quadratic_mode_text.setFillColor(sf::Color(255, 255, 255, 100));
        sine_mode_text.setFillColor(sf::Color(255, 255, 255, 100));
      }
      else if (gravity_selected)
      {
        normal_selected    = true;
        gravity_selected   = false;
        quadratic_selected = false;
        sine_selected      = false;

        normal_mode_text.setFillColor(sf::Color(255, 255, 255, 255));
        gravity_mode_text.setFillColor(sf::Color(255, 255, 255, 100));
        quadratic_mode_text.setFillColor(sf::Color(255, 255, 255, 100));
        sine_mode_text.setFillColor(sf::Color(255, 255, 255, 100));
      }
      else if (quadratic_selected)
      {
        normal_selected    = false;
        gravity_selected   = false;
        quadratic_selected = false;
        sine_selected      = true;

        normal_mode_text.setFillColor(sf::Color(255, 255, 255, 100));
        gravity_mode_text.setFillColor(sf::Color(255, 255, 255, 100));
        quadratic_mode_text.setFillColor(sf::Color(255, 255, 255, 100));
        sine_mode_text.setFillColor(sf::Color(255, 255, 255, 255));
      }
      else if (sine_selected)
      {
        normal_selected    = false;
        gravity_selected   = false;
        quadratic_selected = true;
        sine_selected      = false;

        normal_mode_text.setFillColor(sf::Color(255, 255, 255, 100));
        gravity_mode_text.setFillColor(sf::Color(255, 255, 255, 100));
        quadratic_mode_text.setFillColor(sf::Color(255, 255, 255, 255));
        sine_mode_text.setFillColor(sf::Color(255, 255, 255, 100));
      }
    }
  }

  if ((paused) && (pause_menu) &&
    (event.key.code == sf::Keyboard::Up) ||
    (event.key.code == sf::Keyboard::Down) ||
    (event.key.code == sf::Keyboard::W) ||
    (event.key.code == sf::Keyboard::S))
  {
    resume_selected = !resume_selected;
    if (resume_selected)
    {
      resume_text.setFillColor(sf::Color(255,255,255,255));
      quit_text.setFillColor(sf::Color(255,255,255,100));

    }
    else
    {
      resume_text.setFillColor(sf::Color(255,255,255,100));
      quit_text.setFillColor(sf::Color(255,255,255,255));
    }

  }

  if (in_game &&
           (event.key.code == sf::Keyboard::Right) ||
           (event.key.code == sf::Keyboard::D))
  {
    ship->ship_direction.x = 1.f;
  }
  else if (in_game &&
           (event.key.code == sf::Keyboard::Left) ||
           (event.key.code == sf::Keyboard::A))
  {
    ship->ship_direction.x = -1.f;
  }

  if (event.key.code == sf::Keyboard::Enter)
  {
    if ((in_menu) && (play_selected))
    {
      in_menu = false;
      game_mode_menu = true;

    }
    else if ((in_menu) && (!play_selected))
    {
      window.close();
    }

    else if (game_mode_menu)
    {
      if (normal_selected)
      {
        gamemode(gameModes::Normal);
        intro_menu = false;
        in_menu = false;
        in_game = true;
        high_score_menu = false;
        pause_menu = false;
        paused = false;
        game_mode_menu = false;
      }

      else if (gravity_selected)
      {
        gamemode(gameModes::Gravity);
        intro_menu = false;
        in_menu = false;
        in_game = true;
        high_score_menu = false;
        pause_menu = false;
        paused = false;
        game_mode_menu = false;
      }

      else if (quadratic_selected)
      {
        gamemode(gameModes::Quadratic);
        intro_menu = false;
        in_menu = false;
        in_game = true;
        high_score_menu = false;
        pause_menu = false;
        paused = false;
        game_mode_menu = false;
      }

      else if (sine_selected)
      {
        gamemode(gameModes::Sine);
        intro_menu = false;
        in_menu = false;
        in_game = true;
        high_score_menu = false;
        pause_menu = false;
        paused = false;
        game_mode_menu = false;
      }

    }

    else if ((paused) && (resume_selected) && (pause_menu))
    {
      paused = false;
      pause_menu = false;
      in_game = true;
    }

    else if ((paused) && (!resume_selected) && (pause_menu))
    {
      paused = false;
      pause_menu = false;
      in_menu = true;
      in_game = false;
      reset();
    }
  }

  if (event.key.code == sf::Keyboard::Space)
  {
    if (intro_menu)
    {
      in_menu         = true;
      intro_menu      = false;
      high_score_menu = false;
      pause_menu      = false;
    }

    if (in_game)
    {
      for (int i = 0; i < 20; i++)
      {
        if (!laser[i].getVisibility())
        {
          laser[i].setVisibility(true);
          laser[i].getSprite()->setPosition(
            ship->getSprite()->getPosition().x + ship->getSprite()->getGlobalBounds().width / 2 -
              laser[i].getSprite()->getGlobalBounds().width / 2,
            (ship->getSprite()->getPosition().y - 10));
          laser[i].laser_direction = { 0.f, -1.f };
          break;
        }
      }
    }

    if (high_score_menu)
    {
      intro_menu = false;
      in_menu = true;
      in_game = false;
      high_score_menu = false;
      pause_menu = false;
      paused = false;
      reset();
    }
  }

  if (event.key.code == sf::Keyboard::Escape)
  {
    if (in_game)
    {
      paused = !paused;

      if (paused)
      {
        in_menu         = false;
        intro_menu      = false;
        high_score_menu = false;
        pause_menu      = true;
        in_game         = true;
      }
      else if (!paused)
      {
        in_menu         = false;
        intro_menu      = false;
        high_score_menu = false;
        pause_menu      = false;
        in_game         = true;
      }
    }
  }
}

void Game::mouseMove(sf::Event event)
{
  if (in_menu)
  {
    if ((play_option.getGlobalBounds().contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y)) &&
        (!play_selected))
    {
      play_selected = true;
      play_option.setString("Start Game");
      play_option.setFillColor(sf::Color (60, 215, 28, 255));

      quit_option.setString("Quit");
      quit_option.setFillColor(sf::Color(139,30,30,100));
    }

    else if ((quit_option.getGlobalBounds().contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y)) &&
             (play_selected))
    {
      play_selected = false;
      play_option.setString("Start Game");
      play_option.setFillColor(sf::Color (40, 158, 15, 100));

      quit_option.setString("Quit");
      quit_option.setFillColor(sf::Color(177,38,38,255));
    }
  }

  else if (game_mode_menu)
  {
    if ((normal_mode_text.getGlobalBounds().contains(
          sf::Mouse::getPosition().x, sf::Mouse::getPosition().y)))
    {
      normal_selected    = true;
      gravity_selected   = false;
      quadratic_selected = false;
      sine_selected      = false;

      normal_mode_text.setFillColor(sf::Color(255, 255, 255, 255));
      gravity_mode_text.setFillColor(sf::Color(255, 255, 255, 100));
      quadratic_mode_text.setFillColor(sf::Color(255, 255, 255, 100));
      sine_mode_text.setFillColor(sf::Color(255, 255, 255, 100));
    }
    if ((gravity_mode_text.getGlobalBounds().contains(
          sf::Mouse::getPosition().x, sf::Mouse::getPosition().y)))
    {
      normal_selected    = false;
      gravity_selected   = true;
      quadratic_selected = false;
      sine_selected      = false;

      normal_mode_text.setFillColor(sf::Color(255, 255, 255, 100));
      gravity_mode_text.setFillColor(sf::Color(255, 255, 255, 255));
      quadratic_mode_text.setFillColor(sf::Color(255, 255, 255, 100));
      sine_mode_text.setFillColor(sf::Color(255, 255, 255, 100));
    }
    if ((quadratic_mode_text.getGlobalBounds().contains(
          sf::Mouse::getPosition().x, sf::Mouse::getPosition().y)))
    {
      normal_selected    = false;
      gravity_selected   = false;
      quadratic_selected = true;
      sine_selected      = false;

      normal_mode_text.setFillColor(sf::Color(255, 255, 255, 100));
      gravity_mode_text.setFillColor(sf::Color(255, 255, 255, 100));
      quadratic_mode_text.setFillColor(sf::Color(255, 255, 255, 255));
      sine_mode_text.setFillColor(sf::Color(255, 255, 255, 100));
    }
    if ((sine_mode_text.getGlobalBounds().contains(
          sf::Mouse::getPosition().x, sf::Mouse::getPosition().y)))
    {
      normal_selected    = false;
      gravity_selected   = false;
      quadratic_selected = false;
      sine_selected      = true;

      normal_mode_text.setFillColor(sf::Color(255, 255, 255, 100));
      gravity_mode_text.setFillColor(sf::Color(255, 255, 255, 100));
      quadratic_mode_text.setFillColor(sf::Color(255, 255, 255, 100));
      sine_mode_text.setFillColor(sf::Color(255, 255, 255, 255));
    }
  }

  if ((paused) && (pause_menu))
  {
    if ((resume_text.getGlobalBounds().contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y)) &&
        (!resume_selected))
    {
      resume_selected = true;
      resume_text.setFillColor(sf::Color(255,255,255,255));

      quit_text.setFillColor(sf::Color(255,255,255,100));
    }

    else if ((quit_text.getGlobalBounds().contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y)) &&
             (resume_selected))
    {
      resume_selected = false;
      resume_text.setFillColor(sf::Color(255,255,255,100));

      quit_text.setFillColor(sf::Color(255,255,255,255));
    }
  }
}

void Game::mouseClicked(sf::Event event)
{
  //get the click position
  sf::Vector2i click = sf::Mouse::getPosition(window);
  if (in_menu)
  {
    if ((play_option.getGlobalBounds().contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y)) &&
        (play_selected))
    {
      in_menu = false;
      game_mode_menu = true;
    }

    else if ((quit_option.getGlobalBounds().contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y)) &&
             (!play_selected))
    {
      window.close();
    }
  }

  else if ((game_mode_menu) && (!in_game))
  {
    if ((normal_mode_text.getGlobalBounds().contains(
      sf::Mouse::getPosition().x, sf::Mouse::getPosition().y)))
    {
      gamemode(gameModes::Normal);
      intro_menu = false;
      in_menu = false;
      in_game = true;
      high_score_menu = false;
      pause_menu = false;
      paused = false;
      game_mode_menu = false;
    }

    else if ((gravity_mode_text.getGlobalBounds().contains(
      sf::Mouse::getPosition().x, sf::Mouse::getPosition().y)))
    {
      gamemode(gameModes::Gravity);
      intro_menu = false;
      in_menu = false;
      in_game = true;
      high_score_menu = false;
      pause_menu = false;
      paused = false;
      game_mode_menu = false;
    }

    else if ((quadratic_mode_text.getGlobalBounds().contains(
      sf::Mouse::getPosition().x, sf::Mouse::getPosition().y)))
    {
      gamemode(gameModes::Quadratic);
      intro_menu = false;
      in_menu = false;
      in_game = true;
      high_score_menu = false;
      pause_menu = false;
      paused = false;
      game_mode_menu = false;
    }

    else if ((sine_mode_text.getGlobalBounds().contains(
      sf::Mouse::getPosition().x, sf::Mouse::getPosition().y)))
    {
      gamemode(gameModes::Sine);
      intro_menu = false;
      in_menu = false;
      in_game = true;
      high_score_menu = false;
      pause_menu = false;
      paused = false;
      game_mode_menu = false;
    }
  }

  if ((paused) && (pause_menu))
  {
    if ((resume_text.getGlobalBounds().contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y)) &&
        (resume_selected))
    {
      paused = false;
      pause_menu = false;
      in_game = true;
    }

    else if ((quit_text.getGlobalBounds().contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y)) &&
             (!resume_selected))
    {
      paused = false;
      pause_menu = false;
      in_menu = true;
      in_game = false;
      reset();
    }
  }

}

void Game::keyReleased(sf::Event event)
{
  if (in_game &&
           (event.key.code == sf::Keyboard::Right) ||
           (event.key.code == sf::Keyboard::D))
  {
    ship->ship_direction.x = 0;
  }
  else if (in_game &&
           (event.key.code == sf::Keyboard::Left) ||
           (event.key.code == sf::Keyboard::A))
  {
    ship->ship_direction.x = 0;
  }
}

void Game::reset()
{
  player_score = 0;
  std::stringstream ps;
  ps << player_score;
  std::string player_num = ps.str();
  player_score_str.setString("Score: " + player_num);

  ship->getSprite()->setPosition(window.getSize().x / 2,
                                 window.getSize().y - ship->getSprite()->getGlobalBounds().height - 5);

  for (int i = 0; i < grid_size_x; i++)
  {
    for (int j = 0; j < grid_size_y; j++)
    {
      aliens[i*grid_size_y+j].getSprite()->setPosition(window.getSize().x / 8 * 2 - 120 * grid_size_y + 80*i + 160, 25 + 45*j);
      aliens[i*grid_size_y+j].setVisibility(true);
      aliens[i*grid_size_y+j].alien_direction.x = 1.f;
      aliens[i*grid_size_y+j].alien_direction.y = 0.f;
      aliens[i*grid_size_y+j].alien_speed = 50;
    }
  }

  for (int i = 0; i < 20; i++)
  {
    laser[i].laser_direction = {0.f, 0.f};
    laser[i].getSprite()->setPosition(0 - laser[i].getSprite()->getGlobalBounds().width,window.getSize().y + laser[i].getSprite()->getGlobalBounds().height);
    laser[i].setVisibility(false);
  }
}

void Game::gamemode(gameModes mode)
{
  if (mode == gameModes::Normal)
  {

  }

  if (mode == gameModes::Gravity)
  {
    for (int i = 0; i < grid_size_x; i++)
    {
      for (int j = 0; j < grid_size_y; j++)
      {
        aliens[i*grid_size_y+j].alien_direction.y = 0.1;
      }
    }
  }

  if (mode == gameModes::Quadratic)
  {
    for (int i = 0; i < grid_size_x; i++)
    {
      for (int j = 0; j < grid_size_y; j++)
      {
        aliens[i*grid_size_y+j].alien_direction = {1.f, 0.f};

      }
    }
  }

  if (mode == gameModes::Sine)
  {
    for (int i = 0; i < grid_size_x; i++)
    {
      for (int j = 0; j < grid_size_y; j++)
      {
        aliens[i*grid_size_y+j].alien_direction = {1.f, 0.f};
      }
    }
  }
}