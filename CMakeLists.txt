cmake_minimum_required(VERSION 3.10)
project(kjson VERSION 0.1.0 LANGUAGES C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Options
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

# Output directories
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Include directories
include_directories(include)

# Find Ragel
find_program(RAGEL_EXECUTABLE ragel)
if(NOT RAGEL_EXECUTABLE)
    message(FATAL_ERROR "Ragel not found")
endif()

# Define a macro to process .rl files
macro(ragel_generate_c RL_FILE C_FILE)
    add_custom_command(
        OUTPUT ${C_FILE}
        COMMAND ${RAGEL_EXECUTABLE} -G2 -o ${C_FILE} ${RL_FILE}
        DEPENDS ${RL_FILE}
        COMMENT "Generating ${C_FILE} from ${RL_FILE}"
    )
endmacro()

# Source files
set(RL_SOURCE src/kjson.rl)
set(C_GENERATED src/kjson.c)

# Generate C file from Ragel file
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/${RL_SOURCE}")
    ragel_generate_c(${CMAKE_CURRENT_SOURCE_DIR}/${RL_SOURCE} ${CMAKE_CURRENT_SOURCE_DIR}/${C_GENERATED})
endif()

# Add library
add_library(kjson ${C_GENERATED})

# Add CLI tool
add_executable(kjson_cli src/cli.c)
target_link_libraries(kjson_cli kjson)
set_target_properties(kjson_cli PROPERTIES OUTPUT_NAME kjson)

# Installation
include(GNUInstallDirs)

configure_file(kjson.pc.in kjson.pc @ONLY)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/kjson.pc DESTINATION ${CMAKE_INSTALL_LIBDIR}/pkgconfig)

install(TARGETS kjson kjson_cli
    EXPORT kjsonTargets
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

install(FILES include/kjson.h DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

# Testing
enable_testing()

find_package(cmocka REQUIRED)

add_executable(test_basic test/test_basic.c)
target_link_libraries(test_basic kjson cmocka)
add_test(NAME test_basic COMMAND test_basic)

add_executable(test_standard test/test_standard.c test/test_utils.c)
target_link_libraries(test_standard kjson cmocka)
add_test(NAME test_standard COMMAND test_standard)

add_executable(test_json5 test/test_json5.c test/test_utils.c)
target_link_libraries(test_json5 kjson cmocka)
add_test(NAME test_json5 COMMAND test_json5)
