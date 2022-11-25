cmake_minimum_required(VERSION 3.12)
project(crisp.examples.pf.list
        VERSION 0.1.0
        LANGUAGES CXX)

add_executable       (examples.pf.list 
                      pf_list.h
                      pf_stl_list.h
                      pf_turbo.h
                      pf_list.cpp
                      pf_stl_list.cpp
                      pf_turbo.cpp
                      main.cpp)

target_link_libraries(examples.pf.list PUBLIC
                      crisp.base.lib
                      crisp.list.lib
                      crisp.turbo.lib
                      endpoint.list.lib
                      endpoint.allocator.lib
                      endpoint.turbo.lib
                      crisp.arch.x86_64.msvc
                      )