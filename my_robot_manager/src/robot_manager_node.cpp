#include "../include/robot_manager.h"

int main(int argc, char **argv) {
  ros::init(argc, argv, "robot_manager");
  RobotManager turtlebot;
  turtlebot.robot_name = "my_robot";
  turtlebot.robot_model = "TurtleBot3";
  turtlebot.print_specifications();
}