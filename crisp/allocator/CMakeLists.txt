cmake_minimum_required(VERSION 3.12)
project(crisp.endpoint.allocator
        VERSION 0.1.0
        LANGUAGES C)

add_library(endpoint.allocator.lib STATIC
            standard_library.h
            standard_library.c)