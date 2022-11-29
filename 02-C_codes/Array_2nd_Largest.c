#include <stdio.h>

int main()
{
	int Array[10] ={-1,2,3,50,60,80,65,0,7,30};
	int First_Max=0;
	int Second_Max=0;
	
	First_Max = Array[0];
	Second_Max = Array[0];
	
	for(int i=0;i<10;i++)
	{
		if (Array[i] >= First_Max)
		{
			Second_Max = First_Max;
			First_Max = Array[i];
			printf("%d\n",Second_Max);
		}
		
		else if( Array[i] > Second_Max && Array[i] < First_Max)
		{
			Second_Max = Array[i]; 
		}
	}
	
	printf("The First largest element is : %d\n",First_Max);
	printf("The second largest element is : %d\n",Second_Max);
	
	return 0;
}