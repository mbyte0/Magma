# Magma
Magma is a 2D/3D game engine for Linux/Windows written in C++ that uses Vulkan for rendering, but it can also be used to create applications.  

## Table of contents

- [Getting started](#getting-started)
- [Libraries used in Magma](#libraries-used-in-magma)

## Getting started
<!-- Magma uses CMake, clang and the ninja build system, so install those.  -->
To build magma install: cmake, clang, ninja and the Vulkan SDK

### Build for Debug
To build the debug binaries run:
``` bash
cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_EXPORT_COMPILE_COMMANDS=1 -G Ninja .
ninja
```
### Build for Release
To build the release binaries run:
``` bash
cmake -DCMAKE_BUILD_TYPE=Release -G Ninja .
ninja
```

## Libraries used in Magma

- [{fmt}](https://github.com/fmtlib/fmt "{fmt}'s GitHub repo")
- [glm](https://github.com/g-truc/glm "glm's GitHub repo")
