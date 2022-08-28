file (GLOB_RECURSE src_atomic_mpmc CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/*.c)

if(BUILD_STATIC_LIBRARY)
    add_library               (lib_atomic_mpmc STATIC  ${src_atomic_mpmc})
    target_include_directories(lib_atomic_mpmc PRIVATE ${CMAKE_SOURCE_DIR}/include)
endif()

if(BUILD_SHARED_LIBRARY)
    add_library               (dll_atomic_mpmc SHARED  ${src_atomic_mpmc})
    target_include_directories(dll_atomic_mpmc PRIVATE ${CMAKE_SOURCE_DIR}/include)
    target_link_libraries     (dll_atomic_mpmc lib_atomic_structure_details)
endif()