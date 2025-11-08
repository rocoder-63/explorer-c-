# Project_Conquer — Task #1

This is a tiny sample C++ program for Task #1.

Files:
- `src/main.cpp` — example program that prints a greeting and echoes one optional argument.

Quick commands (from a shell):

Compile with g++:

```bash
mkdir -p build
g++ -std=c++17 -O2 -Wall src/main.cpp -o build/task1
./build/task1
# or pass an argument:
./build/task1 hello
```

Or build with CMake:

```bash
mkdir -p build && cd build
cmake ..
cmake --build .
./task1
```

In VS Code: open the repo root containing `Project_Conquer/Task1`, then use the Build Task (Ctrl+Shift+B) to build, and the Run configuration to run/debug.
