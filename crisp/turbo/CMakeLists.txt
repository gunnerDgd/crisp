cmake_minimum_required(VERSION 3.12)
project(crisp.endpoint.turbo
        VERSION 0.1.0
        LANGUAGES C)

add_library(endpoint.turbo.lib STATIC
            turbo_list.h
            turbo_list.c)