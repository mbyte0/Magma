cmake_minimum_required(VERSION 3.20)

set(MAGMA_VERSION_MAJOR    0    )
set(MAGMA_VERSION_MINOR    0    )
set(MAGMA_VERSION_PATCH    0    )

set(MAGMA_VERSION_STRING "${MAGMA_VERSION_MAJOR}.${MAGMA_VERSION_MINOR}.${MAGMA_VERSION_PATCH}")

project(
  Magma
  VERSION ${MAGMA_VERSION_STRING}
  LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
# add_compile_options("-fmacro-prefix-map=${CMAKE_CURRENT_SOURCE_DIR}/=")

string(TOLOWER "${CMAKE_BUILD_TYPE}"  MAGMA_BUILD_TYPE_LOWERCASE)

set(MAGMA_BUILD_DIR ${CMAKE_SOURCE_DIR}/bin/${MAGMA_BUILD_TYPE_LOWERCASE})

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${MAGMA_BUILD_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${MAGMA_BUILD_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${MAGMA_BUILD_DIR})
# NOTE: binary dir is in build/debug/ or build/release/

message("Building Magma ${MAGMA_VERSION_STRING} (${CMAKE_BUILD_TYPE}) to ${MAGMA_BUILD_DIR}")

add_library(Magma SHARED
  Source/Core/Version.cxx
  Source/Core/Initialize.cxx
  Source/Core/Shutdown.cxx
  Source/Debug/Logger.cxx
)

target_include_directories(Magma
  PUBLIC
    Include/
)

string(TOUPPER "${CMAKE_BUILD_TYPE}"  MAGMA_BUILD_TYPE_UPPERCASE)
string(TOUPPER "${CMAKE_SYSTEM_NAME}" MAGMA_PLATFORM_UPPERCASE  )

target_compile_definitions(Magma
  PUBLIC
    "MAGMA_BUILD_TYPE_${MAGMA_BUILD_TYPE_UPPERCASE}=1"
    "MAGMA_PLATFORM_${MAGMA_PLATFORM_UPPERCASE}=1"
    "MAGMA_VERSION_MAJOR=${MAGMA_VERSION_MAJOR}"
    "MAGMA_VERSION_MINOR=${MAGMA_VERSION_MINOR}"
    "MAGMA_VERSION_PATCH=${MAGMA_VERSION_PATCH}"
    "MAGMA_VERSION_STRING=\"${MAGMA_VERSION_STRING}\""
  PRIVATE
    "MAGMA_BUILD=1"
)

if("${MAGMA_BUILD_TYPE_UPPERCASE}" STREQUAL "DEBUG")
  target_compile_definitions(Magma
    PUBLIC
      "SPDLOG_ACTIVE_LEVEL=SPDLOG_LEVEL_TRACE"
  )
endif()

# set(CMAKE_POSITION_INDEPENDENT_CODE ON )
set(BUILD_SHARED_LIBS OFF)

set(FMT_INSTALL OFF)
add_subdirectory(Dependencies/fmt)
target_link_libraries(Magma fmt::fmt)

add_subdirectory(Dependencies/glm)
target_link_libraries(Magma glm::glm)

set(SPDLOG_FMT_EXTERNAL ON)
add_subdirectory(Dependencies/spdlog)
target_link_libraries(Magma spdlog::spdlog)

# add_subdirectory(Forge)
add_subdirectory(Sandbox)
