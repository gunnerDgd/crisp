cmake_minimum_required(VERSION 3.12)
project(crisp.endpoint.list
        VERSION 0.1.0
        LANGUAGES C)

add_library(endpoint.list.list STATIC
            list.c
            list_iterate.c
            list.h
            list_iterate.h
            dynamic_list.h
            dynamic_list_iterate.h
            dynamic_list.c
            dynamic_list_iterate.c
            type.h)