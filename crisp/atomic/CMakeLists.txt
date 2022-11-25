cmake_minimum_required(VERSION 3.12)
project(crisp.endpoint.atomic
        VERSION 0.1.0
        LANGUAGES C)

add_library(endpoint.atomic STATIC
            type.h
            stack.h
            stack.c)