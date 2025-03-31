cmake_minimum_required(VERSION 3.20)

project(
  Sandbox
  VERSION 0.0.1
  LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
# add_compile_options("-fmacro-prefix-map=${CMAKE_CURRENT_SOURCE_DIR}/=")


add_executable(Sandbox
  Source/Sandbox.cxx
)

target_include_directories(Sandbox
  PUBLIC
    Include/
)

target_link_libraries(Sandbox Magma)
