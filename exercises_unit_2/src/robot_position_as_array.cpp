#include "robot_commander/robot_commander.h"
#include <iostream>
#include <ros/ros.h>

int main(int argc, char **argv) {

  ros::init(argc, argv, "position_array");

  RobotCommander my_robot;

  float robot_coordinates[3];

  robot_coordinates[0] = my_robot.get_x_position();
  robot_coordinates[1] = my_robot.get_y_position();
  robot_coordinates[2] = my_robot.get_z_position();

  std::cout << "X position is: " << robot_coordinates[1]
            << ", Y position is: " << robot_coordinates[2]
            << ", Z position is: " << robot_coordinates[3] 
            << std::endl;
}