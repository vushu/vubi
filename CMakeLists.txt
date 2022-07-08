cmake_minimum_required(VERSION 3.11...3.23)
project(vubi_project)
set(CMAKE_CXX_STANDARD 20)
enable_testing()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(src)
add_subdirectory(app)
add_subdirectory(tests)
