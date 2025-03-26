#include <ros/ros.h>
#include <string>
#include "../include/robot_manager.h"

void RobotManager::print_specifications() {
  ROS_INFO("Robot Name: %s", robot_name.c_str());
  ROS_INFO("Robot Model: %s", robot_model.c_str());
  ROS_INFO("Battery Capacity kwh: %.2f", battery_capacity_kwh);
  ROS_INFO("Total Operation Hours: %d", total_operation_hours);
}
