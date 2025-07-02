#include "robot_commander/robot_commander.h"
#include <iostream>
#include <ros/ros.h>
#include <vector>

// The starter code:

// Creates a standard C++ main function
// Initializes a ros node named "heading_vector" by calling ros::init(argc,
// argv, "heading_vector"); Creates an object of type RobotCommander Uses the
// move_in_circles() method of the RobotCommander class so that the robot moves
// continuously while we capture data Asks the user to input the number of
// values to be captured Stops the robot before the program exits In your part
// of the code you will have to:

// Declare a vector object for storing float values, you can name it headings
// Use the get_heading() method of the RobotCommander class to retieve the
// current robot heading Populate the headings vector with the values that you
// get Print the each collected data value to the console at the time it gets
// collected, like so:

// Collecting heading value: 1.30604
// Collecting heading value: 1.41361
// Collecting heading value: 1.53096
// Collecting heading value: 1.65808

// Preferably pause your program for one second before you retieve a new robot
// heading value If you are using the starter code, you will have the number to
// data values to be collected as the interger total_values. When the number of
// data values collected reaches total_values, print all elements of the
// headings vector. Additionally you will have to modify the file CMakeLists.txt
// in order to build your executable.

int main(int argc, char **argv) {
  ros::init(argc, argv, "heading_vector");

  RobotCommander my_robot;

  // command the robot to keep going in circles
  my_robot.move_in_circles();

  int total_values;
  std::cout << "Enter the number of heading values that you want to capture: ";
  // get user input from the keyboard
  std::cin >> total_values;

  // INSERT YOUR CODE BELOW THIS LINE
  std::vector<float> headings;
  float heading;
  for (int i = 0; i < total_values; i++) {
    heading = my_robot.get_heading();
    std::cout << "Collecting heading value: " << heading << std::endl;
    headings.push_back(heading);
    ros::Duration(1).sleep();
    // usleep(1000000);
  }

  std::cout << "Displaying saved data:" << std::endl;
  for (int i = 0; i < total_values; i++) {
    std::cout << "  Heading value " << i << ": " << heading << std::endl;
  }

  // INSERT YOUR CODE ABOVE THIS LINE

  // stop the robot
  my_robot.stop_moving();

  return 0;
}