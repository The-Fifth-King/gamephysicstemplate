#include "Spring.h"

Spring::Spring(int masspoint1, int masspoint2, float initialLength, float stiffness)
{
	m_massPoint1 = masspoint1;
	m_massPoint2 = masspoint2;
	m_initialLength = initialLength;
	m_stiffness = stiffness;
}

int Spring::getMassPoint1()
{
	return m_massPoint1;
}

int Spring::getMassPoint2()
{
	return m_massPoint2;
}

int Spring::getInitialLength()
{
	return m_initialLength;
}

int Spring::getStiffness()
{
	return m_stiffness;
}


