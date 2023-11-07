#pragma once
#include "util/vectorbase.h"
class MassPoint
{
public:
	// Constructors
	MassPoint(Vec3 position, Vec3 veclocity, bool isFixed);

	// Getters
	Vec3 getPosition() 
	{
		return m_position;
	}
	Vec3 getVelocity()
	{
		return m_velocity;
	}

private:
	// Data Attributes
	Vec3 m_position;
	Vec3 m_velocity;
	bool isFixed;
};

