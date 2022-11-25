cmake_minimum_required(VERSION 3.12)
project(crisp.examples.list
        VERSION 0.1.0
        LANGUAGES C)

add_executable(examples.list.list list.c)
add_executable(examples.list.dynamic_list dynamic_list.c)

target_link_libraries(examples.list.list PUBLIC
                      list.list
                      endpoint.list.list)

target_link_libraries(examples.list.dynamic_list PUBLIC
                      base.allocator.stdlib
                      endpoint.allocator.standard_library
                      list.list
                      list.dynamic_list
                      endpoint.list.list)