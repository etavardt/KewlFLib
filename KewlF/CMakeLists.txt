# CMakeList.txt : CMake project for KewlF, include source and define
# project specific logic here.
#

include_directories(
    src/
#    ${libbacktrace_SOURCE_DIR}/src/
#    ${libbacktrace_BINARY_DIR}/gen
)

# Add source to this project's executable.
file(GLOB SOURCE_FILES LIST_DIRECTORIES false
    src/*.cpp
)
add_library (KewlF STATIC ${SOURCE_FILES})
#target_link_libraries(KewlF ${libbacktrace_BINARY_DIR}/libbacktrace.a)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET KewlF PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
install(TARGETS KewlF FILE_SET HEADERS)