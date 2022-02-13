

add_subdirectory(libs/gtest)

if(WIN32)
	# For Windows: Prevent overriding the parent project's compiler/linker settings
	set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif()

enable_testing()

set(GLFramework_Tests "")
	FILE(GLOB children RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/src/*)
	FOREACH(child ${children})
		list(APPEND GLFramework_Tests ${child})
	ENDFOREACH()

link_directories(../)

add_executable(${PROJECT_NAME}.Tests ${GLFramework_Tests})

	target_link_libraries(${PROJECT_NAME}.Tests GLFramework GTest::gtest_main)

	include(GoogleTest)

	gtest_discover_tests(${PROJECT_NAME}.Tests)