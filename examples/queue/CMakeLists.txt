cmake_minimum_required(VERSION 3.12)
project(crisp.examples.list
        VERSION 0.1.0
        LANGUAGES C)

add_executable(examples.queue queue.c)

target_link_libraries(examples.queue PUBLIC
                      queue.queue
                      endpoint.queue
                      base.allocator.stdlib
                      endpoint.allocator.standard_library)