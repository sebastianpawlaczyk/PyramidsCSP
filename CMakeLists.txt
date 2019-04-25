cmake_minimum_required(VERSION 3.10)
project(Pyramid)

set(CMAKE_CXX_STANDARD 11)

add_executable(Pyramid main.cpp src/sdk/LifeController.cpp src/sdk/LifeController.hpp src/algorithm/PyramidAlgorithm.cpp src/algorithm/PyramidAlgorithm.hpp src/algorithm/SquareHelper.cpp src/algorithm/SquareHelper.hpp)