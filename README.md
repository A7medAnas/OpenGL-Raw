# OpenGL Raw Engine

A clean, encapsulated, and foundational 3D graphics rendering project built from scratch using Modern C++ and OpenGL. This project moves away from raw boilerplate OpenGL calls by utilizing an Object-Oriented architecture, making the rendering loop and state machine much easier to manage.

## 🚀 Features
* **Modern C++ Architecture:** Encapsulated OpenGL core profile objects (`Shader`, `VAO`, `VBO`, `EBO`, `Window`).
* **Fast Build System:** Configured with `CMake` and optimized for the `Ninja` build system.
* **Texture Loading:** Integrated `stb_image` as a single-header library for seamless texture processing.
* **Window Management & Input:** Handled via `GLFW`.
* **OpenGL Function Pointers:** Handled via `GLAD`.

## 📂 Project Structure
* `assets/` - Contains shaders (`.vert`, `.frag`) and textures.
* `include/` - Contains header files (`.h`) for all abstracted OpenGL classes and libraries.
* `src/` - Contains source files (`.cpp`), including the main render loop and single-header implementations.

## 🛠️ Dependencies
To build and run this project, ensure you have the following installed on your system (Linux/Fedora):
* `CMake` (v3.10 or higher)
* `Ninja` (Build system)
* `GCC` or `Clang` compiler (C++17 support required)
* `GLFW` and `OpenGL` libraries

## ⚙️ How to Build and Run
Clone the repository and run the following commands in the root directory:

```bash
# 1. Create a build directory and navigate into it
mkdir build && cd build

# 2. Generate the build files using CMake and Ninja
cmake .. -G Ninja

# 3. Compile the project
ninja

# 4. Run the executable
./myWindow