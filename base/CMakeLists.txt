cmake_minimum_required(VERSION 3.12)
project(crisp.base
        VERSION 0.1.0
        LANGUAGES C)


add_library(base.allocator.stdlib STATIC
            allocator_stdlib.h
            allocator_stdlib.c)