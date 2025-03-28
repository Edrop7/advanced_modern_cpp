#pragma once
#include <ros/ros.h>
#include <std_srvs/SetBool.h>

class RobotManagerBase {

public:
  RobotManagerBase(){};
  RobotManagerBase(ros::NodeHandle *node_handle);

protected:
  ros::NodeHandle *nh;
  void init_config_output_srv();
  bool output_enabled = false;
  virtual void displayRobotDetails();
  std::string robot_name = "Waste Allocation Load Lifter Earth-Class";
  std::string robot_location = "Emeryville, California";

private:
  ros::ServiceServer config_output_srv;
  bool ConfigOutputCallback(std_srvs::SetBoolRequest &req,
                            std_srvs::SetBoolResponse &response);
};