add_executable            (testcase_details_cqueue_basic circular_queue/basic.c)
target_link_libraries     (testcase_details_cqueue_basic lib_atomic_structure_details)
target_include_directories(testcase_details_cqueue_basic PRIVATE ${CMAKE_SOURCE_DIR}/include)