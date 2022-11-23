cmake_minimum_required(VERSION 3.12)
project(crisp.atomic
        VERSION 0.1.0
        LANGUAGES C)

add_library(atomic.spsc STATIC
            type_spsc.h
            spsc.c)