cmake_minimum_required(VERSION 2.8.3)
project(controls)

find_package(catkin REQUIRED COMPONENTS
  rospy
  genmsg
  std_msgs
  mec
)

catkin_python_setup()

catkin_package(
  CATKIN_DEPENDS
  rospy
)
