# Some flags for GLEW
add_definitions(-DGLEW_STATIC)

# Define the framework files.
set(Testbed_Framework_SRCS
	Framework/Main.cpp
	Framework/RenderGL3.cpp
	Framework/RenderGL3.hpp
	Framework/Test.cpp
	Framework/Test.hpp
	Framework/DebugDraw.cpp
	Framework/DebugDraw.hpp
	Framework/imgui.h
	Framework/imgui.cpp
	Framework/stb_truetype.h
)

#define the test files.
set(Testbed_Tests_SRCS
	Tests/TestEntries.cpp
	Tests/AddPair.hpp
	Tests/ApplyForce.hpp
	Tests/BodyTypes.hpp
	Tests/Breakable.hpp
	Tests/Bridge.hpp
	Tests/BulletTest.hpp
	Tests/Cantilever.hpp
	Tests/Car.hpp
	Tests/Chain.hpp
	Tests/CharacterCollision.hpp
	Tests/CollisionFiltering.hpp
	Tests/CollisionProcessing.hpp
	Tests/CompoundShapes.hpp
	Tests/Confined.hpp
	Tests/ContinuousTest.hpp
	Tests/DistanceTest.hpp
	Tests/Dominos.hpp
	Tests/DumpShell.hpp
	Tests/DynamicTreeTest.hpp
	Tests/EdgeShapes.hpp
	Tests/EdgeTest.hpp
	Tests/Gears.hpp
	Tests/OneSidedPlatform.hpp
	Tests/Pinball.hpp
	Tests/PolyCollision.hpp
	Tests/PolyShapes.hpp
	Tests/Prismatic.hpp
	Tests/Pulleys.hpp
	Tests/Pyramid.hpp
	Tests/RayCast.hpp
	Tests/Revolute.hpp
	Tests/Rope.hpp
	Tests/RopeJoint.hpp
	Tests/SensorTest.hpp
	Tests/ShapeEditing.hpp
	Tests/SliderCrank.hpp
	Tests/SphereStack.hpp
	Tests/TheoJansen.hpp
	Tests/Tiles.hpp
	Tests/TimeOfImpact.hpp
	Tests/VaryingFriction.hpp
	Tests/VaryingRestitution.hpp
	Tests/VerticalStack.hpp
	Tests/Web.hpp
)

# These are used to create visual studio folders.
source_group(Framework FILES ${Testbed_Framework_SRCS})
source_group(Tests FILES ${Testbed_Tests_SRCS})

include_directories(
	${OPENGL_INCLUDE_DIR}
	${PROJECT_SOURCE_DIR}/include
	../extlibs/include
)

if(APPLE)
	# We are not using the Apple's framework version, but X11's
	include_directories(/usr/X11/include)
	link_directories(/usr/X11/lib)
	set(OPENGL_LIBRARIES GL GLU X11)
elseif(WIN32)
	set(ADDITIONAL_LIBRARIES winmm)
	
	if(CMAKE_COMPILER_IS_GNUCXX)
		set(CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} "../extlibs/include/")
		set(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} "../extlibs/lib-mingw/")
		
		find_path(GLFW_INCLUDE_DIR GLFW/glfw3.h
			PATH_SUFFIXES include
			PATHS "../extlibs"
		)

		find_library(GLFW_LIBRARY
			NAMES glfw3
			PATH_SUFFIXES lib64 lib
			PATHS "../extlibs/lib-mingw"
		)
	endif(CMAKE_COMPILER_IS_GNUCXX)
endif()

add_executable(Testbed
	${Testbed_Framework_SRCS}
	${Testbed_Tests_SRCS}
)

find_package(GLEW REQUIRED)

include_directories(${GLEW_INCLUDE_DIR} ${GLFW_INCLUDE_DIR})

target_link_libraries(
	Testbed
	box2d
	${GLFW_LIBRARY}
	${GLEW_LIBRARY}
	${ADDITIONAL_LIBRARIES}
	${OPENGL_LIBRARIES}
) 

if(BOX2D_INSTALL_EXAMPLES)
	install(TARGETS Testbed
		RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/examples
	)
endif()
