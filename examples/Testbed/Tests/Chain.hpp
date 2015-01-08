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

#ifndef CHAIN_HPP
#define CHAIN_HPP

class Chain : public Test
{
public:
	Chain()
	{
		b2::Body* ground = NULL;
		{
			b2::BodyDef bd;
			ground = m_world->CreateBody(&bd);

			b2::EdgeShape shape;
			shape.Set(b2::Vec2(-40.0f, 0.0f), b2::Vec2(40.0f, 0.0f));
			ground->CreateFixture(&shape, 0.0f);
		}

		{
			b2::PolygonShape shape;
			shape.SetAsBox(0.6f, 0.125f);

			b2::FixtureDef fd;
			fd.shape = &shape;
			fd.density = 20.0f;
			fd.friction = 0.2f;

			b2::RevoluteJointDef jd;
			jd.collideConnected = false;

			const b2::float32 y = 25.0f;
			b2::Body* prevBody = ground;
			for (b2::int32 i = 0; i < 30; ++i)
			{
				b2::BodyDef bd;
				bd.type = b2::dynamicBody;
				bd.position.Set(0.5f + i, y);
				b2::Body* body = m_world->CreateBody(&bd);
				body->CreateFixture(&fd);

				b2::Vec2 anchor(b2::float32(i), y);
				jd.Initialize(prevBody, body, anchor);
				m_world->CreateJoint(&jd);

				prevBody = body;
			}
		}
	}

	static Test* Create()
	{
		return new Chain;
	}
};

#endif
