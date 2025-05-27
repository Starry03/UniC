cmake_minimum_required(VERSION 3.10.0)
project(UniC VERSION 0.1.0 LANGUAGES C)

add_compile_options(-Wall -Wextra -Werror)

# Include directories
include_directories(
	${CMAKE_SOURCE_DIR}
	${CMAKE_CURRENT_SOURCE_DIR}/unic
)

# Collect all source files
file(GLOB_RECURSE SRCS 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/algebra/*.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/algorithms/*.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/datastructures/*.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/libft/*.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/utils/*.c
)
add_library(unic SHARED ${SRCS})

set_target_properties(unic PROPERTIES 
    PREFIX ""
    OUTPUT_NAME "unic"
)

# Installation
install(TARGETS unic 
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
)
install(DIRECTORY unic/ DESTINATION include/unic FILES_MATCHING PATTERN "*.h")

# example
target_include_directories(unic PUBLIC 
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/unic
)
add_executable(graphdraw examples/examplegraph.c examples/graphdraw.c)
target_link_libraries(graphdraw PRIVATE unic m)

# Enable testing
include(CTest)
enable_testing()

# Packaging
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
