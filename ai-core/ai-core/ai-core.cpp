#include "ai-core.h"

using namespace std;

//AiManager::AiManager(int id):BaseGameEntity(id),location(0.0, 0.0, 0.0),facing(1.0,0.0,0.0),m_pCurrentState(AiExplore::Instance())
AiManager::AiManager(int id):BaseGameEntity(id)
	{
		cout << "Creating State machine.\n";
		m_pStateMachine = new StateMachine<AiManager>(this);
	}

//AiManager is calling for an update to determine if the player's position is known, 
//if they are in the line of sight, and how many available floor spaces are in each direction
void AiManager::Update(int f, int b, int l, int r, Vector3D pos, bool vis)
{
	magF = f;
	magB = b;
	magL = l;
	magR = r;
	playerPos = pos;
	visible = vis;

	cout << "AiManager::Update()\n";
	m_pStateMachine->Update();
}

void AiManager::Update(void)
{
	m_pStateMachine->Update();
}
//
void AiManager::SetStateExplore()
{
	m_pStateMachine->SetCurrentState(AiExplore::Instance());
}

int AiManager::ReadAvoidArray(int AvoidArray[], int numObs)
{
	for(int i = 0; i< numObs; i++)
	{ 
		AvoidArray[i];
	}

	cout<< "AiManager::ReadAvoidArray() \n";
	m_pStateMachine->SetCurrentState(AiAvoid::Instance());
}