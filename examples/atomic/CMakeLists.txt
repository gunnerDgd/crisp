cmake_minimum_required(VERSION 3.12)
project(crisp.examples.atomic
        VERSION 0.1.0
        LANGUAGES C)

add_executable(examples.atomic.spsc spsc.c)
target_link_libraries(examples.atomic.spsc PUBLIC
                      base.allocator.stdlib
                      endpoint.allocator.standard_library
                      queue.queue
                      atomic.spsc
                      endpoint.atomic)