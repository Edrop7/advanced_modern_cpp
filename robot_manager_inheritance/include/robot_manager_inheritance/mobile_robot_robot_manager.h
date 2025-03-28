#pragma once
#include "nav_msgs/Odometry.h"
#include "robot_manager_inheritance/base_robot_manager.h"
#include <ros/ros.h>

class MobileRobotRobotManager : public RobotManagerBase {

public:
  MobileRobotRobotManager(ros::NodeHandle *node_handle);

};