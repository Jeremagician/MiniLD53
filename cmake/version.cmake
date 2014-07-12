find_package(Git)

set(VERSION_NAME "")
set(VERSION_REVISION "")
set(VERSION_DATE "")
set(VERSION_BRANCH "")

if(GIT_FOUND)
  execute_process(
	COMMAND "${GIT_EXECUTABLE}" describe --abbrev=0
	WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}"
	OUTPUT_VARIABLE VERSION_NAME
	OUTPUT_STRIP_TRAILING_WHITESPACE
	ERROR_QUIET
	)

  execute_process(
	COMMAND "${GIT_EXECUTABLE}" rev-parse --short HEAD
	WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}"
	OUTPUT_VARIABLE VERSION_REVISION
	OUTPUT_STRIP_TRAILING_WHITESPACE
	ERROR_QUIET
	)

  execute_process(
	COMMAND "${GIT_EXECUTABLE}" show -s --format=%ci
	WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}"
	OUTPUT_VARIABLE VERSION_DATE
	OUTPUT_STRIP_TRAILING_WHITESPACE
	ERROR_QUIET
	)

  execute_process(
	COMMAND "${GIT_EXECUTABLE}" symbolic-ref --short HEAD
	WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}"
	OUTPUT_VARIABLE VERSION_BRANCH
	OUTPUT_STRIP_TRAILING_WHITESPACE
	ERROR_QUIET
	)
endif()

configure_file(
  "${PROJECT_SOURCE_DIR}/src/Version.hpp.in"
  "${PROJECT_BINARY_DIR}/src/Version.hpp"
)