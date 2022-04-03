cmake_minimum_required(VERSION 3.14)

set(CMAKE_STATIC_LIBRARY_PREFIX "")
set(CMAKE_SHARED_LIBRARY_PREFIX "")

add_subdirectory(libs)
add_subdirectory(tests)

project(GLFramework C CXX)

	set(CXX_STANDARD 20)

	set(GLFramework_Sources
		src/GLFramework.cpp
	)

	add_library(${PROJECT_NAME} SHARED ${GLFramework_Sources})
	add_library(src_for_test ${GLFramework_Sources})

	set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

	target_include_directories(${PROJECT_NAME} PUBLIC include)
	target_link_libraries(${PROJECT_NAME} PRIVATE glad_interface PRIVATE glfw)

	target_include_directories(src_for_test PUBLIC include)
	target_link_libraries(src_for_test PRIVATE glad_interface PRIVATE glfw)

if(GLFramework_SharedBuild)

	install(TARGETS ${PROJECT_NAME} EXPORT GLFrameworkTargets
		LIBRARY DESTINATION lib
		ARCHIVE DESTINATION lib
		RUNTIME DESTINATION bin
		INCLUDES DESTINATION include
		FILES glframework_export.h DESTINATION include
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