#include "../include/test_library/test_library.h"

void display_pos(float x, float y) {

  float pos_x = x;
  float pos_y = y;
  std::cout << "Position X: " << pos_x << " Position Y: " << pos_y << std::endl;
}

void display_velocity(float linear, float angular) {
  std::cout << "Linear velocity: " << linear << " Angular Velocity: " << angular
            << std::endl;
}