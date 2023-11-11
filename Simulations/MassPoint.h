#pragma once
#include "Simulator.h"

class MassPoint
{
public:
	// Constructors
	MassPoint(Vec3 position, Vec3 veclocity, bool isFixed);

	// Getters
	Vec3 getPosition();
	Vec3 getVelocity();

	// Setters
	void setPosition(Vec3 position);
	void setVelocity(Vec3 velocity);
	void setAcceleration(Vec3 acceleration);

private:
	// Data Attributes
	Vec3 m_position;
	Vec3 m_velocity;
	Vec3 m_acceleration;
	bool m_isFixed;
};

