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
  Source/Test.cxx
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


# set(FMT_DOC                         OFF)
# set(FMT_INSTALL                     OFF)
# set(FMT_TEST                        OFF)
# set(BUILD_SHARED_LIBS               OFF)
# set(CMAKE_POSITION_INDEPENDENT_CODE ON )

# add_subdirectory(Libraries/fmt)
# target_link_libraries(Magma fmt::fmt)

# add_subdirectory(Forge)
add_subdirectory(Sandbox)

if(CMAKE_EXPORT_COMPILE_COMMANDS)
  if ("${MAGMA_BUILD_TYPE_UPPERCASE}" STREQUAL "DEBUG" AND "${MAGMA_PLATFORM_UPPERCASE}" STREQUAL "LINUX")
    add_custom_target(LinkCompileCommands ALL
      COMMAND ${CMAKE_COMMAND} -E create_symlink
      ${CMAKE_BINARY_DIR}/compile_commands.json
      ${CMAKE_SOURCE_DIR}/compile_commands.json
      COMMENT "Symlinking compile_commands.json to the project root"
    )
  elseif("${MAGMA_BUILD_TYPE_UPPERCASE}" STREQUAL "DEBUG" AND "${MAGMA_PLATFORM_UPPERCASE}" STREQUAL "WINDOWS")
    # Hardlink because symlink requires admin or developer moode on windows
    add_custom_target(LinkCompileCommands ALL
      COMMAND ${CMAKE_COMMAND} -E copy_if_different
      ${CMAKE_BINARY_DIR}/compile_commands.json
      ${CMAKE_SOURCE_DIR}/compile_commands.json
      COMMAND powershell -Command "New-Item -ItemType HardLink -Path '${CMAKE_SOURCE_DIR}/compile_commands.json' -Target '${CMAKE_BINARY_DIR}/compile_commands.json'" || exit 0
      COMMENT "Hardlinking compile_commands.json to the project root"
    )
  endif()
endif()
