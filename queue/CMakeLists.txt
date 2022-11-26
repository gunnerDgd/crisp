cmake_minimum_required(VERSION 3.12)
project(crisp.queue
        VERSION 0.1.0
        LANGUAGES C)

add_library(crisp.queue.lib STATIC
            queue.h
            queue_controller.h
            queue.c
            queue_controller.c
            type.h)