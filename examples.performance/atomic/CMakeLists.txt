cmake_minimum_required(VERSION 3.12)

project(crisp.examples.pf.atomic
        VERSION 0.1.0
        LANGUAGES CXX)

add_executable(examples.pf.atomic.spsc
               spsc_boost.cpp
               spsc.cpp
               spsc_boost.hpp
               spsc.hpp
               spsc_main.cpp)

target_link_libraries(examples.pf.atomic.spsc PUBLIC
                      crisp.arch.x86_64.msvc
                      crisp.base.lib
                      crisp.atomic.lib
                      crisp.queue.lib
                      endpoint.queue.lib
                      endpoint.allocator.lib
                      endpoint.atomic.lib)