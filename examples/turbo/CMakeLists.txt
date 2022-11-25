cmake_minimum_required(VERSION 3.12)
project(crisp.examples.turbo
        VERSION 0.1.0
        LANGUAGES C)

add_executable(examples.turbo.turbo_list   turbo_list.c)
target_link_libraries(examples.turbo.turbo_list PUBLIC
                      crisp.list.lib
                      crisp.turbo.lib
                      crisp.arch.x86_64.msvc
                      endpoint.list.lib
                      endpoint.turbo.lib)