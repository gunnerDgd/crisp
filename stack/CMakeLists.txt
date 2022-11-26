cmake_minimum_required(VERSION 3.12)
project(crisp.stack
        VERSION 0.1.0
        LANGUAGES C)

add_library(crisp.stack.lib STATIC
            type_stack.h
            stack.h
            stack_controller.h
            stack.c
            stack_controller.c
            type_dynamic_stack.h
            dynamic_stack.h
            dynamic_stack_controller.h
            dynamic_stack.c
            dynamic_stack_controller.c)