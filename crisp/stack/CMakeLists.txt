cmake_minimum_required(VERSION 3.12)
project(crisp.endpoint.stack
        VERSION 0.1.0
        LANGUAGES C)

add_library(endpoint.stack STATIC
            type.h
            stack.h
            dynamic_stack.h
            stack.c
            dynamic_stack.c)