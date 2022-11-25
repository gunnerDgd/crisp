cmake_minimum_required(VERSION 3.12)

project(crisp.turbo
        VERSION 0.1.0
        LANGUAGES C)

add_library(crisp.turbo.lib STATIC
            turbo_list.h
            turbo_list.c)

target_link_libraries(crisp.turbo.lib
                      PRIVATE
                      crisp.arch.x86_64.msvc)