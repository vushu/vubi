include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        e2239ee6043f73722e7aa812a459f54a28552929
    )

set(TEST_NAME "libvubi_test")


# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


add_executable(${TEST_NAME}
window_test.cpp
sdl_utilities_test.cpp
#opengl_window_test.cpp
#opengl_shader_test.cpp
)

# I'm using C++17 in the test
target_compile_features(${TEST_NAME} PRIVATE cxx_std_17)

target_link_libraries(${TEST_NAME} PRIVATE vubi gtest_main)

#DART for vscode
include(Dart)
include(GoogleTest)

gtest_discover_tests(${TEST_NAME})


