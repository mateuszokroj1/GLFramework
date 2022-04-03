project(GLFramework.Tests)

add_subdirectory(libs/gtest)

enable_testing()

set(GLFramework_Tests
	src/test.cpp
)

add_executable(${PROJECT_NAME} ${GLFramework_Tests})

	target_link_libraries(${PROJECT_NAME} src_for_test GTest::gtest_main)

	if(WIN32)
	# For Windows: Prevent overriding the parent project's compiler/linker settings
		set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
	endif()

	include(GoogleTest)

	gtest_discover_tests(${PROJECT_NAME})