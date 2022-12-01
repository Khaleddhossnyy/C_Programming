#include <stdio.h>

int Max_Function(int Num_1,int Num_2, int Num_3, int Num_4);
int Min_Function(int Num_1, int Num_2, int Num_3, int Num_4);
//--------------------------------------------------------------
int main()
{
	int Num_1,Num_2,Num_3,Num_4;
	
	printf("Enter First Number here : ");
	scanf("%d",&Num_1);
	
	printf("Enter Second Number here : ");
	scanf("%d",&Num_2);
	
	printf("Enter Third Number here : ");
	scanf("%d",&Num_3);
	
	printf("Enter Fourth Number here : ");
	scanf("%d",&Num_4);
	
	int Max = Max_Function(Num_1,Num_2,Num_3,Num_4);
	int Min = Min_Function(Num_1,Num_2,Num_3,Num_4);
	
	printf("The Max of the 4 numbers from the Max function is : %d\n",Max);
	printf("The Min of the 4 numbers from the Min function is : %d\n",Min);
	
	return 0;
}
//-------------------------------------------------------------
int Max_Function(int Num_1,int Num_2, int Num_3, int Num_4)
{
	int Number_Array[4]={Num_1,Num_2,Num_3,Num_4};	
	for(int i=0;i<4-1;i++)
	{
		for( int j=0;j<4-1-i;j++)
		{
				if(Number_Array[j] > Number_Array[j+1])
				{
					int Temp=0;
					Temp = Number_Array[j];
					Number_Array[j] = Number_Array[j+1];
					Number_Array[j+1]= Temp;
				}
		}
	}
	return Number_Array[3];
}
//-------------------------------------------------------------
int Min_Function(int Num_1, int Num_2, int Num_3, int Num_4)
{
	int Number_Array[4]={Num_1,Num_2,Num_3,Num_4};	
	for(int i=0;i<4-1;i++)
	{
		for( int j=0;j<4-1-i;j++)
		{
			if(Number_Array[j] > Number_Array[j+1])
			{
				int Temp=0;
				Temp = Number_Array[j];
				Number_Array[j] = Number_Array[j+1];
				Number_Array[j+1]= Temp;
			}
		}
	}
	return Number_Array[0];
}
//-------------------------------------------------------------