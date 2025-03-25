cmake_minimum_required(VERSION 3.0.2)
project(exercises_unit_2)

find_package(catkin REQUIRED COMPONENTS
  robot_commander
  roscpp
)
catkin_package()

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(robot_position_as_array src/robot_position_as_array.cpp)
target_link_libraries(robot_position_as_array ${catkin_LIBRARIES})