add_executable            (testcase_stack_basic basic.c)
target_link_libraries     (testcase_stack_basic PRIVATE 
                           lib_atomic_stack
                           lib_atomic_allocator)
target_include_directories(testcase_stack_basic PRIVATE ${CMAKE_SOURCE_DIR}/include)