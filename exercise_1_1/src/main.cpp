#include "../include/exercise_1_1/exercise_1_1.h"
#include "nav_msgs/Odometry.h"
#include "ros/ros.h"

void odomCallback(const nav_msgs::Odometry::ConstPtr &msg) {

  float linear_x = msg->twist.twist.linear.x;
  float angular_z = msg->twist.twist.angular.z;
  ros::Duration(1).sleep();
  display_velocity(linear_x, angular_z);
}

int main(int argc, char **argv) {

  ros::init(argc, argv, "velocity_listener");

  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe("odom", 1000, odomCallback);

  ros::spin();

  return 0;
}