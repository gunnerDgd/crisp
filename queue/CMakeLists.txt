cmake_minimum_required(VERSION 3.12)
project(crisp.queue
        VERSION 0.1.0
        LANGUAGES C)

add_library(queue.linear STATIC
            linear.h
            linear_controller.h
            linear.c
            linear_controller.c
            type.h)

add_library(queue.circular STATIC
            circular.h
            circular_controller.h
            circular.c
            circular_controller.c
            type.h)