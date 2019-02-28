//Anthony Tung

#include <SFML/Graphics.hpp>
#include <time.h>
#include "snake.hpp"
#include "snake.cpp"

using namespace sf;

int main()
{
  srand(time(0));

  RenderWindow window(VideoMode(w, h), "Snake Game!");

  Texture t1, t2;
  t1.loadFromFile("images/white.png");
  t2.loadFromFile("images/red.png");

  Sprite sprite1(t1);
  Sprite sprite2(t2);

  Clock clock;
  float timer = 0, delay = 0.1;

  f.x = 10;
  f.y = 10;

  while (window.isOpen()) {
    float time = clock.getElapsedTime().asSeconds();
    clock.restart();
    timer += time;

    Event e;
    while (window.pollEvent(e)) {
      if (e.type == Event::Closed)
        window.close();
    }

    if (Keyboard::isKeyPressed(Keyboard::Left))
      dir = 1;
    if (Keyboard::isKeyPressed(Keyboard::Right))
      dir = 2;
    if (Keyboard::isKeyPressed(Keyboard::Up))
      dir = 3;
    if (Keyboard::isKeyPressed(Keyboard::Down))
      dir = 0;

    if (timer > delay) {
      timer = 0;
      Tick();
    }

    ////// draw  ///////
    window.clear();

    for (int i = 0; i < N; i++)
      for (int j = 0; j < M; j++) {
        sprite1.setPosition(i * size, j * size);
        window.draw(sprite1);
      }

    for (int i = 0; i < num; i++) {
      sprite2.setPosition(s[i].x * size, s[i].y * size);
      window.draw(sprite2);
    }

    sprite2.setPosition(f.x * size, f.y * size);
    window.draw(sprite2);

    window.display();
  }

  return 0;
}
