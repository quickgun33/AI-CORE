#include "ai-states.h"
#include "State.h"
#include "ai-core.h"

#include <iostream>
using namespace std;

// AiChase
AiChase* AiChase::Instance()
{
	static AiChase instance;
	return &instance;
}

void AiChase::Enter(AiManager* aimanager)

{
	// put code here
	cout << "AiChase::Enter()\n";
}
void AiChase::Execute(AiManager* aimanager)
{
	// put code here
	cout << "AiChase::Execute()\n";
	bool x =false, z = false;
	Vector3D chaseVel;

	if(aimanager->GetLocation() != aimanager->GetPlayerPos() && aimanager->GetVisible() == true)
	{
		if(aimanager->GetPlayerPos().x != aimanager->GetLocation().x)
		{
			chaseVel.x = 2;
			aimanager->SetVelocity(chaseVel);
		}
		else
		{
			chaseVel.z = 2;
			aimanager->SetVelocity(chaseVel);
		}
	}
	else
    //
	// This code will not work
	//aimanager->GetFSM()->ChangeState(aimanager->GetPrevious());
	//
	// This code works...
	aimanager->GetFSM()->ChangeState(AiExplore::Instance());

}
void AiChase::Exit(AiManager* aimanager)
{
	// put code here
	cout << "AiChase::Exit()\n";
}


// AiExplore
AiExplore* AiExplore::Instance()
{
	static AiExplore instance;
	return &instance;
}

void AiExplore::Enter(AiManager* aimanager)

{
	// put code here
	cout << "AiExplore::Enter()\n";
}
void AiExplore::Execute(AiManager* aimanager)
{
	// put code here
		cout << "AiExplore::Execute()\n";
		if(aimanager->GetVisible() == true)
			aimanager->GetFSM()->ChangeState(AiChase::Instance());

}
void AiExplore::Exit(AiManager* aimanager)
{
	// put code here
	cout << "AiExplore::Exit()\n";
}


// AiEvade
AiEvade* AiEvade::Instance()
{
	static AiEvade instance;
	return &instance;
}

void AiEvade::Enter(AiManager* aimanager)

{
	// put code here
	cout << "AiEvade::Enter()\n";
}
void AiEvade::Execute(AiManager* aimanager)
{
	// put code here
		cout << "AiEvade::Execute()\n";
		aimanager->GetFSM()->ChangeState(AiAvoid::Instance());

}
void AiEvade::Exit(AiManager* aimanager)
{
	// put code here
	cout << "AiEvade::Exit()\n";
}


// AiAvoid
AiAvoid* AiAvoid::Instance()
{
	static AiAvoid instance;
	return &instance;
}

void AiAvoid::Enter(AiManager* aimanager)

{
	// AiAvoid is called 
	cout << "AiAvoid::Enter()\n";
	//Creating variables
	const int MAX_OBSTACLES = 20;
	AiAvoid obstacle[MAX_OBSTACLES];
	obstacle = [(x,y,z)];
}
void AiAvoid::Execute(AiManager* aimanager)
{
	// put code here
		cout << "AiAvoid::Execute()\n";
		//create array of obstacles that the bot will avoid, and a counter
		//to count how many obstacles are in the array 
		int obs = 0;
		obstacle[obs++];
		for (int i = 0; i < obs; ++i)

		aimanager->GetLocation();
		if (Location = obstacle[])
			aimanager->GetFSM()->ChangeState(AiEvade::Instance());
		else 
			aimanager->GetFSM()->ChangeState(AiExplore::Instance());
}
void AiAvoid::Exit(AiManager* aimanager)
{
	// put code here
	cout << "AiAvoid::Exit()\n";
}


// AiFollowPath
AiFollowPath* AiFollowPath::Instance()
{
	static AiFollowPath instance;
	return &instance;
}

void AiFollowPath::Enter(AiManager* aimanager)

{
	// put code here
	cout << "AiFollowPath::Enter()\n";
}
void AiFollowPath::Execute(AiManager* aimanager)
{
	// put code here
		cout << "AiFollowPath::Execute()\n";
		aimanager->GetFSM()->ChangeState(AiExplore::Instance());

}
void AiFollowPath::Exit(AiManager* aimanager)
{
	// put code here
	cout << "AiFollowPath::Exit()\n";
}
