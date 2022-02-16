cmake_minimum_required(VERSION 3.14)

set(CMAKE_STATIC_LIBRARY_PREFIX "")
set(CMAKE_SHARED_LIBRARY_PREFIX "")

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_subdirectory(libs)
add_subdirectory(tests)

project(GLFramework C CXX)

	option(GLFramework_SharedBuild "Build to dynamic library" ON)
	option(GLFramework_BuildTests "Build test project" OFF)

	set(CXX_STANDARD 20)

	set(GLFramework_Sources
		src/GLFramework.cpp
	)

	if(GLFramework_SharedBuild)
		add_library(${PROJECT_NAME} SHARED ${GLFramework_Sources})
		include(GenerateExportHeader)
		generate_export_header(${PROJECT_NAME})
		target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_BINARY_DIR})
	else()
		add_library(${PROJECT_NAME} ${GLFramework_Sources})
	endif()

	if (WIN32)
		include (GenerateExportHeader)          
		GENERATE_EXPORT_HEADER(${PROJECT_NAME}
             BASE_NAME ${PROJECT_NAME}
             EXPORT_MACRO_NAME GLFRAMEWORK_EXPORT
             EXPORT_FILE_NAME GLFramework_Export.h
             STATIC_DEFINE GLFramework_BUILT_AS_STATIC)
	endif ()

	set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)

	target_include_directories(${PROJECT_NAME} PUBLIC include PUBLIC ${GLFramework_BINARY_DIR})
	target_link_libraries(${PROJECT_NAME} PRIVATE glad_interface PRIVATE glfw)

	install(TARGETS ${PROJECT_NAME} EXPORT GLFrameworkTargets
		LIBRARY DESTINATION lib
		RUNTIME DESTINATION bin
		ARCHIVE DESTINATION lib
	)
	install(
		DIRECTORY ${CMAKE_SOURCE_DIR}/include/ DESTINATION include FILES_MATCHING PATTERN "*.h*"
	)
	install(
		FILES ${CMAKE_BINARY_DIR}/GLFramework_Export.h DESTINATION include
	)

	include(CMakePackageConfigHelpers)
	export(EXPORT GLFrameworkTargets
		FILE "${CMAKE_CURRENT_BINARY_DIR}/cmake/GLFrameworkTargets.cmake"
	)
	configure_file(cmake/GLFrameworkConfig.cmake
		"${CMAKE_CURRENT_BINARY_DIR}/cmake/GLFrameworkConfig.cmake"
	)

	install(FILES
		cmake/GLFrameworkConfig.cmake
		"${CMAKE_CURRENT_BINARY_DIR}/cmake/GLFrameworkTargets.cmake"
		DESTINATION
		cmake/
	)

endif()