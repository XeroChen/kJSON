find_package(cmocka REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(test_basic test_basic.c)
target_link_libraries(test_basic kjson cmocka)
add_test(NAME test_basic COMMAND test_basic)

add_executable(test_standard test_standard.c)
target_link_libraries(test_standard kjson cmocka)
add_test(NAME test_standard COMMAND test_standard)

add_executable(test_json5 test_json5.c)
target_link_libraries(test_json5 kjson cmocka)
add_test(NAME test_json5 COMMAND test_json5)

