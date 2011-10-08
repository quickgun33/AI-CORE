#include "ai-core.h"
#include <vector>

 int main ()  
{ 

	// Create a vector for Bot to Spawn 
	Vector3D botVec(1.0, 0.0, 3.0); 
	// Create a velocity for the Bot to be moving when it spawns 
	double botVel = 1.0; 
	// Create a direction for the bot to be facing 
	double facing = 90; 
	// Set bot to aggressive 1 or not aggressive 0 
	bool aggressive = 1; 
 
	// Create a location for the player 
	Vector3D vec(0.0, 0.0, 0.0); 
	
	// Instantiate an AiManager bot named Warren with an ID of 1
	//
	AiManager Warren(1);
	
	// Spawn the Bot at the botVec location, etc.
	Warren.Spawn(facing, botVec, botVel, aggressive);
	// Set the initial bot state to Explore
	Warren.SetStateExplore();
	// Tell the bot it can't see any direction to go 
	// be sure to update this in your game loop
	Warren.Update(0,0,0,0,vec,false);
	// Other possibilities
	// Warren.SetStateChase();
	// Warren.SetStateEvade();
	// Warren.SetStateFollowPath();
	// Warren.SetStateAvoid();

	//Code Added by Jamie Hoseit

	Point3D avoid3DPoint;
    Point3D follow3DPoint;
    Warren.AddAvoidObstacle(avoid3DPoint);

    avoid.x = 2.0;
    avoid.y = 0.0;
    avoid.z = 5.2;

    obstacleLocation.push_back(avoid3DPoint);

    avoid.x = 6.9;
    avoid.y = 0.0;
    avoid.z = 4.8;

    obstacleLocation.push_back(avoid3DPoint);
    

    Warren.AddWayPoint(follow);

    follow.x = 9.1;
    follow.y = 0.0;
    follow.z = 1.2;

    wayPoint.push_back(follow3DPoint);

    follow.x = 1.2;
    follow.y = 0.0;
    follow.z = 3.0;

    wayPoint.push_back(follow3DPoint);
    //End of Jamie Hoseit's code



	// Normally this would be some sort of almost infinite loop
	// This runs through 20 times, and calls update
	//
	for (int i=0; i<20; ++i)
	{
		//
		// The Instantiation of AiManager called Warren
		// gets update by running Warren.Update
		//
	
		// Calculate magF, magB, magL, magR, the player position (if seen)
		// and the player visible to TRUE if we can see the player

		// You will have to calculate the Line of Sight 
		// Hint: the bots location is Warren.GetLocation() and returns Vector3D
		Warren.Update(1,2,3,4,vec,true);

	}

	return 0;
}
