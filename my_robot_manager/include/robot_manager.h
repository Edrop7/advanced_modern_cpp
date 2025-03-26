#pragma once
#include <ros/ros.h>

class RobotManager {
public:
  std::string robot_name;
  std::string robot_model;
  float battery_capacity_kwh = 2;
  int total_operation_hours = 100;

  void print_specifications();
};