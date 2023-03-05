cmake_minimum_required(VERSION 3.24)
project(Connect4_Machine_Learning)

set(CMAKE_CXX_STANDARD 23)
add_executable(Connect4_Machine_Learning main.cpp Connect4/Connect4.cpp ML/ML.cpp ML/File_management.cpp ML/Data_analysis.cpp  ML/AI.cpp)
