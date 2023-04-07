# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.23)

project ("KewlFLib")

include(CMakePrintHelpers) #Example usage: cmake_print_variables(SOURCE_FILES)
#cmake_print_variables(CMAKE_COMMAND)
#cmake_print_variables(CMAKE_CURRENT_SOURCE_DIR)

# Include sub-projects.
add_subdirectory ("3rdParty")
add_subdirectory ("KewlF")
add_subdirectory ("KewlFApp")
