#include <stdio.h>

int main()
{
	float Number_array[3]={};
	
	for(int i=0;i<3;i++) //get three numbers form the user
	{
		printf("Enter the element Number %d : ",i);
		scanf("%f",&Number_array[i]);
		printf("\n");
	}
	
	for(int i=3;i>0;i--)
	{
		printf("The element Number %d is : %f \n",i,Number_array[i-1]);
	}
}
