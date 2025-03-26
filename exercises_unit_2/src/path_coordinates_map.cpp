#include "robot_commander/robot_commander.h"
#include <iostream>
#include <map>
#include <ros/ros.h>
#include <unordered_map>

int main(int argc, char **argv) {
  ros::init(argc, argv, "path_coordinates");

  RobotCommander my_robot;

  float side_length = 1.5;

  std::map<int, std::string> coordinates_map;

  for (int i = 0; i < 5; i++) {
    my_robot.move_forward(side_length);
    my_robot.stop_moving();
    my_robot.turn(1.2566, 1); // 2pi / 5
    my_robot.stop_moving();
    float x = my_robot.get_x_position();
    float y = my_robot.get_y_position();
    std::string coordinate =
        "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
    coordinates_map[i + 1] = coordinate;
  }

  std::cout << std::endl << std::endl << "The coordinates recorded (values) and -> their keys: " << std::endl;

  //        available in C++17: structured bindings
  //   for (const auto &[key, value] : coordinates_map) {
  //     std::cout << value << " -> " << key << std::endl;
  //   }

  for (const auto &pair : coordinates_map) {
    std::cout << pair.second << " -> " << pair.first << std::endl;
  }

  return 0;
}