cmake_minimum_required    (VERSION 3.0.0)
project                   (testcase_mpmc_basic VERSION 0.1.0 LANGUAGES CXX)

add_executable            (testcase_mpmc_basic basic.cpp)
target_link_libraries     (testcase_mpmc_basic PRIVATE 
                           lib_atomic_mpmc
                           lib_atomic_structure_details 
                           lib_atomic_allocator)

target_include_directories(testcase_mpmc_basic PRIVATE ${CMAKE_SOURCE_DIR}/include)
set_target_properties     (testcase_mpmc_basic PROPERTIES LINKER_LANGUAGE CXX)

if(UNIX AND NOT APPLE)
    target_link_libraries(testcase_mpmc_basic PRIVATE pthread)
endif()