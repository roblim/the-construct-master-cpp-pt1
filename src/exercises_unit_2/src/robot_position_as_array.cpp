#include "robot_commander/robot_commander.h"
#include <iostream>
#include <ros/ros.h>

int main(int argc, char **argv) {
  ros::init(argc, argv, "position_array");
  RobotCommander my_robot;

  float pos_array[3];

  pos_array[0] = my_robot.get_x_position();
  pos_array[1] = my_robot.get_y_position();
  pos_array[2] = my_robot.get_z_position();

  std::cout << pos_array[0] << " ";
  std::cout << pos_array[1] << " ";
  std::cout << pos_array[2] << "\n";

  //   for (int i = 0; i < 3; i++) {
  //     std::cout << my_array[i] << " ";
  //     std::cout << std::endl;
  //   }

  return 0;
}