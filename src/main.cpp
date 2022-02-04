#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Alien.h"


int main()
{
  std::cout << "You should see a window that opens as well as this writing to console..."
            << std::endl;

  int initial_Width = sf::VideoMode::getDesktopMode().width;
  int initial_Height = sf::VideoMode::getDesktopMode().height;

  // create window and set up
  sf::RenderWindow window(sf::VideoMode(initial_Width, initial_Height), "Space Invaders!", sf::Style::Fullscreen);
  window.setFramerateLimit(60);

  // A Clock starts counting as soon as it's created
  sf::Clock clock;

  //initialise an instance of the game class
  Game game(window);

  //run the init function of the game class and check it all initialises ok
  if (!game.init())
  {
    return 0;
  }


  // Game loop: run the program as long as the window is open
  while (window.isOpen())
  {
    // check all the window's events that were triggered since the last iteration of the loop
    sf::Event event;

    //calculate delta time
    sf::Time time = clock.restart();
    float dt = time.asSeconds();

    //'process inputs' element of the game loop
    while (window.pollEvent(event))
    {
      // "close requested" event: we close the window
      if (event.type == sf::Event::Closed)
        window.close();

      if (event.type == sf::Event::KeyPressed)
      {
        game.keyPressed(event);
      }

      if (event.type == sf::Event::KeyReleased)
      {
        game.keyReleased(event);
      }

      if (event.type == sf::Event::MouseButtonPressed)
      {
        game.mouseClicked(event);
      }

      if (event.type == sf::Event::MouseMoved)
      {
        game.mouseMove(event);
      }
    }

    if ((!game.paused) && (game.in_game))
    {
      //'update' element of the game loop
      game.update(dt);
    }

    game.timeSinceLastUpdate += game.elapsed;

    window.clear(sf::Color::Black);

    //'render' element of the game loop
    game.render();
    window.display();
  }

  return 0;
}
