cmake_minimum_required(VERSION 3.12)
project(crisp.examples.queue
        VERSION 0.1.0
        LANGUAGES C)

add_executable(examples.queue queue.c)

target_link_libraries(examples.queue PUBLIC
                      endpoint.queue.lib
                      endpoint.allocator.lib
                      crisp.queue.lib
                      crisp.base.lib)