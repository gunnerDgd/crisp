file (GLOB_RECURSE src_atomic_allocator CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/*.c)

if(BUILD_STATIC_LIBRARY)
    add_library               (lib_atomic_allocator STATIC  ${src_atomic_allocator})
    target_include_directories(lib_atomic_allocator PRIVATE ${CMAKE_SOURCE_DIR}/include)
endif()

if(BUILD_SHARED_LIBRARY)
    add_library               (dll_atomic_allocator SHARED  ${src_atomic_allocator})
    target_include_directories(dll_atomic_allocator PRIVATE ${CMAKE_SOURCE_DIR}/include)
endif()