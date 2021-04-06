#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>
#include <stdint.h>
#include <vector>

typedef uint32_t u32;
using namespace std;

struct Base {
  u32 RGBA_to_hex(u32 R, u32 G, u32 B, u32 alpha) {
    u32 color = 0;
    color |= R;
    color <<= 8;
    color |= G;
    color <<= 8;
    color |= B;
    color <<= 8;
    color |= alpha;
    return color;
  }

};
