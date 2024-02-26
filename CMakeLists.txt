cmake_minimum_required(VERSION 3.0.0)
project(Starry VERSION 0.1.0 LANGUAGES C)

include(CTest)
enable_testing()

file(GLOB_RECURSE SRC_FILES "**/*.c")
file(GLOB_RECURSE HEADER_FILES "**/*.h")

add_executable(
	Starry
	${SRC_FILES}
	${HEADER_FILES}
)

target_link_libraries(Starry PRIVATE m)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
