file (GLOB_RECURSE src_atomic_spsc CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/*.c)

if(BUILD_STATIC_LIBRARY)
    add_library               (lib_atomic_spsc STATIC  ${src_atomic_spsc})
    target_include_directories(lib_atomic_spsc PRIVATE ${CMAKE_SOURCE_DIR}/include)
    target_link_libraries     (lib_atomic_spsc lib_atomic_structure_details)
endif()

if(BUILD_SHARED_LIBRARY)
    add_library               (dll_atomic_spsc SHARED  ${src_atomic_spsc})
    target_include_directories(dll_atomic_spsc PRIVATE ${CMAKE_SOURCE_DIR}/include)
    target_link_libraries     (dll_atomic_spsc lib_atomic_structure_details)
endif()