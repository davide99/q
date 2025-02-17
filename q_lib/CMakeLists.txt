###############################################################################
#  Copyright (c) 2016-2023 Joel de Guzman. All rights reserved.
#
#  Distributed under the MIT License (https://opensource.org/licenses/MIT)
###############################################################################
cmake_minimum_required(VERSION 3.5.1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(libq)
set(q_root ${CMAKE_CURRENT_SOURCE_DIR})

###############################################################################
# Get rid of these warnings
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang"
      OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}-Wno-missing-braces]")
endif()

###############################################################################
# Sources

set(Q_HEADERS
   ${CMAKE_CURRENT_SOURCE_DIR}/include/fx/allpass.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/include/fx/biquad.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/include/fx/delay.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/include/fx/dynamic.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/include/fx/envelope.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/include/fx/feature_detection.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/include/fx/lowpass.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/include/fx/median.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/include/fx/moving_average.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/include/fx/moving_maximum.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/include/fx/special.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/include/fx/waveshaper.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/include/pitch/period_detector.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/include/pitch/pitch_detector.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/include/support/value.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/include/support/audio_stream.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/include/support/base.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/include/support/decibel.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/include/support/frequency.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/include/support/literals.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/include/support/midi.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/include/support/notes.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/include/support/phase.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/include/utility/antialiasing.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/include/utility/bitset.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/include/utility/bitstream_acf.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/include/utility/fractional_ring_buffer.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/include/utility/interpolation.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/include/utility/ring_buffer.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/include/utility/zero_crossing.hpp
)

file(GLOB_RECURSE Q_HEADERS include/*.hpp)

source_group("Header Files\\q"
   FILES
   ${Q_HEADERS}
)

###############################################################################
# Library

add_library(libq INTERFACE)

target_include_directories(libq INTERFACE include/)


