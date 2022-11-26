cmake_minimum_required(VERSION 3.12)
project(crisp
        VERSION 0.1.0
        LANGUAGES C)

option(FEATURE_CRISP_LIST   ON)
option(FEATURE_CRISP_STACK  ON)
option(FEATURE_CRISP_QUEUE  ON)
option(FEATURE_CRISP_ATOMIC ON)
option(FEATURE_CRISP_TURBO  OFF)

option(OPTION_NO_STDLIB              OFF)
option(OPTION_BUILD_EXAMPLE          ON)
option(OPTION_BUILD_PERFORMANCE_TEST ON)

option(ARCH_X86_64 ON)
option(ARCH_I386   OFF)

include_directories(${CMAKE_SOURCE_DIR})

add_subdirectory(base)

if(NOT OPTION_NO_STDLIB)
        add_subdirectory(crisp/allocator)
endif()

if(ARCH_X86_64)
        add_subdirectory(arch/x86_64)
endif()

if(FEATURE_CRISP_LIST)
        add_subdirectory(list)
        add_subdirectory(crisp/list)
        
        if(OPTION_BUILD_EXAMPLE)
                add_subdirectory(examples/list)
        endif()

        if(OPTION_BUILD_PERFORMANCE_TEST)
                add_subdirectory(examples.performance/list)
        endif()
endif()

if(FEATURE_CRISP_STACK)
        add_subdirectory(stack)
        add_subdirectory(crisp/stack)
endif()

if(FEATURE_CRISP_QUEUE)
        add_subdirectory(queue)
        add_subdirectory(crisp/queue)
        
        if(OPTION_BUILD_EXAMPLE)
                add_subdirectory(examples/queue)
        endif()
endif()

if(FEATURE_CRISP_ATOMIC)
        add_subdirectory(atomic)
        add_subdirectory(crisp/atomic)

        if(OPTION_BUILD_EXAMPLE)
                add_subdirectory(examples/atomic)
        endif()
        if(OPTION_BUILD_PERFORMANCE_TEST)
                add_subdirectory(examples.performance/atomic)
        endif()
endif()

if(FEATURE_CRISP_TURBO)
        add_subdirectory(turbo)
        add_subdirectory(crisp/turbo)
        
        if(OPTION_BUILD_EXAMPLE)
                add_subdirectory(examples/turbo)
        endif()
endif()