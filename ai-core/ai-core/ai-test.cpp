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
	
	Vector3D AvoidArray[500];

	int AvoidArray[int length] = {(1,0,2),(5,0,7),(4,0,3),(7,0,0),(0,0,9),(3,0,6),(9,0,1)};
	Warren.ReadAvoidArray(AvoidArray[],length);
	int i;
	i = length
	if (i < sizeof AvoidArray[]) 
		{
			i++;
			return AvoidArray[i];
		}
	else 
	{
		break;
	}


	return 0;
}

