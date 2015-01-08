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

#ifndef TEST_H
#define TEST_H

#include <Box2D/Box2D.hpp>
#include "DebugDraw.hpp"

#if defined(__APPLE__)
#include <OpenGL/gl3.h>
#else
#include <GL/glew.h>
#endif
#include <GLFW/glfw3.h>

#include <cstdlib>

class Test;
struct Settings;

typedef Test* TestCreateFcn();

#define	RAND_LIMIT	32767
#define DRAW_STRING_NEW_LINE 16

/// Random number in range [-1,1]
inline b2::float32 RandomFloat()
{
	b2::float32 r = static_cast<b2::float32>(std::rand() & (RAND_LIMIT));
	r /= RAND_LIMIT;
	r = 2.0f * r - 1.0f;
	return r;
}

/// Random floating point number in range [lo, hi]
inline b2::float32 RandomFloat(b2::float32 lo, b2::float32 hi)
{
	b2::float32 r = static_cast<b2::float32>(std::rand() & (RAND_LIMIT));
	r /= RAND_LIMIT;
	r = (hi - lo) * r + lo;
	return r;
}

/// Test settings. Some can be controlled in the GUI.
struct Settings
{
	Settings()
	{
		hz = 60.0f;
		velocityIterations = 8;
		positionIterations = 3;
		drawShapes = true;
		drawJoints = true;
		drawAABBs = false;
		drawContactPoints = false;
		drawContactNormals = false;
		drawContactImpulse = false;
		drawFrictionImpulse = false;
		drawCOMs = false;
		drawStats = false;
		drawProfile = false;
		enableWarmStarting = true;
		enableContinuous = true;
		enableSubStepping = false;
		enableSleep = true;
		pause = false;
		singleStep = false;
	}

	b2::float32 hz;
	b2::int32 velocityIterations;
	b2::int32 positionIterations;
	bool drawShapes;
	bool drawJoints;
	bool drawAABBs;
	bool drawContactPoints;
	bool drawContactNormals;
	bool drawContactImpulse;
	bool drawFrictionImpulse;
	bool drawCOMs;
	bool drawStats;
	bool drawProfile;
	bool enableWarmStarting;
	bool enableContinuous;
	bool enableSubStepping;
	bool enableSleep;
	bool pause;
	bool singleStep;
};

struct TestEntry
{
	const char *name;
	TestCreateFcn *createFcn;
};

extern TestEntry g_testEntries[];
// This is called when a joint in the world is implicitly destroyed
// because an attached body is destroyed. This gives us a chance to
// nullify the mouse joint.
class DestructionListener : public b2::DestructionListener
{
public:
	void SayGoodbye(b2::Fixture* fixture) { B2_NOT_USED(fixture); }
	void SayGoodbye(b2::Joint* joint);

	Test* test;
};

const b2::int32 k_maxContactPoints = 2048;

struct ContactPoint
{
	b2::Fixture* fixtureA;
	b2::Fixture* fixtureB;
	b2::Vec2 normal;
	b2::Vec2 position;
	b2::PointState state;
	b2::float32 normalImpulse;
	b2::float32 tangentImpulse;
	b2::float32 separation;
};

class Test : public b2::ContactListener
{
public:

	Test();
	virtual ~Test();

	void DrawTitle(const char *string);
	virtual void Step(Settings* settings);
	virtual void Keyboard(int key) { B2_NOT_USED(key); }
	virtual void KeyboardUp(int key) { B2_NOT_USED(key); }
	void ShiftMouseDown(const b2::Vec2& p);
	virtual void MouseDown(const b2::Vec2& p);
	virtual void MouseUp(const b2::Vec2& p);
	void MouseMove(const b2::Vec2& p);
	void LaunchBomb();
	void LaunchBomb(const b2::Vec2& position, const b2::Vec2& velocity);
	
	void SpawnBomb(const b2::Vec2& worldPt);
	void CompleteBombSpawn(const b2::Vec2& p);

	// Let derived tests know that a joint was destroyed.
	virtual void JointDestroyed(b2::Joint* joint) { B2_NOT_USED(joint); }

	// Callbacks for derived classes.
	virtual void BeginContact(b2::Contact* contact) { B2_NOT_USED(contact); }
	virtual void EndContact(b2::Contact* contact) { B2_NOT_USED(contact); }
	virtual void PreSolve(b2::Contact* contact, const b2::Manifold* oldManifold);
	virtual void PostSolve(b2::Contact* contact, const b2::ContactImpulse* impulse)
	{
		B2_NOT_USED(contact);
		B2_NOT_USED(impulse);
	}

	void ShiftOrigin(const b2::Vec2& newOrigin);

protected:
	friend class DestructionListener;
	friend class BoundaryListener;
	friend class ContactListener;

	b2::Body* m_groundBody;
	b2::AABB m_worldAABB;
	ContactPoint m_points[k_maxContactPoints];
	b2::int32 m_pointCount;
	DestructionListener m_destructionListener;
	b2::int32 m_textLine;
	b2::World* m_world;
	b2::Body* m_bomb;
	b2::MouseJoint* m_mouseJoint;
	b2::Vec2 m_bombSpawnPoint;
	bool m_bombSpawning;
	b2::Vec2 m_mouseWorld;
	b2::int32 m_stepCount;

	b2::Profile m_maxProfile;
	b2::Profile m_totalProfile;
};

#endif
