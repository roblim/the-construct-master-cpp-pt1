#include "robot_commander/robot_commander.h"
#include <array>
#include <iostream>
#include <ros/ros.h>
#include <set>

using namespace std;

// In your code you will have to:

// Make the robot trace a polygonal path (of your choice).
// Use the methods move_forward(int time) to move forward for n seconds and
// move_backward(int time) to move backwards for n seconds. Use the method
// turn(float velocity_value, int n_secs) to turn the robot. Specify the
// velocity (in rad/s) with velocity_value and the duration of the turn with
// n_secs. Use the method stop_moving() for stopping the robot. Store the (X,Y)
// coordinates of the vertex of the plygon traced in a set. Use the methods
// get_x_position() and get_y_position() to get the current coordinates. Print
// the (X,Y) coordinates of the vertex. Change the code to store the coordinates
// in a multiset to observe the difference.

array<float, 2> get_coord_array(RobotCommander robot) {
  return {robot.get_x_position(), robot.get_y_position()};
}

int main(int argc, char *argv[]) {
  constexpr double pi = 3.14159265358979323846;

  ros::init(argc, argv, "path_coords");
  RobotCommander my_robot;
  // set<array<float, 2>> coord_set;
  multiset<array<float, 2>> coord_set;

  // insert start vertex of square
  coord_set.insert(get_coord_array(my_robot));

  // move to 2nd vertex and insert coords
  my_robot.move_forward(4);
  coord_set.insert(get_coord_array(my_robot));

  // turn 90 degrees (1.57 rad)
  my_robot.turn(pi / 2, 1);

  // move to 3rd vertex and insert coords
  my_robot.move_forward(4);
  coord_set.insert(get_coord_array(my_robot));

  // turn 90 degrees (1.57 rad)
  my_robot.turn(pi / 2, 1);

  // move to 4th vertex and insert coords
  my_robot.move_forward(4);
  coord_set.insert(get_coord_array(my_robot));

  // turn 90 degrees (1.57 rad)
  my_robot.turn(pi / 2, 1);

  // move to start vertex and insert coords
  my_robot.move_forward(4);
  coord_set.insert(get_coord_array(my_robot));

  cout << "The vertices of the square are: " << endl;

  for (const auto &vertex : coord_set) {
    cout << "  "
         << "(" << vertex[0] << ", " << vertex[1] << ")" << endl;
  }

  return 0;
}