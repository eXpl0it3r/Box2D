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

#ifndef POLY_SHAPES_HPP
#define POLY_SHAPES_HPP

/// This tests stacking. It also shows how to use b2::World::Query
/// and b2::TestOverlap.

/// This callback is called by b2::World::QueryAABB. We find all the fixtures
/// that overlap an AABB. Of those, we use b2::TestOverlap to determine which fixtures
/// overlap a circle. Up to 4 overlapped fixtures will be highlighted with a yellow border.
class PolyShapesCallback : public b2::QueryCallback
{
public:
	
	enum
	{
		e_maxCount = 4
	};

	PolyShapesCallback()
	{
		m_count = 0;
	}

	void DrawFixture(b2::Fixture* fixture)
	{
		b2::Color color(0.95f, 0.95f, 0.6f);
		const b2::Transform& xf = fixture->GetBody()->GetTransform();

		switch (fixture->GetType())
		{
		case b2::Shape::e_circle:
			{
				b2::CircleShape* circle = (b2::CircleShape*)fixture->GetShape();

				b2::Vec2 center = b2::Mul(xf, circle->m_p);
				b2::float32 radius = circle->m_radius;

				g_debugDraw->DrawCircle(center, radius, color);
			}
			break;

		case b2::Shape::e_polygon:
			{
				b2::PolygonShape* poly = (b2::PolygonShape*)fixture->GetShape();
				b2::int32 vertexCount = poly->m_count;
				assert(vertexCount <= b2::maxPolygonVertices);
				b2::Vec2 vertices[b2::maxPolygonVertices];

				for (b2::int32 i = 0; i < vertexCount; ++i)
				{
					vertices[i] = b2::Mul(xf, poly->m_vertices[i]);
				}

				g_debugDraw->DrawPolygon(vertices, vertexCount, color);
			}
			break;
				
		default:
			break;
		}
	}

	/// Called for each fixture found in the query AABB.
	/// @return false to terminate the query.
	bool ReportFixture(b2::Fixture* fixture)
	{
		if (m_count == e_maxCount)
		{
			return false;
		}

		b2::Body* body = fixture->GetBody();
		b2::Shape* shape = fixture->GetShape();

		bool overlap = b2::TestOverlap(shape, 0, &m_circle, 0, body->GetTransform(), m_transform);

		if (overlap)
		{
			DrawFixture(fixture);
			++m_count;
		}

		return true;
	}

	b2::CircleShape m_circle;
	b2::Transform m_transform;
	b2::Draw* g_debugDraw;
	b2::int32 m_count;
};

class PolyShapes : public Test
{
public:

	enum
	{
		e_maxBodies = 256
	};

	PolyShapes()
	{
		// Ground body
		{
			b2::BodyDef bd;
			b2::Body* ground = m_world->CreateBody(&bd);

			b2::EdgeShape shape;
			shape.Set(b2::Vec2(-40.0f, 0.0f), b2::Vec2(40.0f, 0.0f));
			ground->CreateFixture(&shape, 0.0f);
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
	}

	void Create(b2::int32 index)
	{
		if (m_bodies[m_bodyIndex] != NULL)
		{
			m_world->DestroyBody(m_bodies[m_bodyIndex]);
			m_bodies[m_bodyIndex] = NULL;
		}

		b2::BodyDef bd;
		bd.type = b2::dynamicBody;

		b2::float32 x = RandomFloat(-2.0f, 2.0f);
		bd.position.Set(x, 10.0f);
		bd.angle = RandomFloat(-b2::pi, b2::pi);

		if (index == 4)
		{
			bd.angularDamping = 0.02f;
		}

		m_bodies[m_bodyIndex] = m_world->CreateBody(&bd);

		if (index < 4)
		{
			b2::FixtureDef fd;
			fd.shape = m_polygons + index;
			fd.density = 1.0f;
			fd.friction = 0.3f;
			m_bodies[m_bodyIndex]->CreateFixture(&fd);
		}
		else
		{
			b2::FixtureDef fd;
			fd.shape = &m_circle;
			fd.density = 1.0f;
			fd.friction = 0.3f;

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

		case GLFW_KEY_A:
			for (b2::int32 i = 0; i < e_maxBodies; i += 2)
			{
				if (m_bodies[i])
				{
					bool active = m_bodies[i]->IsActive();
					m_bodies[i]->SetActive(!active);
				}
			}
			break;

		case GLFW_KEY_D:
			DestroyBody();
			break;
		}
	}

	void Step(Settings* settings)
	{
		Test::Step(settings);

		PolyShapesCallback callback;
		callback.m_circle.m_radius = 2.0f;
		callback.m_circle.m_p.Set(0.0f, 1.1f);
		callback.m_transform.SetIdentity();
		callback.g_debugDraw = &g_debugDraw;

		b2::AABB aabb;
		callback.m_circle.ComputeAABB(&aabb, callback.m_transform, 0);

		m_world->QueryAABB(&callback, aabb);

		b2::Color color(0.4f, 0.7f, 0.8f);
		g_debugDraw.DrawCircle(callback.m_circle.m_p, callback.m_circle.m_radius, color);

		g_debugDraw.DrawString(5, m_textLine, "Press 1-5 to drop stuff");
		m_textLine += DRAW_STRING_NEW_LINE;
		g_debugDraw.DrawString(5, m_textLine, "Press 'a' to (de)activate some bodies");
		m_textLine += DRAW_STRING_NEW_LINE;
		g_debugDraw.DrawString(5, m_textLine, "Press 'd' to destroy a body");
		m_textLine += DRAW_STRING_NEW_LINE;
	}

	static Test* Create()
	{
		return new PolyShapes;
	}

	b2::int32 m_bodyIndex;
	b2::Body* m_bodies[e_maxBodies];
	b2::PolygonShape m_polygons[4];
	b2::CircleShape m_circle;
};

#endif
