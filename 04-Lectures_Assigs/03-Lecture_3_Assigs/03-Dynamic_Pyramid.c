#include <stdio.h>


int main()
{
	
	int Number_Of_Rows;
	printf("Please enter the number of rows in the pyrmaid here : ");
	scanf("%d",&Number_Of_Rows);
	
	for(int i = 0; i < Number_Of_Rows; i++) 
	{
			for(int j=1; j<=Number_Of_Rows-i; j++) //for creating the write amount of spaces in each line
			{
				printf(" ");
			}
		
			for(int k=0; k<(2*i+1) ;k++) //for printing the stars 
			{
				printf("*");
			}
			printf("\n");
	}
	return 0;
}