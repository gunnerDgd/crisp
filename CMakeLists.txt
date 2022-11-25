cmake_minimum_required(VERSION 3.12)
project(crisp
        VERSION 0.1.0
        LANGUAGES C)

include_directories(${CMAKE_SOURCE_DIR})

add_subdirectory(base)
add_subdirectory(list)
add_subdirectory(stack)
add_subdirectory(queue)
add_subdirectory(atomic)

add_subdirectory(crisp/list)
add_subdirectory(crisp/stack)
add_subdirectory(crisp/atomic)
add_subdirectory(crisp/allocator)

add_subdirectory(examples/list)