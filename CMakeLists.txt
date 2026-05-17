#--------------------------------- FILE INFO ----------------------------------#
# Filename           : CMakeLists.txt                                          #
#                                                                              #
# Top level CMakeLists.txt file (for this software repo)                       #
#                                                                              #
#------------------------------------------------------------------------------#
cmake_minimum_required(VERSION 4.0.2)
project(hello_world_project LANGUAGES C) # <== Name your software project

include(FetchContent)

# \/=== Add dependencies to other GitHub repos
# Example dependency on Hello World project (check out Repeat Hello World project):
#FetchContent_Declare(
#    print_hello_world
#    GIT_REPOSITORY git@github.com:Mouse-Unit-07/experiment-software-hello-world.git
#    GIT_TAG main
#)
# FetchContent_MakeAvailable(print_hello_world)

# \/=== Add all library directories (each w/ a CMakeLists.txt)
add_subdirectory(hello_world)

# \/=== Add all test directories
if(TARGET_WINDOWS AND SUPPORTS_WINDOWS)
    if(ENABLE_HELLO_WORLD_TESTS)
        add_subdirectory(hello_world/tests)
    endif()
endif()

# \/=== Create an aggregate interface library if your project has multiple libraries 
add_library(hello_world_aggregate_lib INTERFACE)

# \/=== Link to all libraries defined by your software project
target_link_libraries(hello_world_aggregate_lib INTERFACE
    hello_world_lib
)
