add_executable            (testcase_spsc_basic basic.c)
target_link_libraries     (testcase_spsc_basic PRIVATE 
                           lib_atomic_spsc 
                           lib_atomic_structure_details 
                           lib_atomic_allocator)
target_include_directories(testcase_spsc_basic PRIVATE ${CMAKE_SOURCE_DIR}/include)