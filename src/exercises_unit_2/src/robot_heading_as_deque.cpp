#include "robot_commander/robot_commander.h"
#include <deque>
#include <iostream>
#include <ros/ros.h>

// The starter code:

// - Creates a standard C++ main function
// - Initializes a ros node named "heading_deque" by calling ros::init(argc,
// argv, "heading_deque");
// - Creates an object of type RobotCommander
// - Uses the move_in_circles() method of the RobotCommander class so that the
// robot moves continuously while we capture data
// - Asks the user to input the number of values to be captured
// - Stops the robot before the program exits

// In your part of the code you will have to:

// - Declare a deque object for storing float values, you can name it headings
// - Use the get_heading() method of the RobotCommander class to retieve the
// current robot heading
// - Add the heading data to the front of the deque container
// - Print the each collected data value to the console at the time it gets
// collected, like so:

// Collecting heading value: 1.30604
// Collecting heading value: 1.41361
// Collecting heading value: 1.53096
// Collecting heading value: 1.65808

// - As before, it is recommended to pause your program for one
// second each time you retrieve new data
// - From what's implemented by the starter code, you will have the number to
// data values to be collected as the interger total_values
// - When the number of data values collected reaches total_values, print all
// elements of the headings deque
// - Confirm that the values are printed starting with the last collected value
// first and ending with the first value added to the deque

// - Remember that you will have to modify the CMakeLists.txt script to build
// your executable.

// Expected output:

// [ INFO] [1648727125.240518638]: Initializing node
// [ INFO] [1648727127.298828409, 531.733000000]: Moving in circles
// Enter the number of heading values that you want to capture: 5
// Collecting heading value: -1.07757
// Collecting heading value: -0.960217
// Collecting heading value: -0.813532
// Collecting heading value: -0.696179
// Collecting heading value: -0.578831

// Displaying saved data
// Heading value 0: -0.578831
// Heading value 1: -0.696179
// Heading value 2: -0.813532
// Heading value 3: -0.960217
// Heading value 4: -1.07757
// [ INFO] [1648727137.847149787, 537.655000000]: Stopping the robot

int main(int argc, char **argv) {
  ros::init(argc, argv, "heading_deque");

  RobotCommander my_robot;

  // command the robot to keep going in circles
  my_robot.move_in_circles();

  int total_values;
  std::cout << "Enter the number of heading values that you want to capture: ";
  // get user input from the keyboard
  std::cin >> total_values;

  // INSERT YOUR CODE BELOW THIS LINE
  std::deque<float> headings;
  float heading;
  for (int i = 0; i < total_values; i++) {
    heading = my_robot.get_heading();
    std::cout << "Collecting heading value: " << heading << std::endl;
    headings.push_front(heading);
    ros::Duration(1).sleep();
    // usleep(1000000);
  }

  std::cout << "Displaying saved data:" << std::endl;
  for (int i = 0; i < total_values; i++) {
    std::cout << "  Heading value " << i << ": " << headings.at(i) << std::endl;
  }

  // INSERT YOUR CODE ABOVE THIS LINE

  // stop the robot
  my_robot.stop_moving();

  return 0;
}