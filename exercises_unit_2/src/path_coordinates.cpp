#include "robot_commander/robot_commander.h"
#include <iostream>
#include <ros/ros.h>
#include <set>

int main(int argc, char **argv) {
  ros::init(argc, argv, "path_coordinates");

  RobotCommander my_robot;

  float side_length = 1.5;

  // greater stores in reverse order alphabetically, not needed but here for
  // demo
  std::set<std::string, std::greater<std::string>> pentagon_position_set;

  std::multiset<std::string, std::greater<std::string>>
      pentagon_position_multiset;

  for (int i = 0; i < 5; i++) {
    my_robot.move_forward(side_length);
    my_robot.stop_moving();
    my_robot.turn(1.2566, 1); // 2pi / 5
    my_robot.stop_moving();
    float x = my_robot.get_x_position();
    float y = my_robot.get_y_position();
    std::string coordinate =
        "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
    pentagon_position_set.insert(coordinate);
    pentagon_position_multiset.insert(coordinate);
  }

  std::cout << std::endl << "First the set: " << std::endl;
  for (const auto &coord : pentagon_position_set) {
    std::cout << coord << " " << std::endl;
  }
  std::cout << std::endl << std::endl;

  std::cout << std::endl << "Now the multiset: " << std::endl;
  for (const auto &coord : pentagon_position_multiset) {
    std::cout << coord << " " << std::endl;
  }
  std::cout << std::endl << std::endl;

  return 0;
}