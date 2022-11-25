cmake_minimum_required(VERSION 3.12)
project(crisp.examples.pf.list
        VERSION 0.1.0
        LANGUAGES CXX)

add_executable       (examples.pf.list 
                      pf_list.h
                      pf_stl_list.h
                      pf_list.cpp
                      pf_stl_list.cpp
                      main.cpp)
target_link_libraries(examples.pf.list PUBLIC
                      base.allocator.stdlib
                      endpoint.allocator.standard_library
                      list.list
                      list.dynamic_list
                      endpoint.list.list)