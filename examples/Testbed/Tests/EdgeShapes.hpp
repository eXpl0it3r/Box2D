/*
* Copyright (c) 2006-2010 Erin Catto http://www.box2d.org
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

#ifndef EDGE_SHAPES_HPP
#define EDGE_SHAPES_HPP

class EdgeShapesCallback : public b2::RayCastCallback
{
public:
	EdgeShapesCallback()
	{
		m_fixture = NULL;
	}

	b2::float32 ReportFixture(b2::Fixture* fixture, const b2::Vec2& point,
							  const b2::Vec2& normal, b2::float32 fraction)
	{
		m_fixture = fixture;
		m_point = point;
		m_normal = normal;

		return fraction;
	}

	b2::Fixture* m_fixture;
	b2::Vec2 m_point;
	b2::Vec2 m_normal;
};

class EdgeShapes : public Test
{
public:

	enum
	{
		e_maxBodies = 256
	};

	EdgeShapes()
	{
		// Ground body
		{
			b2::BodyDef bd;
			b2::Body* ground = m_world->CreateBody(&bd);

			b2::float32 x1 = -20.0f;
			b2::float32 y1 = 2.0f * std::cos(x1 / 10.0f * b2::pi);
			for (b2::int32 i = 0; i < 80; ++i)
			{
				b2::float32 x2 = x1 + 0.5f;
				b2::float32 y2 = 2.0f * std::cos(x2 / 10.0f * b2::pi);

				b2::EdgeShape shape;
				shape.Set(b2::Vec2(x1, y1), b2::Vec2(x2, y2));
				ground->CreateFixture(&shape, 0.0f);

				x1 = x2;
				y1 = y2;
			}
		}

		{
			b2::Vec2 vertices[3];
			vertices[0].Set(-0.5f, 0.0f);
			vertices[1].Set(0.5f, 0.0f);
			vertices[2].Set(0.0f, 1.5f);
			m_polygons[0].Set(vertices, 3);
		}

		{
			b2::Vec2 vertices[3];
			vertices[0].Set(-0.1f, 0.0f);
			vertices[1].Set(0.1f, 0.0f);
			vertices[2].Set(0.0f, 1.5f);
			m_polygons[1].Set(vertices, 3);
		}

		{
			b2::float32 w = 1.0f;
			b2::float32 b = w / (2.0f + std::sqrt(2.0f));
			b2::float32 s = std::sqrt(2.0f) * b;

			b2::Vec2 vertices[8];
			vertices[0].Set(0.5f * s, 0.0f);
			vertices[1].Set(0.5f * w, b);
			vertices[2].Set(0.5f * w, b + s);
			vertices[3].Set(0.5f * s, w);
			vertices[4].Set(-0.5f * s, w);
			vertices[5].Set(-0.5f * w, b + s);
			vertices[6].Set(-0.5f * w, b);
			vertices[7].Set(-0.5f * s, 0.0f);

			m_polygons[2].Set(vertices, 8);
		}

		{
			m_polygons[3].SetAsBox(0.5f, 0.5f);
		}

		{
			m_circle.m_radius = 0.5f;
		}

		m_bodyIndex = 0;
		std::memset(m_bodies, 0, sizeof(m_bodies));

		m_angle = 0.0f;
	}

	void Create(b2::int32 index)
	{
		if (m_bodies[m_bodyIndex] != NULL)
		{
			m_world->DestroyBody(m_bodies[m_bodyIndex]);
			m_bodies[m_bodyIndex] = NULL;
		}

		b2::BodyDef bd;

		b2::float32 x = RandomFloat(-10.0f, 10.0f);
		b2::float32 y = RandomFloat(10.0f, 20.0f);
		bd.position.Set(x, y);
		bd.angle = RandomFloat(-b2::pi, b2::pi);
		bd.type = b2::dynamicBody;

		if (index == 4)
		{
			bd.angularDamping = 0.02f;
		}

		m_bodies[m_bodyIndex] = m_world->CreateBody(&bd);

		if (index < 4)
		{
			b2::FixtureDef fd;
			fd.shape = m_polygons + index;
			fd.friction = 0.3f;
			fd.density = 20.0f;
			m_bodies[m_bodyIndex]->CreateFixture(&fd);
		}
		else
		{
			b2::FixtureDef fd;
			fd.shape = &m_circle;
			fd.friction = 0.3f;
			fd.density = 20.0f;
			m_bodies[m_bodyIndex]->CreateFixture(&fd);
		}

		m_bodyIndex = (m_bodyIndex + 1) % e_maxBodies;
	}

	void DestroyBody()
	{
		for (b2::int32 i = 0; i < e_maxBodies; ++i)
		{
			if (m_bodies[i] != NULL)
			{
				m_world->DestroyBody(m_bodies[i]);
				m_bodies[i] = NULL;
				return;
			}
		}
	}

	void Keyboard(int key)
	{
		switch (key)
		{
		case GLFW_KEY_1:
		case GLFW_KEY_2:
		case GLFW_KEY_3:
		case GLFW_KEY_4:
		case GLFW_KEY_5:
			Create(key - GLFW_KEY_1);
			break;

		case GLFW_KEY_D:
			DestroyBody();
			break;
		}
	}

	void Step(Settings* settings)
	{
		bool advanceRay = settings->pause == 0 || settings->singleStep;

		Test::Step(settings);
		g_debugDraw.DrawString(5, m_textLine, "Press 1-5 to drop stuff");
		m_textLine += DRAW_STRING_NEW_LINE;

		b2::float32 L = 25.0f;
		b2::Vec2 point1(0.0f, 10.0f);
		b2::Vec2 d(L * std::cos(m_angle), -L * b2::Abs(sinf(m_angle)));
		b2::Vec2 point2 = point1 + d;

		EdgeShapesCallback callback;

		m_world->RayCast(&callback, point1, point2);

		if (callback.m_fixture)
		{
			g_debugDraw.DrawPoint(callback.m_point, 5.0f, b2::Color(0.4f, 0.9f, 0.4f));

			g_debugDraw.DrawSegment(point1, callback.m_point, b2::Color(0.8f, 0.8f, 0.8f));

			b2::Vec2 head = callback.m_point + 0.5f * callback.m_normal;
			g_debugDraw.DrawSegment(callback.m_point, head, b2::Color(0.9f, 0.9f, 0.4f));
		}
		else
		{
			g_debugDraw.DrawSegment(point1, point2, b2::Color(0.8f, 0.8f, 0.8f));
		}

		if (advanceRay)
		{
			m_angle += 0.25f * b2::pi / 180.0f;
		}
	}

	static Test* Create()
	{
		return new EdgeShapes;
	}

	b2::int32 m_bodyIndex;
	b2::Body* m_bodies[e_maxBodies];
	b2::PolygonShape m_polygons[4];
	b2::CircleShape m_circle;

	b2::float32 m_angle;
};

#endif
