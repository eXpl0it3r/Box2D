/*
* Copyright (c) 2006-2013 Erin Catto http://www.box2d.org
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

#ifndef DEBUGDRAW_H
#define DEBUGDRAW_H

#include <Box2D/Box2D.hpp>

struct GLRenderPoints;
struct GLRenderLines;
struct GLRenderTriangles;

//
struct Camera
{
	Camera()
	{
		m_center.Set(0.0f, 20.0f);
		m_extent = 25.0f;
		m_zoom = 1.0f;
		m_width = 1280;
		m_height = 800;
	}

	b2::Vec2 ConvertScreenToWorld(const b2::Vec2& screenPoint);
	b2::Vec2 ConvertWorldToScreen(const b2::Vec2& worldPoint);
	void BuildProjectionMatrix(b2::float32* m, b2::float32 zBias);

	b2::Vec2 m_center;
	b2::float32 m_extent;
	b2::float32 m_zoom;
	b2::int32 m_width;
	b2::int32 m_height;
};

// This class implements debug drawing callbacks that are invoked
// inside b2::World::Step.
class DebugDraw : public b2::Draw
{
public:
	DebugDraw();
	~DebugDraw();

	void Create();
	void Destroy();

	void DrawPolygon(const b2::Vec2* vertices, b2::int32 vertexCount, const b2::Color& color);

	void DrawSolidPolygon(const b2::Vec2* vertices, b2::int32 vertexCount, const b2::Color& color);

	void DrawCircle(const b2::Vec2& center, b2::float32 radius, const b2::Color& color);

	void DrawSolidCircle(const b2::Vec2& center, b2::float32 radius, const b2::Vec2& axis, const b2::Color& color);

	void DrawSegment(const b2::Vec2& p1, const b2::Vec2& p2, const b2::Color& color);

	void DrawTransform(const b2::Transform& xf);

    void DrawPoint(const b2::Vec2& p, b2::float32 size, const b2::Color& color);

    void DrawString(int x, int y, const char* string, ...); 

    void DrawString(const b2::Vec2& p, const char* string, ...);

    void DrawAABB(b2::AABB* aabb, const b2::Color& color);

    void Flush();
    
private:
	GLRenderPoints* m_points;
    GLRenderLines* m_lines;
    GLRenderTriangles* m_triangles;
};

extern DebugDraw g_debugDraw;
extern Camera g_camera;

#endif
