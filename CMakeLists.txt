cmake_minimum_required(VERSION 3.14)

add_subdirectory(libs)

project(GLFramework C CXX)

	set(CXX_STANDARD 20)

	set(GLFramework_Sources "")
	FILE(GLOB children RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/src/*)
	FOREACH(child ${children})
		list(APPEND GLFramework_Sources ${child})
	ENDFOREACH()

	add_library(${PROJECT_NAME} SHARED ${GLFramework_Sources})

	target_include_directories(${PROJECT_NAME} PUBLIC include)
	target_link_libraries(${PROJECT_NAME} PRIVATE glad_interface PRIVATE glfw)

	option(GLFramework_BuildTests "Build test project" OFF)
	if(GLFramework_BuildTests)
		add_subdirectory(tests)
	endif()