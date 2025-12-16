cmake_minimum_required(VERSION 3.10)
project(kjson C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

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
# We only generate if the .rl file exists. 
# For now, we will assume src/kjson.c is the source, 
# but eventually it will be generated from src/kjson.rl.
# If src/kjson.rl exists, we use it.
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/${RL_SOURCE}")
    ragel_generate_c(${CMAKE_CURRENT_SOURCE_DIR}/${RL_SOURCE} ${CMAKE_CURRENT_SOURCE_DIR}/${C_GENERATED})
endif()

# Add library
add_library(kjson ${C_GENERATED})

# Testing
enable_testing()
add_subdirectory(test)
