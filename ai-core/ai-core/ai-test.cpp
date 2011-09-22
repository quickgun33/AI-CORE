#include "ai-core.h"

int main () 
{
	Vector3D vec(0.00, 0.00, 0.00);
	
	AiManager Warren(1);
	Warren.SetStateExplore();
	for (int i=0; i<20; ++i)
	{
			Warren.Update(1,2,3,4,vec,true);
			Sleep(800);
	}
	
	int AvoidArray[] = {(1,0,2),(5,0,7),(4,0,3),(7,0,0),(0,0,9),(3,0,6),(9,0,1)};
	Warren.ReadAvoidArray(AvoidArray);
	int i = 0;
	if (i < sizeof AvoidArray[]) 
		{i++;}

	return 0;
}

