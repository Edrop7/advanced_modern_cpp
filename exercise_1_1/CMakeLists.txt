cmake_minimum_required(VERSION 3.0.2)
project(exercise_1_1)


find_package(catkin REQUIRED COMPONENTS
  nav_msgs
  roscpp
  rospy
)

catkin_package()

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

#executable named velocity_listener, linked to main and source cpp
add_executable(velocity_listener src/main.cpp src/exercise_1_1.cpp)

add_dependencies(velocity_listener nav_msgs_generate_messages_cpp)
 target_link_libraries(velocity_listener
   ${catkin_LIBRARIES}
)