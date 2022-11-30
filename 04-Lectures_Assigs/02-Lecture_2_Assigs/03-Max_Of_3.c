#include <stdio.h>


int main()
{
	int Num_1;
	int Num_2;
	int Num_3;
	int Max;
	
	printf("Enter the first Number here : ");
	scanf("%d",&Num_1);
	
	printf("Enter the Second Number here : ");
	scanf("%d",&Num_2);
	
	printf("Enter the Third Number here : ");
	scanf("%d",&Num_3);
	
	if( (Num_1>=Num_2) && (Num_1>=Num_3) )
	{
		Max= Num_1;
	}
	else if((Num_2>Num_1) && (Num_2>Num_3))
	{
		Max=Num_2;
	}
	else
	{
		Max = Num_3;
	}
	
	printf("Maximum is : %d",Max);
	
}