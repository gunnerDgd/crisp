add_library     (crisp INTERFACE)
add_subdirectory(core)
add_subdirectory(collections)

target_link_libraries(crisp INTERFACE crisp-collections)
target_link_libraries(crisp INTERFACE crisp-core)