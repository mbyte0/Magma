cmake_minimum_required(VERSION 3.20)

project(
  App
  VERSION 0.1.0
  LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)

add_executable(app
  Source/App.cxx
  Source/Main.cxx
)

target_include_directories(app
  PUBLIC
    Include/
)

target_link_libraries(app lib)
