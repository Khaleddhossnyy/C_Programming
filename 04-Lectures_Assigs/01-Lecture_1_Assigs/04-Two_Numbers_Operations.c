#include <stdio.h>


int main()
{
	int Number_1;
	int Number_2;
	int Operation_result; //to save the result of the operation done on the two entered numbers
	
	
	while(1)
	{
		printf("Enter the first number here : ");
		scanf("%d",&Number_1);
			
		printf("Enter the second number here : ");
		scanf("%d",&Number_2);
		
		printf("\n");
		
		Operation_result = Number_1 + Number_2; //adding
		printf("The summation of the two numbers entered is : %d\n",Operation_result);
		
		Operation_result = Number_1 - Number_2; //subtraction 
		printf("The Subtraction of the two numbers entered is : %d\n",Operation_result);
		
		Operation_result = Number_1 & Number_2; //bit wise anding
		printf("The Anding of the two numbers entered is : %d\n",Operation_result);
		
		Operation_result = Number_1 | Number_2; //bit wise oring
		printf("The Oring of the two numbers entered is : %d\n",Operation_result);
		
		Operation_result = Number_1 ^ Number_2; //bit wise xoring
		printf("The xOring of the two numbers entered is : %d\n",Operation_result);
		
		printf("\n");
	}
	
}