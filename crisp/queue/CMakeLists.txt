cmake_minimum_required(VERSION 3.12)
project(crisp.endpoint.queue
        VERSION 0.1.0
        LANGUAGES C)

add_library(endpoint.queue.lib STATIC
            type.h
            queue.h
            queue.c)