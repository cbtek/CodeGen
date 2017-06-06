
#==============================================================================
# CMakeLists file for codegen
#==============================================================================
cmake_minimum_required(VERSION 3.0)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CURR_TARGET codegen)
project(${CURR_TARGET})
set(CURR_TARGET_SOURCES "${CURR_TARGET}_SOURCES")
set(CURR_TARGET_HEADERS "${CURR_TARGET}_HEADERS")

include_directories(inc)
include_directories(inc/code_templates)
include_directories(inc/project_templates)

include(${CMAKE_MODULE_PATH}/flags.cmake)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

#==============================================================================
# Include Source Files
#==============================================================================
file(GLOB CURR_TARGET_SOURCES "src/*.cpp" "src/project_templates/*.cpp" "src/code_templates/*.cpp")
file(GLOB CURR_TARGET_HEADERS "inc/*.h*" "inc/project_templates/*.h*" "inc/code_templates/*.h*")

#==============================================================================
# Add Executable
#==============================================================================
add_executable(${CURR_TARGET}
               ${CURR_TARGET_SOURCES}
               ${CURR_TARGET_HEADERS}
               )

#==============================================================================
# Add Dependencies
#==============================================================================
add_dependencies(${CURR_TARGET} common_utils )

#==============================================================================
# Target Link Libraries
#==============================================================================
target_link_libraries(${CURR_TARGET} common_utils )
