set(LIBRARY_NAME "vubi")

# list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

# file(GLOB_RECURSE SOURCE_LIST
# "${CMAKE_CURRENT_LIST_DIR}/*.cpp")

set(SOURCE_LIST
    window.cpp
    application.cpp
    sdl_utilities.cpp
    )

file(GLOB_RECURSE HEADER_LIST
    "${PROJECT_SOURCE_DIR}/include/*h")

add_library(${LIBRARY_NAME} ${SOURCE_LIST} ${HEADER_LIST})

include(FetchContent)

FetchContent_Declare(
    GLM
    GIT_REPOSITORY "https://github.com/g-truc/glm"
    GIT_TAG "cc98465e3508535ba8c7f6208df934c156a018dc"
    )

FetchContent_Declare(
    vulkanhpp
    GIT_REPOSITORY "https://github.com/KhronosGroup/Vulkan-Headers"
    )



FetchContent_MakeAvailable(GLM)
FetchContent_MakeAvailable(vulkanhpp)

find_package(PkgConfig REQUIRED)
pkg_search_module(SDL2 REQUIRED sdl2)
pkg_search_module(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)

if ( NOT vulkanhpp_POPULATED )
    message ( STATUS "Fetching vulkanhpp" )
endif ()

if ( vulkanhpp_POPULATED )
    message ( STATUS "FOUND vulkanhpp" )
endif ()


if (PkgConfig_FOUND)
    message(STATUS "FOUND PkgConfig!")
else()
    message(FATAL_ERROR "FAILED TO GET PkgConfig!")
endif()

if(SDL2_FOUND)
    message(STATUS "FOUND SDL2!")
    message(STATUS "${SDL2_INCLUDE_DIRS}")
else()
    message(STATUS "COULDN'T find SDL2")
endif()

if(SDL2IMAGE_FOUND)
    message(STATUS "FOUND SDL2IMAGE!")
    message(STATUS "${SDL2IMAGE_INCLUDE_DIRS}")
else()
    message(STATUS "COULDN'T find SDL2")
endif()


target_include_directories(${LIBRARY_NAME} PRIVATE SDL2_INCLUDE_DIRS SDL2IMAGE_INCLUDE_DIRS PUBLIC ../include)

target_link_libraries(${LIBRARY_NAME} ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES} glm Vulkan::Headers)

# All users of this library will need at least C++11
target_compile_features(${LIBRARY_NAME} PUBLIC cxx_std_20)

# IDEs should put the headers in a nice place
source_group(
    TREE "${PROJECT_SOURCE_DIR}/include"
    PREFIX "Header Files"
    FILES ${HEADER_LIST})
