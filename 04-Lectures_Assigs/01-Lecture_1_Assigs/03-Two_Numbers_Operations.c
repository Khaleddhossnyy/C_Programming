#include <stdio.h>


int main()
{
	int Number_1;
	int Number_2;
	char Operation;
	int Operation_result; //to save the result of the operation done on the two entered numbers
	
	
	while(1)
	{
		printf("Enter the first number here : ");
		scanf("%d",&Number_1);
		
		printf("Enter the second number here : ");
		scanf("%d",&Number_2);
		
		printf("Enter the Operation you want to do on these two numbers : ");
		scanf(" %c",&Operation);
		
		switch(Operation)
		{
			case '+':
				Operation_result = Number_1 + Number_2; //adding
				printf("The summation of the two numbers entered is : %d\n",Operation_result);
				printf("\n");
			break;
			
			case '-':
				Operation_result = Number_1 - Number_2; //subtraction 
				printf("The Subtraction of the two numbers entered is : %d\n",Operation_result);
				printf("\n");
			break;
			
			case '&':
				Operation_result = Number_1 & Number_2; //bit wise anding
				printf("The Anding of the two numbers entered is : %d\n",Operation_result);
				printf("\n");
			break;
			
			case '|': 
				Operation_result = Number_1 | Number_2; //bit wise oring
				printf("The Oring of the two numbers entered is : %d\n",Operation_result);
				printf("\n");
			break;
			
			case '^':
				Operation_result = Number_1 ^ Number_2; //bit wise xoring
				printf("The xOring of the two numbers entered is : %d\n",Operation_result);
				printf("\n");
			break;
			
			default:
				printf("The operation entered is not valid\n");
				printf("\n");
			break;
		}
	}
	
	
	
	
	return 0;
}