#include <stdio.h>

int main()
{
	
	int Number_Array[10]={};  //array to save the values which the user will enter
	int Start_Index =0;
	int End_Index = 10-1;
	int Middle_Index = (Start_Index + End_Index)/2;
	int Number_To_Search_For;
	int checker=0;
	
	for(int i=0;i<10;i++) //taking 10 int numbers from the user 
	{
		printf("Enter the element no %d here : ",i+1);
		scanf("%d",&Number_Array[i]);
	}
	
	printf("Please enter a number to search for: ");
	scanf("%d",&Number_To_Search_For);
	
	
	while(Start_Index <= End_Index)  //binary search for the number entered by the user 
	{
		Middle_Index = (Start_Index + End_Index)/2;
		if(Number_To_Search_For == Number_Array[Middle_Index])
		{
			printf("The element is found in position %d \n",Middle_Index+1);
			checker =1;
			break;
		}
		if( Number_Array[Middle_Index] < Number_To_Search_For)
		{
			Start_Index = Middle_Index +1;
		}
		else
		{
			End_Index= Middle_Index -1;
		}
	}
	if(checker == 0) //element not found
	{
		printf("The number isn't found in the array you entered here\n"); 
	}
	
	return 0;
}