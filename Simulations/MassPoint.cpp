#include "MassPoint.h"

MassPoint::MassPoint(Vec3 position, Vec3 veclocity, bool isFixed)
{
	m_position = position;
	m_velocity = veclocity;
	m_isFixed = isFixed;
}

Vec3 MassPoint::getPosition()
{
	return m_position;
}
Vec3 MassPoint::getVelocity()
{
	return m_velocity;
}

void MassPoint::setPosition(Vec3 position)
{
	m_position = position;
}
void MassPoint::setVelocity(Vec3 velocity)
{
	m_velocity = velocity;
}
void MassPoint::setAcceleration(Vec3 acceleration)
{
	m_acceleration = acceleration;
}
