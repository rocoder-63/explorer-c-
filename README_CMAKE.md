# Project Build Setup

This project uses CMake for building. Follow the steps below to set up and build.

## Prerequisites

You need to install:
- **CMake** (3.10+): https://cmake.org/download/
- **Ninja** (build tool): https://github.com/ninja-build/ninja/releases or `choco install ninja` (Windows)
- **C++ Compiler** (g++): Already available from MSYS64 (C:/msys64/ucrt64/bin/g++.exe)

Or, if you prefer to use **Make** instead of Ninja, install **Make** or use the **MinGW** toolchain.

## Building with CMake in VS Code

### Option 1: Use VS Code Tasks (Recommended)

1. Open VS Code in the workspace root.
2. Press `Ctrl+Shift+B` to run the default build task (**CMake: Build**).
   - This assumes CMake is already configured.
   - If configuration is needed, run **CMake: Configure** first.

### Option 2: Run from Terminal

```powershell
# Navigate to Task1 directory
cd Task1

# Configure (generates build files)
cmake -B build -S . -G "Ninja"

# Build
cmake --build build

# Run the executable
.\build\task1.exe
```

Or, if using Make instead of Ninja:
```powershell
cmake -B build -S . -G "Unix Makefiles"
cmake --build build
.\build\task1.exe
```

## Available VS Code Tasks

- **CMake: Configure** – Generate build files in `Task1/build/`
- **CMake: Build** – Compile the project (default task, Ctrl+Shift+B)
- **CMake: Configure & Build** – Configure and build in one step
- **CMake: Run task1** – Execute the compiled `task1.exe`
- **C/C++: g++.exe build active file** – Direct g++ compilation (legacy)

## Output

The compiled executable will be placed in:
```
Task1/build/task1.exe
```

## Troubleshooting

- **CMake not found**: Install CMake from https://cmake.org/download/ and add it to PATH.
- **Ninja not found**: Install Ninja or replace `-G "Ninja"` with `-G "Unix Makefiles"` (if make is installed).
- **Build fails**: Ensure the C++ compiler is in PATH. For MSYS64, add `C:/msys64/ucrt64/bin` to your PATH.
