file(GLOB_RECURSE SOURCE_LIST
    "${CMAKE_CURRENT_LIST_DIR}/*.cpp")

file(GLOB_RECURSE HEADER_LIST
    "${CMAKE_CURRENT_LIST_DIR}/include/*h")


add_executable(app ${SOURCE_LIST} ${HEADER_LIST})

target_link_libraries(app PRIVATE vubi)
