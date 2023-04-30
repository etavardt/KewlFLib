# CMakeList.txt : CMake project for 3rdParty projects
# project specific logic here.
#

# Include sub-projects.
#add_subdirectory ("glfw3")

#include(FetchContent)
include(FetchContent)

#find_package(backtrace REQUIRED)
#find_package(glfw REQUIRED)

#FetchContent_Declare(
#    libbacktrace
#    GIT_REPOSITORY https://github.com/etavardt/libbacktrace.git
#    #GIT_TAG        ???
#)

## Check if population has already been performed
#FetchContent_GetProperties(libbacktrace)
#string(TOLOWER "libbacktrace" lcName)
#if(NOT ${lcName}_POPULATED)
#  # Fetch the content using previously declared details
#  FetchContent_Populate(libbacktrace)

#  # Set custom variables, policies, etc.
#  # ...

#  # Bring the populated content into the build
#  add_subdirectory(${${lcName}_SOURCE_DIR} ${${lcName}_BINARY_DIR})
#endif()

FetchContent_Declare(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    #GIT_TAG 3.3.8
)
FetchContent_GetProperties(glfw)
if(NOT glfw_POPULATED)
    FetchContent_Populate(glfw)

    set(GLFW_BUILD_EXAMPLES OFF CACHE INTERNAL "Build the GLFW example programs")
    set(GLFW_BUILD_TESTS OFF CACHE INTERNAL "Build the GLFW test programs")
    set(GLFW_BUILD_DOCS OFF CACHE INTERNAL "Build the GLFW documentation")
    set(GLFW_INSTALL OFF CACHE INTERNAL "Generate installation target")

    add_subdirectory(${glfw_SOURCE_DIR} ${glfw_BINARY_DIR})
endif()

cmake_print_variables(glfw_SOURCE_DIR)
cmake_print_variables(glfw_BINARY_DIR)
cmake_print_variables(glfw_INCLUDE_DIR)

#FetchContent_Declare(
#    glew
#    GIT_REPOSITORY https://github.com/nigels-com/glew.git
#)

#FetchContent_Declare(
#    glm
#    GIT_REPOSITORY https://github.com/g-truc/glm.git
#)
