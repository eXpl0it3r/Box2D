/*
* Copyright (c) 2006-2012 Erin Catto http://www.box2d.org
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

#ifndef AddPair_HPP
#define AddPair_HPP

class AddPair : public Test
{
public:

	AddPair()
	{
		m_world->SetGravity(b2::Vec2(0.0f,0.0f));
		{
			b2::CircleShape shape;
			shape.m_p.SetZero();
			shape.m_radius = 0.1f;

			float minX = -6.0f;
			float maxX = 0.0f;
			float minY = 4.0f;
			float maxY = 6.0f;
			
			for (b2::int32 i = 0; i < 400; ++i)
			{
				b2::BodyDef bd;
				bd.type = b2::dynamicBody;
				bd.position = b2::Vec2(RandomFloat(minX,maxX),RandomFloat(minY,maxY));
				b2::Body* body = m_world->CreateBody(&bd);
				body->CreateFixture(&shape, 0.01f);
			}
		}
		
		{
			b2::PolygonShape shape;
			shape.SetAsBox(1.5f, 1.5f);
			b2::BodyDef bd;
			bd.type = b2::dynamicBody;
			bd.position.Set(-40.0f,5.0f);
			bd.bullet = true;
			b2::Body* body = m_world->CreateBody(&bd);
			body->CreateFixture(&shape, 1.0f);
			body->SetLinearVelocity(b2::Vec2(150.0f, 0.0f));
		}
	}

	static Test* Create()
	{
		return new AddPair;
	}
};

#endif
