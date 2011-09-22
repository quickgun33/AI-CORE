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
	
}
void AiAvoid::Execute(AiManager* aimanager)
{
	// put code here
		cout << "AiAvoid::Execute()\n";
		
		//If the bot is near one of the variables in the obstacle array, change state to evade
		if (aimanager->GetLocation() = AvoidArray[])
			{aimanager->GetFSM()->ChangeState(AiEvade::Instance());}
		//If the bot is not near one of the variables in the obstacle array, change state to evade
		if (aimanager->GetLocation() != AvoidArray[])
			{aimanager->GetFSM()->ChangeState(AiExplore::Instance());}
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
