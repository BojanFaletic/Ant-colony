#pragma once

#include "base.hpp"

struct Home : public Base {
  sf::RectangleShape home;
  sf::Vector2f size{40, 40};

  Home() {
    int master_x = 200;
    home.setPosition(master_x, master_x);
    home.setSize(size);
    sf::Color col{RGBA_to_hex(200, 180, 30, 255)};
    home.setPosition(200,200);
    home.setFillColor(col);
  }

  void display(sf::RenderWindow &w) { w.draw(home); }
};