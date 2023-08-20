project(crisp-test-str)
add_executable       (str-init init.c)
target_link_libraries(str-init PUBLIC crisp crisp-arch)

add_executable       (str-push_back push_back.c)
target_link_libraries(str-push_back PUBLIC crisp crisp-arch)