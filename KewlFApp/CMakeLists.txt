# CMakeList.txt : CMake project for KewlFApp, include source and define
# project specific logic here.
#

cmake_print_variables(libbacktrace_SOURCE_DIR)
include_directories(
    src/
    ../KewlF/src/
    ../3rdParty/easyloggingpp/src/
#    ${libbacktrace_SOURCE_DIR}/src/
#    ${libbacktrace_BINARY_DIR}/gen
)

# Add source to this project's executable.
file(GLOB SOURCE_FILES LIST_DIRECTORIES false
    ../3rdParty/easyloggingpp/src/*.cc
    src/*.cpp
    src/*.h
    src/*.hpp
)

# Add source to this project's executable.
add_executable (KewlFApp ${SOURCE_FILES})
target_link_libraries(KewlFApp KewlF)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET KewlFApp PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
