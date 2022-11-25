cmake_minimum_required(VERSION 3.12)

project(crisp.atomic
        VERSION 0.1.0
        LANGUAGES C)

add_library(crisp.atomic.lib STATIC
            type_spsc.h
            type_stack.h
            stack.h
            spsc.h
            stack.c
            spsc.c)