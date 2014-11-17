enable_testing()

find_package(Check REQUIRED)
include_directories(${CHECK_INCLUDE_DIRS})

add_executable(test_lz_json test_lz_json.c)

target_link_libraries(test_lz_json
		${CHECK_LIBRARIES}
		lz_json
		lz_kvmap
		lz_tailq
		lz_heap
		pthread
)

configure_file(
		${CMAKE_CURRENT_SOURCE_DIR}/test1.json
		${CMAKE_CURRENT_BINARY_DIR}/test1.json
)

add_test(test_lz_json ${CMAKE_CURRENT_BINARY_DIR}/test_lz_json)
