#pragma once
#include <ros/ros.h>
#include "nav_msgs/Odometry.h"

class RobotManager {
private:
  std::string robot_name;
  std::string robot_model;
  const float battery_capacity_kwh = 2;
  const int total_operation_hours = 100;
  std::string odom_topic;
  ros::Subscriber odom_subscriber;

public:
  static int robot_count;

  RobotManager(ros::NodeHandle *nh, std::string topic, std::string name,
               std::string model);
  void print_specifications();
  void odom_callback(const nav_msgs::Odometry::ConstPtr &msg);
};