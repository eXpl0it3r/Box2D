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

#ifndef PYRAMID_HPP
#define PYRAMID_HPP

class Pyramid : public Test
{
public:
	enum
	{
		e_count = 20
	};

	Pyramid()
	{
		{
			b2::BodyDef bd;
			b2::Body* ground = m_world->CreateBody(&bd);

			b2::EdgeShape shape;
			shape.Set(b2::Vec2(-40.0f, 0.0f), b2::Vec2(40.0f, 0.0f));
			ground->CreateFixture(&shape, 0.0f);
		}

		{
			b2::float32 a = 0.5f;
			b2::PolygonShape shape;
			shape.SetAsBox(a, a);

			b2::Vec2 x(-7.0f, 0.75f);
			b2::Vec2 y;
			b2::Vec2 deltaX(0.5625f, 1.25f);
			b2::Vec2 deltaY(1.125f, 0.0f);

			for (b2::int32 i = 0; i < e_count; ++i)
			{
				y = x;

				for (b2::int32 j = i; j < e_count; ++j)
				{
					b2::BodyDef bd;
					bd.type = b2::dynamicBody;
					bd.position = y;
					b2::Body* body = m_world->CreateBody(&bd);
					body->CreateFixture(&shape, 5.0f);

					y += deltaY;
				}

				x += deltaX;
			}
		}
	}

	void Step(Settings* settings)
	{
		Test::Step(settings);

		//b2::DynamicTree* tree = &m_world->m_contactManager.m_broadPhase.m_tree;

		//if (m_stepCount == 400)
		//{
		//	tree->RebuildBottomUp();
		//}
	}

	static Test* Create()
	{
		return new Pyramid;
	}
};

#endif
