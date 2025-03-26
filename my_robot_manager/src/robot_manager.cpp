#include <ros/ros.h>
#include <string>
#include "../include/robot_manager.h"

int RobotManager::robot_count = 0;

RobotManager::RobotManager(ros::NodeHandle *nh, std::string topic, std::string name, std::string model) {
  odom_topic = topic;
  robot_name = name;
  robot_model = model;
  odom_subscriber = nh->subscribe(odom_topic, 1000, &RobotManager::odom_callback, this);

    robot_count++;
    ROS_INFO("Created Robot #%d", robot_count);
}

void RobotManager::odom_callback(const nav_msgs::Odometry::ConstPtr &msg) {
  ROS_INFO("%s position (x,y): %lf , %lf", robot_name.c_str(), msg->pose.pose.position.x, msg->pose.pose.position.y);
}

void RobotManager::print_specifications() {
  ROS_INFO("Robot Name: %s", robot_name.c_str());
  ROS_INFO("Robot Model: %s", robot_model.c_str());
  ROS_INFO("Battery Capacity kwh: %.2f", battery_capacity_kwh);
  ROS_INFO("Total Operation Hours: %d", total_operation_hours);
}
