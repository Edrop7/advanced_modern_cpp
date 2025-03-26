#include "../include/robot_manager.h"
#include <ros/ros.h>

int main(int argc, char **argv) {
  ros::init(argc, argv, "robot_manager");
  ros::NodeHandle nh;
  RobotManager turtlebot = RobotManager(&nh, "/robot1/odom", "my_robot", "turtlebot");
  turtlebot.print_specifications();
  ros::spin();
}