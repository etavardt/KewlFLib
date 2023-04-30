# CMakeList.txt : CMake project for KewlF, include source and define
# project specific logic here.
#

FetchContent_MakeAvailable(glfw)
cmake_print_variables(glfw_SOURCE_DIR)

include_directories(
    src/
    ../3rdParty/include/
    #../3rdParty/glfw/include/
    ${glfw_SOURCE_DIR}/include/
    ../3rdParty/glad/src/
    ../3rdParty/glad/include/
    ../3rdParty/imgui/
)

# Add source to this project's executable.
file(GLOB_RECURSE SOURCE_FILES LIST_DIRECTORIES false
    src/*.cpp
)

cmake_print_variables(SOURCE_FILES)

add_library (KewlF STATIC ${SOURCE_FILES})

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(KewlF PUBLIC KEWLF_DEBUG)
endif()

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET KewlF PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/src/
     DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/include/
     FILES_MATCHING PATTERN *.hpp
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
#install(TARGETS KewlF
#        FILE_SET
#        HEADERS
#)
#install(DIRECTORY "${CMAKE_SOURCE_DIR}/" # source directory
#        DESTINATION "include" # target directory
#        FILES_MATCHING # install only matched files
#        PATTERN "*.h" # select header files
#)
