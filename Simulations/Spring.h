#pragma once
class Spring
{
public:
	// Constructors
	Spring(int massPoint1, int massPoint2, float initialLength, float stiffness);

	// Getter
	int getMassPoint1();
	int getMassPoint2();
	int getInitialLength();
	int getStiffness();

private:
	int m_massPoint1, m_massPoint2;
	float m_initialLength, m_stiffness;
};

