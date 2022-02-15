cmake_minimum_required(VERSION 3.14)

set(CMAKE_STATIC_LIBRARY_PREFIX "")
set(CMAKE_SHARED_LIBRARY_PREFIX "")

add_subdirectory(libs)

project(GLFramework C CXX)

	option(GLFramework_SharedBuild "Build to dynamic library" ON)
	option(GLFramework_BuildTests "Build test project" OFF)

	set(CXX_STANDARD 20)

	set(GLFramework_Sources "")
	FILE(GLOB children RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/src/*)
	FOREACH(child ${children})
		list(APPEND GLFramework_Sources ${child})
	ENDFOREACH()

	if(GLFramework_SharedBuild)
		add_library(${PROJECT_NAME} SHARED ${GLFramework_Sources})
		include(GenerateExportHeader)
		generate_export_header(${PROJECT_NAME})
		target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_BINARY_DIR})
	else()
		add_library(${PROJECT_NAME} ${GLFramework_Sources})
	endif()

	target_include_directories(${PROJECT_NAME} PUBLIC include)
	target_link_libraries(${PROJECT_NAME} PRIVATE glad_interface PRIVATE glfw)
	
	if(GLFramework_BuildTests)
		add_subdirectory(tests)
	endif()

install(TARGETS ${PROJECT_NAME} DESTINATION lib)
install(DIRECTORY include DESTINATION include)