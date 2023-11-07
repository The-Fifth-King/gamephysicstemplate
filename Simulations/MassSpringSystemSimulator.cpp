#include "MassSpringSystemSimulator.h"

// Construtors
MassSpringSystemSimulator::MassSpringSystemSimulator()
{
	
}

// UI Functions
const char* MassSpringSystemSimulator::getTestCasesStr()
{

}
void MassSpringSystemSimulator::initUI(DrawingUtilitiesClass* DUC)
{
	
}
void MassSpringSystemSimulator::reset()
{

}
void MassSpringSystemSimulator::drawFrame(ID3D11DeviceContext* pd3dImmediateContext){}
void MassSpringSystemSimulator::notifyCaseChanged(int testCase){}
void MassSpringSystemSimulator::externalForcesCalculations(float timeElapsed){}
void MassSpringSystemSimulator::simulateTimestep(float timeStep){}
void MassSpringSystemSimulator::onClick(int x, int y){}
void MassSpringSystemSimulator::onMouse(int x, int y){}

// Specific Functions
void MassSpringSystemSimulator::setMass(float mass)
{
	m_fMass = mass;
}
void MassSpringSystemSimulator::setStiffness(float stiffness)
{
	m_fStiffness = stiffness;
}
void MassSpringSystemSimulator::setDampingFactor(float damping)
{
	m_fDamping = damping;
}
int MassSpringSystemSimulator::addMassPoint(Vec3 position, Vec3 Velocity, bool isFixed)
{
	MassPoint* mp = new MassPoint(position, Velocity, isFixed);
	m_massPoints.push_back(mp);
}
void MassSpringSystemSimulator::addSpring(int masspoint1, int masspoint2, float initialLength)
{
	Spring* sp = new Spring(masspoint1, masspoint2, initialLength);
	m_springs.push_back(sp);
}
int MassSpringSystemSimulator::getNumberOfMassPoints()
{
	return m_massPoints.size();
}
int MassSpringSystemSimulator::getNumberOfSprings()
{
	return m_springs.size();
}
Vec3 MassSpringSystemSimulator::getPositionOfMassPoint(int index)
{
	list<MassPoint*>::iterator itr = m_massPoints.begin();
	for (int i = 0; i < index; i++) itr++;
	return (*itr)->getPosition();
}
Vec3 MassSpringSystemSimulator::getVelocityOfMassPoint(int index)
{
	list<MassPoint*>::iterator itr = m_massPoints.begin();
	for (int i = 0; i < index; i++) itr++;
	return (*itr)->getVelocity();
}
void MassSpringSystemSimulator::applyExternalForce(Vec3 force)
{

}
