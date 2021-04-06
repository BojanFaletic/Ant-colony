#pragma once

#include "base.hpp"

struct Food : public Base {
  sf::RectangleShape food;
  u32 life;
  sf::Vector2f size{20, 20};


  Food() {
    int master_x = 50;
    food.setPosition(master_x, master_x);
    food.setSize(size);
    sf::Color col{RGBA_to_hex(200, 0, 160, 255)};
    food.setFillColor(col);
    life = 10;
  }

  void update_color(u32 level){
      u32 scope = 255/10;
      sf::Color col{RGBA_to_hex(200, 0, 160, scope*level)};
      food.setFillColor(col);
  }

  void display(sf::RenderWindow &w) { w.draw(food); }

  sf::Vector2f position() { return food.getPosition(); }
};