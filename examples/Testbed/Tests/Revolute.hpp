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

#ifndef REVOLUTE_HPP
#define REVOLUTE_HPP

class Revolute : public Test
{
public:
	Revolute()
	{
		b2::Body* ground = NULL;
		{
			b2::BodyDef bd;
			ground = m_world->CreateBody(&bd);

			b2::EdgeShape shape;
			shape.Set(b2::Vec2(-40.0f, 0.0f), b2::Vec2(40.0f, 0.0f));

			b2::FixtureDef fd;
			fd.shape = &shape;
			//fd.filter.categoryBits = 2;

			ground->CreateFixture(&fd);
		}

		{
			b2::CircleShape shape;
			shape.m_radius = 0.5f;

			b2::BodyDef bd;
			bd.type = b2::dynamicBody;

			b2::RevoluteJointDef rjd;

			bd.position.Set(-10.0f, 20.0f);
			b2::Body* body = m_world->CreateBody(&bd);
			body->CreateFixture(&shape, 5.0f);

			b2::float32 w = 100.0f;
			body->SetAngularVelocity(w);
			body->SetLinearVelocity(b2::Vec2(-8.0f * w, 0.0f));

			rjd.Initialize(ground, body, b2::Vec2(-10.0f, 12.0f));
			rjd.motorSpeed = 1.0f * b2::pi;
			rjd.maxMotorTorque = 10000.0f;
			rjd.enableMotor = false;
			rjd.lowerAngle = -0.25f * b2::pi;
			rjd.upperAngle = 0.5f * b2::pi;
			rjd.enableLimit = true;
			rjd.collideConnected = true;

			m_joint = (b2::RevoluteJoint*)m_world->CreateJoint(&rjd);
		}

		{
			b2::CircleShape circle_shape;
			circle_shape.m_radius = 3.0f;

			b2::BodyDef circle_bd;
			circle_bd.type = b2::dynamicBody;
			circle_bd.position.Set(5.0f, 30.0f);

			b2::FixtureDef fd;
			fd.density = 5.0f;
			fd.filter.maskBits = 1;
			fd.shape = &circle_shape;

			m_ball = m_world->CreateBody(&circle_bd);
			m_ball->CreateFixture(&fd);

			b2::PolygonShape polygon_shape;
			polygon_shape.SetAsBox(10.0f, 0.2f, b2::Vec2 (-10.0f, 0.0f), 0.0f);

			b2::BodyDef polygon_bd;
			polygon_bd.position.Set(20.0f, 10.0f);
			polygon_bd.type = b2::dynamicBody;
			polygon_bd.bullet = true;
			b2::Body* polygon_body = m_world->CreateBody(&polygon_bd);
			polygon_body->CreateFixture(&polygon_shape, 2.0f);

			b2::RevoluteJointDef rjd;
			rjd.Initialize(ground, polygon_body, b2::Vec2(20.0f, 10.0f));
			rjd.lowerAngle = -0.25f * b2::pi;
			rjd.upperAngle = 0.0f * b2::pi;
			rjd.enableLimit = true;
			m_world->CreateJoint(&rjd);
		}

		// Tests mass computation of a small object far from the origin
		{
			b2::BodyDef bodyDef;
			bodyDef.type = b2::dynamicBody;
			b2::Body* body = m_world->CreateBody(&bodyDef);
		
			b2::PolygonShape polyShape;		
			b2::Vec2 verts[3];
			verts[0].Set( 17.63f, 36.31f );
			verts[1].Set( 17.52f, 36.69f );
			verts[2].Set( 17.19f, 36.36f );
			polyShape.Set(verts, 3);
		
			b2::FixtureDef polyFixtureDef;
			polyFixtureDef.shape = &polyShape;
			polyFixtureDef.density = 1;

			body->CreateFixture(&polyFixtureDef);	//assertion hits inside here
		}

	}

	void Keyboard(int key)
	{
		switch (key)
		{
		case GLFW_KEY_L:
			m_joint->EnableLimit(!m_joint->IsLimitEnabled());
			break;

		case GLFW_KEY_M:
			m_joint->EnableMotor(!m_joint->IsMotorEnabled());
			break;
		}
	}

	void Step(Settings* settings)
	{
		Test::Step(settings);
		g_debugDraw.DrawString(5, m_textLine, "Keys: (l) limits, (m) motor");
		m_textLine += DRAW_STRING_NEW_LINE;

		//if (m_stepCount == 360)
		//{
		//	m_ball->SetTransform(b2::Vec2(0.0f, 0.5f), 0.0f);
		//}

		//b2::float32 torque1 = m_joint1->GetMotorTorque();
		//g_debugDraw.DrawString(5, m_textLine, "Motor Torque = %4.0f, %4.0f : Motor Force = %4.0f", (float) torque1, (float) torque2, (float) force3);
		//m_textLine += DRAW_STRING_NEW_LINE;
	}

	static Test* Create()
	{
		return new Revolute;
	}

	b2::Body* m_ball;
	b2::RevoluteJoint* m_joint;
};

#endif
