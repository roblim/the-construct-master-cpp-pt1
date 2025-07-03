#include "robot_commander/robot_commander.h"
#include <forward_list>
#include <iostream>
#include <list>
#include <ros/ros.h>

// Tasks:

// - Add a new blank file named lists.cpp inside the src directory of the
// exercises_unit_2 package.
// - Create a list named laser and add the following to it: range_max,
// range_min, angle_max and angle_min.
// - Access the first, third, and third from last elements of the list using the
// begin() and end() functions.
// - Try the same with the forward list and display the results.

void showlist(std::list<float> k) {
  for (float i : k) {
    std::cout << i << " ";
  }
  std::cout << "\n";
}

void show_fl(std::forward_list<float> k) {
  for (float i : k) {
    std::cout << i << " ";
  }
  std::cout << "\n";
}

// int main(int argc, char **argv) {
int main(int argc, char *argv[]) {
  ros::init(argc, argv, "laser_list");
  RobotCommander my_robot;

  // std::list<float> laser = {my_robot.range_max(), my_robot.range_min(),
  //                           my_robot.angle_max(), my_robot.angle_min()};
  std::list<float> laser = {30, 0.1, 180, 0};
  std::cout << "Laser list: ";
  showlist(laser);

  // std::list<float>::iterator list_it = laser.begin();
  auto list_it = laser.begin();
  std::cout << "Range max: " << *list_it << std::endl;
  std::advance(list_it, 2);
  std::cout << "Angle max: " << *list_it << std::endl;

  list_it = laser.begin();
  std::advance(list_it, laser.size() - 3);
  std::cout << "Range min: " << *list_it << std::endl;

  std::forward_list<float> fl_laser = {30, 0.1, 180, 0};
  std::cout << "Laser forward list: ";
  show_fl(fl_laser);

  auto fwd_list_it = fl_laser.begin();
  std::cout << "Range max (fwd list): " << *fwd_list_it << std::endl;
  std::advance(fwd_list_it, 2);
  std::cout << "Angle max (fwd list): " << *fwd_list_it << std::endl;

  const int k = 3; // "third from last"
  auto fwd_list_lead = fl_laser.begin();

  for (int i = 0; i < k; ++i) {
    if (fwd_list_lead == fl_laser.end()) {
      std::cout << "List too short!\n";
      return 1;
    }
    ++fwd_list_lead;
  }

  auto fwd_list_trail = fl_laser.begin();
  while (fwd_list_lead != fl_laser.end()) {
    ++fwd_list_lead;
    ++fwd_list_trail;
  }

  std::cout << "Range min (fwd list): " << *fwd_list_trail << std::endl;
  return 0;
}


// solution for list
// #include<iostream>
// #include<list>
// using namespace std;

// int main(){
    
//     list<string> laser{"range_max","range_min","angle_max","angle_min"};
   
//     //iterator laser_front starts to point the first element of the list
//     auto laser_front = laser.begin();
//     //Jump 2 more times as you are already on the first element
//     advance(laser_front, 2);
//     // * is used to tell the value of what is being pointed by the iterator
//     cout << *laser_front << '\n';

//     //iterator laser_front starts to point the past-the-end element of the list
//     laser_front = laser.end();
//     //Jump back to the third element from last
//     laser_front = next(laser_front, -3);
//     cout << *laser_front<< '\n';


//     return 0;
// }

// solution for forward list

// #include<iostream>
// #include<forward_list>
// using namespace std;

// int main(){

//     forward_list<string> laser{"range_max","range_min","angle_max","angle_min"};
//     //iterator laser_front starts to point the first element of the list
//     auto laser_front = laser.begin();
//     //Jump 2 more times as you are already on the first element
//     advance(laser_front, 2);
//     // * is used to tell the value of what is being pointed by the iterator
//     cout << *laser_front << '\n';

//     //iterator laser_front starts to point the past-the-end element of the list
//     laser_front = laser.end();
//     //Jump back to the third element from last
//     laser_front = next(laser_front, -3);
//     cout << *laser_front<< '\n';


//     return 0;
// }