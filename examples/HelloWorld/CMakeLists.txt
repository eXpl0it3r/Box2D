# Hello World examples
include_directories(${PROJECT_SOURCE_DIR}/include)
add_executable(HelloWorld HelloWorld.cpp)
target_link_libraries(HelloWorld box2d)

if(BOX2D_INSTALL_EXAMPLES)
	install(TARGETS HelloWorld
		RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/examples
	)
endif()
