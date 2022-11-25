cmake_minimum_required(VERSION 3.12)
project(crisp.base
        VERSION 0.1.0
        LANGUAGES C)


add_library(crisp.base.lib STATIC
            type_allocator.h
            type_atomic.h
            type_primitive.h
            allocator_stdlib.h
            allocator_stdlib.c)