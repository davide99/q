###############################################################################
#  Copyright (c) 2016-2023 Joel de Guzman. All rights reserved.
#
#  Distributed under the MIT License (https://opensource.org/licenses/MIT)
###############################################################################
cmake_minimum_required(VERSION 3.5.1)

project(q)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(q_lib)

add_executable(pitch main.cpp)
target_include_directories(pitch PRIVATE libq)
target_link_libraries(pitch libq)