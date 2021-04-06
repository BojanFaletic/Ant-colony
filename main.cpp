#include <SFML/Graphics.hpp>
#include <iostream>

#include "ant.hpp"
#include "food.hpp"
#include "home.hpp"

int main() {
  sf::RenderWindow window(sf::VideoMode(400, 400), "Ant game");

  window.setFramerateLimit(30);
  sf::RectangleShape shape;
  sf::Vector2f size{10, 10};
  shape.setSize(size);
  shape.setOutlineColor(sf::Color::Red);
  shape.setOutlineThickness(5);
  shape.setPosition(20, 20);

  vector<Ant> a;
  for (int i = 0; i < 10; i++) {

    a.push_back(Ant());
  }
  Food f;
  Home h;

  while (window.isOpen()) {
    sf::Event event;

    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }
    window.setActive();
    // window.draw(shape);

    auto current_pos = shape.getPosition();
    current_pos.x += 1;
    shape.setPosition(current_pos);

    for (auto &el : a) {
      el.display(window);
      el.update(f);
    }
    h.display(window);

    f.display(window);

    // drawing window
    window.display();
    window.clear();
  }
}