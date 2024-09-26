cmake_minimum_required(VERSION 3.10)
project(DKit VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

cmake_policy(SET CMP0072 NEW)

find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)
find_package(Vulkan REQUIRED)

file(GLOB_RECURSE SOURCES "src/**/*.cpp")
file(GLOB_RECURSE HEADER_DIRS LIST_DIRECTORIES true "src/**/*.h")

set(MAIN_SOURCE "src/Main.cpp")

list(APPEND SOURCES ${MAIN_SOURCE})

foreach(header_dir ${HEADER_DIRS})
    get_filename_component(header_path ${header_dir} DIRECTORY)
    include_directories(${header_path})
endforeach()

include_directories(${GLEW_INCLUDE_DIRS})
include_directories(${OPENGL_INCLUDE_DIR})
include_directories(${GLFW_INCLUDE_DIRS})
include_directories(${VULKAN_INCLUDE_DIRS})
include_directories("include/CrossPlatform") 

add_executable(DKit ${SOURCES})

target_link_libraries(DKit ${GLEW_LIBRARIES} ${OPENGL_LIBRARIES} glfw ${Vulkan_LIBRARIES})


