cmake_minimum_required(VERSION 3.12)
project(crisp.examples.atomic
        VERSION 0.1.0
        LANGUAGES CXX)

add_executable(examples.atomic.spsc  spsc.cpp)
add_executable(examples.atomic.stack stack.cpp)

target_link_libraries(examples.atomic.spsc PUBLIC
                      crisp.arch.x86_64.msvc
                      crisp.base.lib
                      crisp.atomic.lib
                      crisp.queue.lib
                      endpoint.queue.lib
                      endpoint.allocator.lib
                      endpoint.atomic.lib)

target_link_libraries(examples.atomic.stack PUBLIC
                      crisp.arch.x86_64.msvc
                      crisp.base.lib
                      crisp.atomic.lib
                      crisp.stack.lib
                      endpoint.stack.lib
                      endpoint.allocator.lib
                      endpoint.atomic.lib)