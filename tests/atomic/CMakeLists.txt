project(crisp-test-atomic)
add_executable       (add add.c)
target_link_libraries(add PUBLIC crisp crisp-arch)