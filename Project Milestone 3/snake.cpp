// Anthony Tung
// OOP Milestone 3

#include "snake.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>

using namespace sf;

// Function allows the snake to move around using coordinates
void windows::Tick()
{
  for (int i = num; i > 0; --i) {
    s[i].x = s[i - 1].x;
    s[i].y = s[i - 1].y;
  }

  if (dir == 0)
    s[0].y += 1;
  if (dir == 1)
    s[0].x -= 1;
  if (dir == 2)
    s[0].x += 1;
  if (dir == 3)
    s[0].y -= 1;

  if ((s[0].x == f.x) && (s[0].y == f.y)) {
    num++;
    f.x = rand() % N;
    f.y = rand() % M;
  }

  if (s[0].x > N)
    s[0].x = 0;
  if (s[0].x < 0)
    s[0].x = N;
  if (s[0].y > M)
    s[0].y = 0;
  if (s[0].y < 0)
    s[0].y = M;

  for (int i = 1; i < num; i++)
    if (s[0].x == s[i].x && s[0].y == s[i].y)
      num = i;
}

// Function loads in the texture from the file that was originally provided, and this function creates the game window.
void Windows::CreateWindow()
{
    //Generate a random number
    srand(static_cast<unsigned int>(time(NULL)));

    //Create a game Window
    sf::RenderWindow window(sf::VideoMode(width, height), "Snake");
    sf::Texture text1, text2, text3, text4, text5, text6, text7;

    // Loads images used for snake game, and 4 new colors were added
    text1.loadFromFile("/Users/Anthony/Desktop/Snake/images/white.png");
    text2.loadFromFile("/Users/Anthony/Desktop/Snake/images/red.png");
    text3.loadFromFile("/Users/Anthony/Desktop/Snake/images/maroon.png");
    text4.loadFromFile("/Users/Anthony/Desktop/Snake/images/purple.png");
    text5.loadFromFile("/Users/Anthony/Desktop/Snake/images/yellow.png");
    text6.loadFromFile("/Users/Anthony/Desktop/Snake/images/blue.png");
    text7.loadFromFile("/Users/Anthony/Desktop/Snake/images/green.png");

    sf::Sprite sprite1(text1), sprite2(text2), sprite3(text3), sprite4(text4), sprite5(text5), sprite6(text6), sprite7(text7);
    sf::Clock clock;

    f.x = 10;
    f.y = 10;

    int var = 0;
    bool decision = true;


    float time = clock.getElapsedTime().asSeconds();

    clock.restart();
    timer += time;

    sf::Event event;

    while(window.pollEvent(event))

        if(event.type == sf::Event::Closed)
            window.close();

        //Keyboard controls which were provided in the original code
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            dir = 1;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            dir = 2;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            dir = 3;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            dir = 0;
        if(timer > delay)
        {
            timer = 0;

            Tick();
        }

        window.clear();

        for(int counter = 0; counter < N; ++counter)
            for(int innerCounter = 0; innerCounter < M; ++innerCounter)
            {
                sprite1.setPosition(counter * size, innerCounter * size);
                window.draw(sprite1);
            }
        for(int counter = 0; counter < num; ++counter)
        {
            sprite2.setPosition(s[counter].x * size, s[counter].y * size);
            window.draw(sprite2);
        }

        var = num % 6;

        //The time will depend on the length of snake
        switch(var)
        {
            case 1:
                sprite3.setPosition(f.x * size, f.y * size);
                window.draw(sprite3);
                decision = true;
                break;
            case 2:
                sprite4.setPosition(f.x * size, f.y * size);
                window.draw(sprite4);
                decision = true;
                break;
            case 3:
                sprite5.setPosition(f.x * size, f.y * size);
                window.draw(sprite5);
                if(decision == true)
                    delay = delay - 0.01;
                decision = false;
                break;
            case 4:
                sprite6.setPosition(f.x * size, f.y * size);
                window.draw(sprite6);
                decision = true;
                break;
            case 5:
                sprite2.setPosition(f.x * size, f.y * size);
                window.draw(sprite2);
                decision = true;
                break;
            case 6:
                sprite7.setPosition(f.x * size, f.y * size);
                window.draw(sprite7);
                decision = true;
                break;
        }

        window.display();
}
