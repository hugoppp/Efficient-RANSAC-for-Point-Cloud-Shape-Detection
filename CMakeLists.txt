# Taken from https://github.com/ihmcrobotics/ihmc-open-robotics-software/blob/5f5345ea78f681c1ca815bb1539041b5d0ab54d0/ihmc-sensor-processing/csrc/ransac_schnabel/CMakeLists.txt
cmake_minimum_required(VERSION 2.8)
project(pc_ransac)

set(CMAKE_CXX_FLAGS "-fpermissive")

include_directories(SYSTEM ./)
include_directories(SYSTEM ./MiscLib/)
FILE(GLOB SRC "./*.cpp")
FILE(GLOB MISC_SRC "./MiscLib/*.cpp")

add_compile_options(-w)

add_library(libransac STATIC  ${SRC} ${MISC_SRC})
