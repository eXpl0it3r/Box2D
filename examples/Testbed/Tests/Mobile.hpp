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

#ifndef MOBILE_HPP
#define MOBILE_HPP

class Mobile : public Test
{
public:

	enum
	{
		e_depth = 4
	};

	Mobile()
	{
		b2::Body* ground;

		// Create ground body.
		{
			b2::BodyDef bodyDef;
			bodyDef.position.Set(0.0f, 20.0f);
			ground = m_world->CreateBody(&bodyDef);
		}

		b2::float32 a = 0.5f;
		b2::Vec2 h(0.0f, a);

		b2::Body* root = AddNode(ground, b2::Vec2_zero, 0, 3.0f, a);

		b2::RevoluteJointDef jointDef;
		jointDef.bodyA = ground;
		jointDef.bodyB = root;
		jointDef.localAnchorA.SetZero();
		jointDef.localAnchorB = h;
		m_world->CreateJoint(&jointDef);
	}

	b2::Body* AddNode(b2::Body* parent, const b2::Vec2& localAnchor, b2::int32 depth, b2::float32 offset, b2::float32 a)
	{
		b2::float32 density = 20.0f;
		b2::Vec2 h(0.0f, a);

		b2::Vec2 p = parent->GetPosition() + localAnchor - h;

		b2::BodyDef bodyDef;
		bodyDef.type = b2::dynamicBody;
		bodyDef.position = p;
		b2::Body* body = m_world->CreateBody(&bodyDef);

		b2::PolygonShape shape;
		shape.SetAsBox(0.25f * a, a);
		body->CreateFixture(&shape, density);

		if (depth == e_depth)
		{
			return body;
		}

		b2::Vec2 a1 = b2::Vec2(offset, -a);
		b2::Vec2 a2 = b2::Vec2(-offset, -a);
		b2::Body* body1 = AddNode(body, a1, depth + 1, 0.5f * offset, a);
		b2::Body* body2 = AddNode(body, a2, depth + 1, 0.5f * offset, a);

		b2::RevoluteJointDef jointDef;
		jointDef.bodyA = body;
		jointDef.localAnchorB = h;

		jointDef.localAnchorA = a1;
		jointDef.bodyB = body1;
		m_world->CreateJoint(&jointDef);

		jointDef.localAnchorA = a2;
		jointDef.bodyB = body2;
		m_world->CreateJoint(&jointDef);

		return body;
	}

	static Test* Create()
	{
		return new Mobile;
	}
};

#endif
