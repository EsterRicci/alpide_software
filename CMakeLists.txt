# CMakeLists.txt for ALPIDE single chip analysis software
#Written by Ester Ricci, ester.ricci@unitn.it

cmake_minimum_required(VERSION 2.6 FATAL_ERROR)
project(ALPIDEsinglechipAnalysis)

list(APPEND CMAKE_PREFIX_PATH $ENV{ROOTSYS})
find_package(ROOT REQUIRED COMPONENTS RIO Net Hist Gpad)
include(${ROOT_USE_FILE})

include_directories(${CMAKE_SOURCE_DIR}/include)
file(GLOB_RECURSE sources ${CMAKE_SOURCE_DIR}/src/*cc)

add_executable(AnalysisEster AnalysisEster.cc ${sources})
add_executable(CreateMask CreateMask.cc ${sources})

target_link_libraries(AnalysisEster ${ROOT_LIBRARIES})
target_link_libraries(CreateMask ${ROOT_LIBRARIES})
