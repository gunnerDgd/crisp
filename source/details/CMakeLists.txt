file (GLOB_RECURSE     src_atomic_structure_details 
      CONFIGURE_DEPENS ${CMAKE_CURRENT_SOURCE_DIR}/*.c)

add_library               (lib_atomic_structure_details STATIC
                           ${src_atomic_structure_details})
target_include_directories(lib_atomic_structure_details PRIVATE
                           ${CMAKE_SOURCE_DIR}/include)