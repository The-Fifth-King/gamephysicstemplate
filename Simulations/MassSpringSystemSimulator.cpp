#include "MassSpringSystemSimulator.h"
#include "Spring.h"
#include "MassPoint.h"

// Construtors
MassSpringSystemSimulator::MassSpringSystemSimulator()
{
	m_iTestCase = 0;
}

// UI Functions
const char* MassSpringSystemSimulator::getTestCasesStr()
{
	return "Euler,Midpoint";
}
void MassSpringSystemSimulator::initUI(DrawingUtilitiesClass* DUC)
{
	this->DUC = DUC;
	switch (m_iTestCase)
	{
	case 0:break;
	case 1:
		//TwAddVarRW(DUC->g_pTweakBar, "Num Spheres", TW_TYPE_INT32, &m_iNumSpheres, "min=1");
		//TwAddVarRW(DUC->g_pTweakBar, "Sphere Size", TW_TYPE_FLOAT, &m_fSphereSize, "min=0.01 step=0.01");
		break;
	}
}
void MassSpringSystemSimulator::reset()
{
	m_mouse.x = m_mouse.y = 0;
	m_trackmouse.x = m_trackmouse.y = 0;
	m_oldtrackmouse.x = m_oldtrackmouse.y = 0;
}
void MassSpringSystemSimulator::drawFrame(ID3D11DeviceContext* pd3dImmediateContext)
{
	switch (m_iTestCase)
	{
	case 0: 
		for each (MassPoint mp in m_massPoints)
		{
			DUC->drawSphere(mp.getPosition(), Vec3(0.05, 0.05, 0.05));
		}
		for each (Spring sp in m_springs)
		{
			MassPoint mp1 = m_massPoints[sp.getMassPoint1()], mp2 = m_massPoints[sp.getMassPoint2()];
			DUC->beginLine();
			DUC->drawLine(mp1.getPosition(), Vec3(1, 1, 1), mp2.getPosition(), Vec3(1, 1, 1));
			DUC->endLine();
		}
		
		break;
	case 1: break;
	}
}
void MassSpringSystemSimulator::notifyCaseChanged(int testCase)
{
	m_iTestCase = testCase;
	switch (m_iTestCase)
	{
	case 0:
		cout << "Euler!\n";
		setStiffness(40);
		setMass(10);
		setDampingFactor(0);

		addMassPoint(Vec3(0, 0, 0), Vec3(-1, 0, 0), false);
		addMassPoint(Vec3(0, 2, 0), Vec3(1, 0, 0), false);
		addSpring(0, 1, 1);
		printf("%i", getNumberOfMassPoints());
		break;
	case 1:
		cout << "Midpoint!\n";
		//m_iNumSpheres = 100;
		//m_fSphereSize = 0.05f;
		break;
	default:
		cout << "Empty Test!\n";
		break;
	}
}

// Interaction
void MassSpringSystemSimulator::onClick(int x, int y)
{
	m_trackmouse.x = x;
	m_trackmouse.y = y;
}
void MassSpringSystemSimulator::onMouse(int x, int y)
{
	m_oldtrackmouse.x = x;
	m_oldtrackmouse.y = y;
	m_trackmouse.x = x;
	m_trackmouse.y = y;
}

// Simulation
void MassSpringSystemSimulator::externalForcesCalculations(float timeElapsed)
{

}
void MassSpringSystemSimulator::simulateTimestep(float timeStep)
{
	switch (m_iTestCase)
	{
	case 0: 
		explicitEuler(timeStep);
		break;
	case 1: break;
	default:
		break;
	}
}
void MassSpringSystemSimulator::explicitEuler(float timeStep)
{
	vector<Vec3> acceleration(getNumberOfMassPoints());

	//Calculate spring forces
	for each (Spring sp in m_springs)
	{
		int mp1 = sp.getMassPoint1(), mp2 = sp.getMassPoint2();
		Vec3 pos1 = m_massPoints[mp1].getPosition(), pos2 = m_massPoints[mp2].getPosition();
		Vec3 dir1 = normalize(pos1 - pos2), dir2 = normalize(pos2 - pos1);

		Vec3 force1 = -sp.getStiffness() * (length(pos1 - pos2) - sp.getInitialLength()) * dir1;
		Vec3 force2 = -sp.getStiffness() * (length(pos1 - pos2) - sp.getInitialLength()) * dir2;

		acceleration[mp1] += force1;
		acceleration[mp2] += force2;
	}

	// Gravity
	for each (Vec3 accel in acceleration)
	{
		//accel += GRAVITY;
	}

	// Update position and velocity
	for (int i = 0; i < getNumberOfMassPoints(); i++)
	{
		MassPoint* mp = &m_massPoints[i];
		Vec3 oldPos = mp->getPosition(), oldVel = mp->getVelocity();
		mp->setPosition(oldPos + timeStep * oldVel);
		mp->setVelocity(oldVel + timeStep * acceleration[i]);
	}
}
void MassSpringSystemSimulator::midpoint(float timeStep)
{
	for each (MassPoint mp in m_massPoints)
	{

	}
}

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
	MassPoint mp(position, Velocity, isFixed);
	m_massPoints.push_back(mp);
	return getNumberOfMassPoints() - 1;
}
void MassSpringSystemSimulator::addSpring(int masspoint1, int masspoint2, float initialLength)
{
	Spring sp(masspoint1, masspoint2, initialLength, m_fStiffness);
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
	return m_massPoints[index].getPosition();
}
Vec3 MassSpringSystemSimulator::getVelocityOfMassPoint(int index)
{
	return m_massPoints[index].getVelocity();
}
void MassSpringSystemSimulator::applyExternalForce(Vec3 force)
{

}

// Helper
float MassSpringSystemSimulator::length(Vec3 vector)
{
	float dx, dy, dz;
	dx = vector.x * vector.x;
	dy = vector.y * vector.y;
	dz = vector.z * vector.z;
	return sqrt(dx + dy + dz);
}
Vec3 MassSpringSystemSimulator::normalize(Vec3 vector)
{
	vector.x /= vector.x;
	vector.y /= vector.y;
	vector.z /= vector.z;
	return vector;
}
