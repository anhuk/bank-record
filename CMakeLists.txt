cmake_minimum_required(VERSION 3.18.0)
project(bank-record VERSION 0.0.1)
set(CMAKE_CXX_STANDARD 20)

file(GLOB SOURCES ./src/*.cpp)
add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME}
  PRIVATE include)
