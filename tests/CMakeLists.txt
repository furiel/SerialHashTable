find_package(Criterion REQUIRED)

add_executable(test_serial_hash test_serial_hash.c)
target_link_libraries(test_serial_hash PRIVATE serialhashtable ${CRITERION_LIBRARY})
add_test(test_serial_hash test_serial_hash)

add_executable(test_serial_list test_serial_list.c)
target_link_libraries(test_serial_list PRIVATE serialhashtable ${CRITERION_LIBRARY})
add_test(test_serial_list test_serial_list)
