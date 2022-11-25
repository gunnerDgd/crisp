cmake_minimum_required(VERSION 3.12)
project(crisp.examples.list
        VERSION 0.1.0
        LANGUAGES C)

add_executable(examples.list.list         list.c)
add_executable(examples.list.dynamic_list dynamic_list.c)

target_link_libraries(examples.list.list PUBLIC
                      crisp.list.lib
                      endpoint.list.lib)

target_link_libraries(examples.list.dynamic_list PUBLIC
                      crisp.base.lib
                      crisp.list.lib
                      endpoint.allocator.lib
                      endpoint.list.lib)

if(FEATURE_CRISP_TURBO)
        
endif()