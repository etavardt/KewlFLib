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
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(KewlF PUBLIC KEWLF_DEBUG)
endif()

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET KewlF PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
install(TARGETS KewlF FILE_SET HEADERS)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/src/
     DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/include/KewlF
     FILES_MATCHING PATTERN src/*.hpp
)

#add_custom_command(
#    TARGET KewlF POST_BUILD
#    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/src/*.h* ${CMAKE_SOURCE_DIR}/include/KewlF
#    COMMENT "Copying recources" VERBATIM
#)
#INSTALL (
#    DIRECTORY ${CMAKE_SOURCE_DIR}/src/
#    DESTINATION ${CMAKE_SOURCE_DIR}/include/KewlF
#    FILES_MATCHING PATTERN "*.h*"
#)