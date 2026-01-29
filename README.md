# Hello World Repo

- A simple repo that defines a "Hello World" library
- This repo has the required structure (CMakeLists.txt files, etc) to be compatible w/ our uniform development environment
- Refer to the `software-repeat-hello-world` repository for an example of a project that has a dependency on another micromouse software library/project

## Creating Your Own Software Repository

- When creating your own software repo, for the most part you can just copy this repo
- Refer to each file for details on what to change:
- `software-hello-world/`
  - Top level project directory- rename it to whatever you need (`software-your-repo-name`)
  - `main.c`
    - Just a file for testing code on hardware- customize as needed
  - `CMakeLists.txt`
    - Top level CMakeLists.txt file (for this software repo)
  - `platforms.cmake`
    - Indicates what build targets are applicable for this project- you can turn on/off build targets
  - `hello-world/`
    - A library in your software repo
    - You can define as many libraries as you want, but they each need a CMakeLists.txt file and `tests/` folder
    - `print_hello_world.c` & `print_hello_world.h`
      - You can define whatever implementation/interface files you want
    - `CMakeLists.txt`
      - Library level CMakeLists.txt file
    - `tests/`
      - Test directory for your libraries
      - All .cpp CppUTest files for your libraries are defined here
      - `CMakeLists.txt`
        - Test level CMakeLists.txt file
      - `test_print_hello_world.cpp`
        - CppUTest file for your library
