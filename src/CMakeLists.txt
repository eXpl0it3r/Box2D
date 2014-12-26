set(INC_ROOT ${PROJECT_SOURCE_DIR}/include/Box2D)
set(SRC_ROOT ${PROJECT_SOURCE_DIR}/src)

set(BOX2D_Collision_SRCS
	${SRC_ROOT}/Collision/b2BroadPhase.cpp
	${SRC_ROOT}/Collision/b2CollideCircle.cpp
	${SRC_ROOT}/Collision/b2CollideEdge.cpp
	${SRC_ROOT}/Collision/b2CollidePolygon.cpp
	${SRC_ROOT}/Collision/b2Collision.cpp
	${SRC_ROOT}/Collision/b2Distance.cpp
	${SRC_ROOT}/Collision/b2DynamicTree.cpp
	${SRC_ROOT}/Collision/b2TimeOfImpact.cpp
)
set(BOX2D_Collision_HDRS
	${INC_ROOT}/Collision/b2BroadPhase.hpp
	${INC_ROOT}/Collision/b2Collision.hpp
	${INC_ROOT}/Collision/b2Distance.hpp
	${INC_ROOT}/Collision/b2DynamicTree.hpp
	${INC_ROOT}/Collision/b2TimeOfImpact.hpp
)
set(BOX2D_Shapes_SRCS
	${SRC_ROOT}/Collision/Shapes/b2CircleShape.cpp
	${SRC_ROOT}/Collision/Shapes/b2EdgeShape.cpp
	${SRC_ROOT}/Collision/Shapes/b2ChainShape.cpp
	${SRC_ROOT}/Collision/Shapes/b2PolygonShape.cpp
)
set(BOX2D_Shapes_HDRS
	${INC_ROOT}/Collision/Shapes/b2CircleShape.hpp
	${INC_ROOT}/Collision/Shapes/b2EdgeShape.hpp
	${INC_ROOT}/Collision/Shapes/b2ChainShape.hpp
	${INC_ROOT}/Collision/Shapes/b2PolygonShape.hpp
	${INC_ROOT}/Collision/Shapes/b2Shape.hpp
)
set(BOX2D_Common_SRCS
	${SRC_ROOT}/Common/b2BlockAllocator.cpp
	${SRC_ROOT}/Common/b2Draw.cpp
	${SRC_ROOT}/Common/b2Math.cpp
	${SRC_ROOT}/Common/b2Settings.cpp
	${SRC_ROOT}/Common/b2StackAllocator.cpp
	${SRC_ROOT}/Common/b2Timer.cpp
)
set(BOX2D_Common_HDRS
	${INC_ROOT}/Common/b2BlockAllocator.hpp
	${INC_ROOT}/Common/b2Draw.hpp
	${INC_ROOT}/Common/b2GrowableStack.hpp
	${INC_ROOT}/Common/b2Math.hpp
	${INC_ROOT}/Common/b2Settings.hpp
	${INC_ROOT}/Common/b2StackAllocator.hpp
	${INC_ROOT}/Common/b2Timer.hpp
)
set(BOX2D_Dynamics_SRCS
	${SRC_ROOT}/Dynamics/b2Body.cpp
	${SRC_ROOT}/Dynamics/b2ContactManager.cpp
	${SRC_ROOT}/Dynamics/b2Fixture.cpp
	${SRC_ROOT}/Dynamics/b2Island.cpp
	${SRC_ROOT}/Dynamics/b2World.cpp
	${SRC_ROOT}/Dynamics/b2WorldCallbacks.cpp
)
set(BOX2D_Dynamics_HDRS
	${INC_ROOT}/Dynamics/b2Body.hpp
	${INC_ROOT}/Dynamics/b2ContactManager.hpp
	${INC_ROOT}/Dynamics/b2Fixture.hpp
	${INC_ROOT}/Dynamics/b2Island.hpp
	${INC_ROOT}/Dynamics/b2TimeStep.hpp
	${INC_ROOT}/Dynamics/b2World.hpp
	${INC_ROOT}/Dynamics/b2WorldCallbacks.hpp
)
set(BOX2D_Contacts_SRCS
	${SRC_ROOT}/Dynamics/Contacts/b2CircleContact.cpp
	${SRC_ROOT}/Dynamics/Contacts/b2Contact.cpp
	${SRC_ROOT}/Dynamics/Contacts/b2ContactSolver.cpp
	${SRC_ROOT}/Dynamics/Contacts/b2PolygonAndCircleContact.cpp
	${SRC_ROOT}/Dynamics/Contacts/b2EdgeAndCircleContact.cpp
	${SRC_ROOT}/Dynamics/Contacts/b2EdgeAndPolygonContact.cpp
	${SRC_ROOT}/Dynamics/Contacts/b2ChainAndCircleContact.cpp
	${SRC_ROOT}/Dynamics/Contacts/b2ChainAndPolygonContact.cpp
	${SRC_ROOT}/Dynamics/Contacts/b2PolygonContact.cpp
)
set(BOX2D_Contacts_HDRS
	${INC_ROOT}/Dynamics/Contacts/b2CircleContact.hpp
	${INC_ROOT}/Dynamics/Contacts/b2Contact.hpp
	${INC_ROOT}/Dynamics/Contacts/b2ContactSolver.hpp
	${INC_ROOT}/Dynamics/Contacts/b2PolygonAndCircleContact.hpp
	${INC_ROOT}/Dynamics/Contacts/b2EdgeAndCircleContact.hpp
	${INC_ROOT}/Dynamics/Contacts/b2EdgeAndPolygonContact.hpp
	${INC_ROOT}/Dynamics/Contacts/b2ChainAndCircleContact.hpp
	${INC_ROOT}/Dynamics/Contacts/b2ChainAndPolygonContact.hpp
	${INC_ROOT}/Dynamics/Contacts/b2PolygonContact.hpp
)
set(BOX2D_Joints_SRCS
	${SRC_ROOT}/Dynamics/Joints/b2DistanceJoint.cpp
	${SRC_ROOT}/Dynamics/Joints/b2FrictionJoint.cpp
	${SRC_ROOT}/Dynamics/Joints/b2GearJoint.cpp
	${SRC_ROOT}/Dynamics/Joints/b2Joint.cpp
	${SRC_ROOT}/Dynamics/Joints/b2MotorJoint.cpp
	${SRC_ROOT}/Dynamics/Joints/b2MouseJoint.cpp
	${SRC_ROOT}/Dynamics/Joints/b2PrismaticJoint.cpp
	${SRC_ROOT}/Dynamics/Joints/b2PulleyJoint.cpp
	${SRC_ROOT}/Dynamics/Joints/b2RevoluteJoint.cpp
	${SRC_ROOT}/Dynamics/Joints/b2RopeJoint.cpp
	${SRC_ROOT}/Dynamics/Joints/b2WeldJoint.cpp
	${SRC_ROOT}/Dynamics/Joints/b2WheelJoint.cpp
)
set(BOX2D_Joints_HDRS
	${INC_ROOT}/Dynamics/Joints/b2DistanceJoint.hpp
	${INC_ROOT}/Dynamics/Joints/b2FrictionJoint.hpp
	${INC_ROOT}/Dynamics/Joints/b2GearJoint.hpp
	${INC_ROOT}/Dynamics/Joints/b2Joint.hpp
	${INC_ROOT}/Dynamics/Joints/b2MotorJoint.hpp
	${INC_ROOT}/Dynamics/Joints/b2MouseJoint.hpp
	${INC_ROOT}/Dynamics/Joints/b2PrismaticJoint.hpp
	${INC_ROOT}/Dynamics/Joints/b2PulleyJoint.hpp
	${INC_ROOT}/Dynamics/Joints/b2RevoluteJoint.hpp
	${INC_ROOT}/Dynamics/Joints/b2RopeJoint.hpp
	${INC_ROOT}/Dynamics/Joints/b2WeldJoint.hpp
	${INC_ROOT}/Dynamics/Joints/b2WheelJoint.hpp
)
set(BOX2D_Rope_SRCS
	${SRC_ROOT}/Rope/b2Rope.cpp
)
set(BOX2D_Rope_HDRS
	${INC_ROOT}/Rope/b2Rope.hpp
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
