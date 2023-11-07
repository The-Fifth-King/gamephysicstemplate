#pragma once
class Spring
{
public:
	// Constructors
	Spring(int masspoint1, int masspoint2, float initialLength);

private:
	int masspoint1, masspoint2;
	float initialLength;
};

