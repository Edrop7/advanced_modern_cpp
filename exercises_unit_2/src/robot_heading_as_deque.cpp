#include "robot_commander/robot_commander.h"
#include <deque>
#include <iostream>
#include <ros/ros.h>

int main(int argc, char **argv) {

  ros::init(argc, argv, "heading_vector");

  RobotCommander my_robot;

  my_robot.move_in_circles();

  int values_to_capture;
  std::cout << "how many values should be captured: ";
  std::cin >> values_to_capture;

  std::deque<float> headings;
  float captured_heading;

  for (int i = 0; i < values_to_capture; i++) {
    captured_heading = my_robot.get_heading();
    headings.push_front(captured_heading);
    std::cout << "Collecting heading value: " << captured_heading << std::endl;
    ros::Duration(1.0).sleep();
  }

  std::cout << std::endl << "Displaying saved Data:" << std::endl;
  for (int i = 0; i < values_to_capture; i++) {
    std::cout << "Heading value " << i << ": " << headings.at(i) << std::endl;
  }

  my_robot.stop_moving();

  return 0;
}