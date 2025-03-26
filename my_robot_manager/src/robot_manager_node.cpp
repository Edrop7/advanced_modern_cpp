#include "../include/robot_manager.h"
#include <iostream>
#include <ros/ros.h>

int main(int argc, char **argv) {
  std::cout << std::endl << std::endl;

  ros::init(argc, argv, "robot_manager");
  ros::NodeHandle nh;

  RobotManager turtlebot =
      RobotManager(&nh, "/robot1/odom", "my_robot", "turtlebot");
  turtlebot.print_specifications();

  std::cout << std::endl << std::endl;

//   RobotManager turtlebot2 =
//       RobotManager(&nh, "/robot2/odom", "my_second_robot", "turtlebot");
//   turtlebot2.print_specifications();

//   std::cout << std::endl << std::endl;

  ros::spin();
}