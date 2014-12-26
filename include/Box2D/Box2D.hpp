/*
* Copyright (c) 2006-2009 Erin Catto http://www.box2d.org
*
* This software is provided 'as-is', without any express or implied
* warranty.  In no event will the authors be held liable for any damages
* arising from the use of this software.
* Permission is granted to anyone to use this software for any purpose,
* including commercial applications, and to alter it and redistribute it
* freely, subject to the following restrictions:
* 1. The origin of this software must not be misrepresented; you must not
* claim that you wrote the original software. If you use this software
* in a product, an acknowledgment in the product documentation would be
* appreciated but is not required.
* 2. Altered source versions must be plainly marked as such, and must not be
* misrepresented as being the original software.
* 3. This notice may not be removed or altered from any source distribution.
*/

#ifndef BOX2D_HPP
#define BOX2D_HPP

/**
\mainpage Box2D API Documentation

\section intro_sec Getting Started

For documentation please see http://box2d.org/documentation.html

For discussion please visit http://box2d.org/forum
*/

// These include files constitute the main Box2D API

#include <Box2D/Common/b2Settings.hpp>
#include <Box2D/Common/b2Draw.hpp>
#include <Box2D/Common/b2Timer.hpp>

#include <Box2D/Collision/Shapes/b2CircleShape.hpp>
#include <Box2D/Collision/Shapes/b2EdgeShape.hpp>
#include <Box2D/Collision/Shapes/b2ChainShape.hpp>
#include <Box2D/Collision/Shapes/b2PolygonShape.hpp>

#include <Box2D/Collision/b2BroadPhase.hpp>
#include <Box2D/Collision/b2Distance.hpp>
#include <Box2D/Collision/b2DynamicTree.hpp>
#include <Box2D/Collision/b2TimeOfImpact.hpp>

#include <Box2D/Dynamics/b2Body.hpp>
#include <Box2D/Dynamics/b2Fixture.hpp>
#include <Box2D/Dynamics/b2WorldCallbacks.hpp>
#include <Box2D/Dynamics/b2TimeStep.hpp>
#include <Box2D/Dynamics/b2World.hpp>

#include <Box2D/Dynamics/Contacts/b2Contact.hpp>

#include <Box2D/Dynamics/Joints/b2DistanceJoint.hpp>
#include <Box2D/Dynamics/Joints/b2FrictionJoint.hpp>
#include <Box2D/Dynamics/Joints/b2GearJoint.hpp>
#include <Box2D/Dynamics/Joints/b2MotorJoint.hpp>
#include <Box2D/Dynamics/Joints/b2MouseJoint.hpp>
#include <Box2D/Dynamics/Joints/b2PrismaticJoint.hpp>
#include <Box2D/Dynamics/Joints/b2PulleyJoint.hpp>
#include <Box2D/Dynamics/Joints/b2RevoluteJoint.hpp>
#include <Box2D/Dynamics/Joints/b2RopeJoint.hpp>
#include <Box2D/Dynamics/Joints/b2WeldJoint.hpp>
#include <Box2D/Dynamics/Joints/b2WheelJoint.hpp>

#endif // BOX2D_HPP
