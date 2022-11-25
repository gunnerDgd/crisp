cmake_minimum_required(VERSION 3.12)
project(crisp.list
        VERSION 0.1.0
        LANGUAGES C)

add_library(list.list STATIC
            list_controller.c
            list_iterate.c
            list.c
            list_controller.h
            list_iterate.h
            list.h
            type_list.h)

add_library(list.dynamic_list STATIC
            dynamic_list_controller.c
            dynamic_list.c
            dynamic_list_controller.h
            dynamic_list.h
            type_dynamic_list.h)

add_subdirectory(turbo)