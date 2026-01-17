# TODO

A simple terminal-based TODO application built with C++ to practice CMake, vcpkg, and C++ project structure.

## Prerequisites

- CMake (3.15+)
- vcpkg
- ncurses library
- C++ compiler (GCC 9+, Clang 10+, or MSVC 2019+)

## Installation

1. **Install vcpkg**
   ```bash
   git clone https://github.com/Microsoft/vcpkg.git
   cd vcpkg
   ./bootstrap-vcpkg.sh
   ```

2. **Install ncurses**
   ```bash
   ./vcpkg install ncurses
   ```

## Build & Run

```bash
mkdir build && cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE=[path-to-vcpkg]/scripts/buildsystems/vcpkg.cmake
cmake --build .
./TODO
```

## Learning Goals

- CMake build configuration
- vcpkg package management
- C++ folder structure
- Third-party library integration

## License

MIT License
