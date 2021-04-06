#pragma once

#include "base.hpp"
#include "food.hpp"

// https://www.hexcolortool.com/

const int num_of_particles = 10;

struct Ant : public Base {
  sf::RectangleShape master;
  vector<sf::RectangleShape> tail;
  sf::Color found_food{200, 60, 30, 255};
  sf::Color normal_mode{0,13,200,200};

  Ant() {
    int master_x = 200;
    master.setPosition(master_x, master_x);
    sf::Vector2f size{10, 10};
    master.setSize(size);
    master.setFillColor(sf::Color::Green);

    for (int i = 0; i < num_of_particles; i++) {
      sf::RectangleShape tmp;
      tmp.setSize(master.getSize());
      u32 scale = 200 / num_of_particles;
      sf::Color col{RGBA_to_hex(0, 130, 200, 200 - i * scale)};
      tmp.setFillColor(col);
      tmp.setPosition(master_x, master_x);
      tail.push_back(tmp);
    }
  };

  void display(sf::RenderWindow &w) {
    w.draw(master);
    for (int i = 0; i < tail.size(); i++) {
      w.draw(tail[i]);
    }
  }

  void update(Food &f) {
    static int frame_cnt = 0;
    frame_cnt++;

    int delta = 10;

    if (frame_cnt % 2 == 0) {
      enum dir { RIGHT, DOWN, LEFT, UP };
      vector<dir> invalid_moves;
      sf::Vector2f master_pos = master.getPosition();
      if (master_pos.x < 5) {
        invalid_moves.push_back(dir::LEFT);
      }
      if (master_pos.x > 400 - 5) {
        invalid_moves.push_back(dir::RIGHT);
      }
      if (master_pos.y > 400 - 5) {
        invalid_moves.push_back(dir::DOWN);
      }
      if (master_pos.y < 5) {
        invalid_moves.push_back(dir::UP);
      }
      int dir = 0;
      do {
        dir = rand() % 4;
      } while (find(invalid_moves.begin(), invalid_moves.end(), dir) !=
               invalid_moves.end());
      sf::Vector2f velocity{0, 0};

      switch (dir) {
      case 0:
        velocity.x += delta;
        break;
      case 1:
        velocity.y += delta;
        break;
      case 2:
        velocity.x -= delta;
        break;
      case 3:
        velocity.y -= delta;
        break;
      default:
        break;
      }

      frame_cnt = 0;
      sf::Vector2f master_pos_new = master_pos;
      master_pos_new += velocity;

      master.setPosition(master_pos_new);

      // check for food
      auto fod_pos = f.position();
      u32 size = f.size.x;

      auto in_range = [&]{
        return master_pos.x >= fod_pos.x && master_pos.x <= fod_pos.x+size &&
        master_pos.y >= fod_pos.y && master_pos.y <= fod_pos.y+size;
      };

      if (in_range()){
        cout << "eaten";
        f.life--;
        f.update_color(f.life);

        if (f.life == 0) {
          // new position
          f.life = 10;
          u32 new_x = rand() % 400;
          u32 new_y = rand() % 400;
          f.food.setPosition(sf::Vector2f{(float)new_x, (float)new_y});
        }
      }

      tail[0].setPosition(master_pos);
      for (int i = tail.size() - 1; i > 0; i--) {
        tail[i].setPosition(tail[i - 1].getPosition());
      }
    }
  }
};