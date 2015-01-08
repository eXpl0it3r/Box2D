# Hello World examples
include_directories (${PROJECT_SOURCE_DIR}/include)
add_executable(HelloWorld HelloWorld.cpp)
target_link_libraries (HelloWorld Box2D)
