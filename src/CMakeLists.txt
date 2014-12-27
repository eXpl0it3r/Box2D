set(INC_ROOT ${PROJECT_SOURCE_DIR}/include/Box2D)
set(SRC_ROOT ${PROJECT_SOURCE_DIR}/src)

set(BOX2D_Collision_SRCS
	${SRC_ROOT}/Collision/BroadPhase.cpp
	${SRC_ROOT}/Collision/CollideCircle.cpp
	${SRC_ROOT}/Collision/CollideEdge.cpp
	${SRC_ROOT}/Collision/CollidePolygon.cpp
	${SRC_ROOT}/Collision/Collision.cpp
	${SRC_ROOT}/Collision/Distance.cpp
	${SRC_ROOT}/Collision/DynamicTree.cpp
	${SRC_ROOT}/Collision/TimeOfImpact.cpp
)
set(BOX2D_Collision_HDRS
	${INC_ROOT}/Collision/BroadPhase.hpp
	${INC_ROOT}/Collision/Collision.hpp
	${INC_ROOT}/Collision/Distance.hpp
	${INC_ROOT}/Collision/DynamicTree.hpp
	${INC_ROOT}/Collision/TimeOfImpact.hpp
)
set(BOX2D_Shapes_SRCS
	${SRC_ROOT}/Collision/Shapes/CircleShape.cpp
	${SRC_ROOT}/Collision/Shapes/EdgeShape.cpp
	${SRC_ROOT}/Collision/Shapes/ChainShape.cpp
	${SRC_ROOT}/Collision/Shapes/PolygonShape.cpp
)
set(BOX2D_Shapes_HDRS
	${INC_ROOT}/Collision/Shapes/CircleShape.hpp
	${INC_ROOT}/Collision/Shapes/EdgeShape.hpp
	${INC_ROOT}/Collision/Shapes/ChainShape.hpp
	${INC_ROOT}/Collision/Shapes/PolygonShape.hpp
	${INC_ROOT}/Collision/Shapes/Shape.hpp
)
set(BOX2D_Common_SRCS
	${SRC_ROOT}/Common/BlockAllocator.cpp
	${SRC_ROOT}/Common/Draw.cpp
	${SRC_ROOT}/Common/Math.cpp
	${SRC_ROOT}/Common/Settings.cpp
	${SRC_ROOT}/Common/StackAllocator.cpp
	${SRC_ROOT}/Common/Timer.cpp
)
set(BOX2D_Common_HDRS
	${INC_ROOT}/Common/BlockAllocator.hpp
	${INC_ROOT}/Common/Draw.hpp
	${INC_ROOT}/Common/GrowableStack.hpp
	${INC_ROOT}/Common/Math.hpp
	${INC_ROOT}/Common/Settings.hpp
	${INC_ROOT}/Common/StackAllocator.hpp
	${INC_ROOT}/Common/Timer.hpp
)
set(BOX2D_Dynamics_SRCS
	${SRC_ROOT}/Dynamics/Body.cpp
	${SRC_ROOT}/Dynamics/ContactManager.cpp
	${SRC_ROOT}/Dynamics/Fixture.cpp
	${SRC_ROOT}/Dynamics/Island.cpp
	${SRC_ROOT}/Dynamics/World.cpp
	${SRC_ROOT}/Dynamics/WorldCallbacks.cpp
)
set(BOX2D_Dynamics_HDRS
	${INC_ROOT}/Dynamics/Body.hpp
	${INC_ROOT}/Dynamics/ContactManager.hpp
	${INC_ROOT}/Dynamics/Fixture.hpp
	${INC_ROOT}/Dynamics/Island.hpp
	${INC_ROOT}/Dynamics/TimeStep.hpp
	${INC_ROOT}/Dynamics/World.hpp
	${INC_ROOT}/Dynamics/WorldCallbacks.hpp
)
set(BOX2D_Contacts_SRCS
	${SRC_ROOT}/Dynamics/Contacts/CircleContact.cpp
	${SRC_ROOT}/Dynamics/Contacts/Contact.cpp
	${SRC_ROOT}/Dynamics/Contacts/ContactSolver.cpp
	${SRC_ROOT}/Dynamics/Contacts/PolygonAndCircleContact.cpp
	${SRC_ROOT}/Dynamics/Contacts/EdgeAndCircleContact.cpp
	${SRC_ROOT}/Dynamics/Contacts/EdgeAndPolygonContact.cpp
	${SRC_ROOT}/Dynamics/Contacts/ChainAndCircleContact.cpp
	${SRC_ROOT}/Dynamics/Contacts/ChainAndPolygonContact.cpp
	${SRC_ROOT}/Dynamics/Contacts/PolygonContact.cpp
)
set(BOX2D_Contacts_HDRS
	${INC_ROOT}/Dynamics/Contacts/CircleContact.hpp
	${INC_ROOT}/Dynamics/Contacts/Contact.hpp
	${INC_ROOT}/Dynamics/Contacts/ContactSolver.hpp
	${INC_ROOT}/Dynamics/Contacts/PolygonAndCircleContact.hpp
	${INC_ROOT}/Dynamics/Contacts/EdgeAndCircleContact.hpp
	${INC_ROOT}/Dynamics/Contacts/EdgeAndPolygonContact.hpp
	${INC_ROOT}/Dynamics/Contacts/ChainAndCircleContact.hpp
	${INC_ROOT}/Dynamics/Contacts/ChainAndPolygonContact.hpp
	${INC_ROOT}/Dynamics/Contacts/PolygonContact.hpp
)
set(BOX2D_Joints_SRCS
	${SRC_ROOT}/Dynamics/Joints/DistanceJoint.cpp
	${SRC_ROOT}/Dynamics/Joints/FrictionJoint.cpp
	${SRC_ROOT}/Dynamics/Joints/GearJoint.cpp
	${SRC_ROOT}/Dynamics/Joints/Joint.cpp
	${SRC_ROOT}/Dynamics/Joints/MotorJoint.cpp
	${SRC_ROOT}/Dynamics/Joints/MouseJoint.cpp
	${SRC_ROOT}/Dynamics/Joints/PrismaticJoint.cpp
	${SRC_ROOT}/Dynamics/Joints/PulleyJoint.cpp
	${SRC_ROOT}/Dynamics/Joints/RevoluteJoint.cpp
	${SRC_ROOT}/Dynamics/Joints/RopeJoint.cpp
	${SRC_ROOT}/Dynamics/Joints/WeldJoint.cpp
	${SRC_ROOT}/Dynamics/Joints/WheelJoint.cpp
)
set(BOX2D_Joints_HDRS
	${INC_ROOT}/Dynamics/Joints/DistanceJoint.hpp
	${INC_ROOT}/Dynamics/Joints/FrictionJoint.hpp
	${INC_ROOT}/Dynamics/Joints/GearJoint.hpp
	${INC_ROOT}/Dynamics/Joints/Joint.hpp
	${INC_ROOT}/Dynamics/Joints/MotorJoint.hpp
	${INC_ROOT}/Dynamics/Joints/MouseJoint.hpp
	${INC_ROOT}/Dynamics/Joints/PrismaticJoint.hpp
	${INC_ROOT}/Dynamics/Joints/PulleyJoint.hpp
	${INC_ROOT}/Dynamics/Joints/RevoluteJoint.hpp
	${INC_ROOT}/Dynamics/Joints/RopeJoint.hpp
	${INC_ROOT}/Dynamics/Joints/WeldJoint.hpp
	${INC_ROOT}/Dynamics/Joints/WheelJoint.hpp
)
set(BOX2D_Rope_SRCS
	${SRC_ROOT}/Rope/Rope.cpp
)
set(BOX2D_Rope_HDRS
	${INC_ROOT}/Rope/Rope.hpp
)
set(BOX2D_General_HDRS
	${INC_ROOT}/Box2D.hpp
)
include_directories( ${PROJECT_SOURCE_DIR}/include )

if(BOX2D_BUILD_SHARED)
	add_library(Box2D_shared SHARED
		${BOX2D_General_HDRS}
		${BOX2D_Joints_SRCS}
		${BOX2D_Joints_HDRS}
		${BOX2D_Contacts_SRCS}
		${BOX2D_Contacts_HDRS}
		${BOX2D_Dynamics_SRCS}
		${BOX2D_Dynamics_HDRS}
		${BOX2D_Common_SRCS}
		${BOX2D_Common_HDRS}
		${BOX2D_Shapes_SRCS}
		${BOX2D_Shapes_HDRS}
		${BOX2D_Collision_SRCS}
		${BOX2D_Collision_HDRS}
		${BOX2D_Rope_SRCS}
		${BOX2D_Rope_HDRS}
	)
	set_target_properties(Box2D_shared PROPERTIES
		OUTPUT_NAME "Box2D"
		CLEAN_DIRECT_OUTPUT 1
		VERSION ${BOX2D_VERSION}
	)
endif()

if(BOX2D_BUILD_STATIC)
	add_library(Box2D STATIC
		${BOX2D_General_HDRS}
		${BOX2D_Joints_SRCS}
		${BOX2D_Joints_HDRS}
		${BOX2D_Contacts_SRCS}
		${BOX2D_Contacts_HDRS}
		${BOX2D_Dynamics_SRCS}
		${BOX2D_Dynamics_HDRS}
		${BOX2D_Common_SRCS}
		${BOX2D_Common_HDRS}
		${BOX2D_Shapes_SRCS}
		${BOX2D_Shapes_HDRS}
		${BOX2D_Collision_SRCS}
		${BOX2D_Collision_HDRS}
		${BOX2D_Rope_SRCS}
		${BOX2D_Rope_HDRS}
	)
	set_target_properties(Box2D PROPERTIES
		CLEAN_DIRECT_OUTPUT 1
		VERSION ${BOX2D_VERSION}
	)
endif()

# These are used to create visual studio folders.
source_group(Collision FILES ${BOX2D_Collision_SRCS} ${BOX2D_Collision_HDRS})
source_group(Collision\\Shapes FILES ${BOX2D_Shapes_SRCS} ${BOX2D_Shapes_HDRS})
source_group(Common FILES ${BOX2D_Common_SRCS} ${BOX2D_Common_HDRS})
source_group(Dynamics FILES ${BOX2D_Dynamics_SRCS} ${BOX2D_Dynamics_HDRS})
source_group(Dynamics\\Contacts FILES ${BOX2D_Contacts_SRCS} ${BOX2D_Contacts_HDRS})
source_group(Dynamics\\Joints FILES ${BOX2D_Joints_SRCS} ${BOX2D_Joints_HDRS})
source_group(Include FILES ${BOX2D_General_HDRS})
source_group(Rope FILES ${BOX2D_Rope_SRCS} ${BOX2D_Rope_HDRS})

if(BOX2D_INSTALL)
	# install headers
	install(FILES ${BOX2D_General_HDRS} DESTINATION include/Box2D)
	install(FILES ${BOX2D_Collision_HDRS} DESTINATION include/Box2D/Collision)
	install(FILES ${BOX2D_Shapes_HDRS} DESTINATION include/Box2D/Collision/Shapes)
	install(FILES ${BOX2D_Common_HDRS} DESTINATION include/Box2D/Common)
	install(FILES ${BOX2D_Dynamics_HDRS} DESTINATION include/Box2D/Dynamics)
	install(FILES ${BOX2D_Contacts_HDRS} DESTINATION include/Box2D/Dynamics/Contacts)
	install(FILES ${BOX2D_Joints_HDRS} DESTINATION include/Box2D/Dynamics/Joints)
	install(FILES ${BOX2D_Rope_HDRS} DESTINATION include/Box2D/Rope)

	# install libraries
	if(BOX2D_BUILD_SHARED)
		install(TARGETS Box2D_shared EXPORT Box2D-targets 
                  LIBRARY DESTINATION ${LIB_INSTALL_DIR}
                  ARCHIVE DESTINATION ${LIB_INSTALL_DIR}
                  RUNTIME DESTINATION bin)
	endif()
	if(BOX2D_BUILD_STATIC)
		install(TARGETS Box2D EXPORT Box2D-targets DESTINATION ${LIB_INSTALL_DIR})
	endif()

	# install build system hooks for third-party apps
	install(EXPORT Box2D-targets DESTINATION ${LIB_INSTALL_DIR}/Box2D)

        set (BOX2D_INCLUDE_DIR ${CMAKE_INSTALL_PREFIX}/include)
        set (BOX2D_INCLUDE_DIRS ${BOX2D_INCLUDE_DIR} )
        set (BOX2D_LIBRARY_DIRS ${CMAKE_INSTALL_PREFIX}/${LIB_INSTALL_DIR})
        set (BOX2D_LIBRARY Box2D)
        set (BOX2D_LIBRARIES ${BOX2D_LIBRARY})
        set (BOX2D_USE_FILE ${CMAKE_INSTALL_PREFIX}/${LIB_INSTALL_DIR}/cmake/Box2D/UseBox2D.cmake)
        configure_file(Box2DConfig.cmake.in ${CMAKE_CURRENT_BINARY_DIR}/Box2DConfig.cmake @ONLY ESCAPE_QUOTES)
        install(FILES ${CMAKE_CURRENT_BINARY_DIR}/Box2DConfig.cmake UseBox2D.cmake DESTINATION ${LIB_INSTALL_DIR}/cmake/Box2D)
endif(BOX2D_INSTALL)
