# CMakeList.txt : CMake project for 3rdParty projects
# project specific logic here.
#

# Include sub-projects.

include(FetchContent)

# GLFW
FetchContent_Declare(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    #GIT_TAG 3.3.8
)
FetchContent_GetProperties(glfw)
if(NOT glfw_POPULATED)
    FetchContent_Populate(glfw)

    add_subdirectory(${glfw_SOURCE_DIR} ${glfw_BINARY_DIR})
endif()

cmake_print_variables(glfw_SOURCE_DIR)
cmake_print_variables(glfw_BINARY_DIR)

# IMGUI
FetchContent_Declare(
    imgui
    GIT_REPOSITORY https://github.com/ocornut/imgui.git
    GIT_TAG        origin/docking
    #URL https://github.com/ocornut/imgui/archive/refs/heads/docking.zip
)
FetchContent_GetProperties(imgui)
if(NOT imgui_POPULATED)
    FetchContent_Populate(imgui)

    #add_subdirectory(${imgui_SOURCE_DIR} ${imgui_BINARY_DIR})
endif()

cmake_print_variables(imgui_SOURCE_DIR)
cmake_print_variables(imgui_BINARY_DIR)
