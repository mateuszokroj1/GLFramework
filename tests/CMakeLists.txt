project(GLFramework.Tests)

add_subdirectory(libs/gtest)

enable_testing()

set(GLFramework_Tests
	src/test.cpp
)

add_executable(${PROJECT_NAME} ${GLFramework_Tests})

	target_link_libraries(${PROJECT_NAME} GLFramework GTest::gtest_main)

	set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)

	include(GoogleTest)

	gtest_discover_tests(${PROJECT_NAME})

	add_custom_command ( TARGET ${PROJECT_NAME} PRE_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy_if_different
		$<TARGET_FILE:GLFramework> $<TARGET_FILE_DIR:GLFramework.Tests>
	)