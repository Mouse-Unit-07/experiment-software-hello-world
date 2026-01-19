# Hello World Repo

- A simple repo that defines an interface with a single function that prints "Hello World\r\n"
- It's an example of a source code repo with the required structure (CMakeLists.txt files, etc) for compatibility w/ our uniform development environment
- Refer to the `software-repeat-hello-world` repository for an example of a project that has a dependency on another micromouse software library/project

## Creating Your Own Software Repository

- Below are all the changes you need to make to create your own software repository:
  - `software-hello-world/`
    - Top level project directory
    - Must be renamed for your software (`software-whatever-you-want`)
      - GitHub doesn't support nesting/grouping repositories, so the `software-` prefix helps see that the repo is a software repo
  - `software-hello-world/main.c`
    - Just a file for if you need to flash some test code to the MCU
    - Customize as needed
  - `software-hello-world/CMakeLists.txt`
    - Top level CMakeLists.txt file
    - `hello_world_lib` must be renamed for your software unit's library (`whatever_you_want_lib`)
    - All of your interface subdirectories must be made explicit with `target_include_directories()`
    - Establish links to other micromouse software on GitHub in this file
  - `software-hello-world/hello-world/`
    - An interface in your software project
    - You can define as many interfaces as you want, but they each need their own CMakeLists.txt file and `tests/` folder
  - `software-hello-world/hello-world/print_hello_world.c & .h`
    - You can define whatever interface files you want
  - `software-hello-world/hello-world/CMakeLists.txt`
    - Interface level CMakeLists.txt file
    - All .c source files defined in the interface must be explicitly included with `target_sources()`
    - `hello_world_lib` again must be renamed for your software project's library
  - `software-hello-world/hello-world/tests/`
    - Test directory for the hello_world interface
    - All .cpp CppUTest files for your interface are defined here
  - `software-hello-world/hello-world/CMakeLists.txt`
    - Test level CMakeLists.txt file
    - All "test source files" (.cpp CppUTest files and their associated .c source files being tested) must be listed out as a part of the `LOCAL_TEST_SOURCES` variable
    - `test_hello_world` must be renamed according to what interface this is a test unit for (`test_whatever_interface`)
  - `software-hello-world/hello-world/test_print_hello_world.cpp`
    - CppUTest file for your interface
