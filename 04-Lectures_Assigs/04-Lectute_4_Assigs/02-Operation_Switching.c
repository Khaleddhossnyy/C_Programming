#include <stdio.h>

float ADD(float Nmber_1, float Number_2);
float SUB(float Nmber_1, float Number_2);
float MUL(float Nmber_1, float Number_2);
float DIV(float Nmber_1, float Number_2);
int Remainder(int Number_1,int Number_2);
int Incremenet(int Number_1);
int Decrement(int Number_2);

int AND(int Number_1, int Number_2);
int OR(int Number_1, int Number_2);
int XOR(int Number_1, int Number_2);
int NOT(int Nmber_1);

int main()
{
	char Operation_Id;
	
	float Num_1;
	float Num_2;
	
	float Operation_Result;
	
	
	int Num_11;
	int Num_22;
	
	printf("Enter the operation ID here : ");
	scanf("%d",&Operation_Id);
	printf("\n");
	
	switch(Operation_Id)
	{
		case 1: //add
			printf("enter first operand : ");
			scanf("%f",&Num_1);
			printf("enter second operand : ");
			scanf("%f",&Num_2);
			Operation_Result = ADD(Num_1,Num_2);
			printf("Result of summation of the two numbers is : %0.3f\n",Operation_Result);
		break;
		
		case 2: //subtract
			printf("enter first operand : ");
			scanf("%f",&Num_1);
			printf("enter second operand : ");
			scanf("%f",&Num_2);
			Operation_Result = SUB(Num_1,Num_2);
			printf("Result of subtracting of the two numbers is : %0.3f\n",Operation_Result);
		break;
		
		case 3: //multiply 
			printf("enter first operand : ");
			scanf("%f",&Num_1);
			printf("enter second operand : ");
			scanf("%f",&Num_2);
			Operation_Result = MUL(Num_1,Num_2);
			printf("Result of multplication of the two numbers is : %0.3f\n",Operation_Result);
		break;
		
		case 4: //division
			printf("enter first operand : ");
			scanf("%f",&Num_1);
			printf("enter second operand : ");
			scanf("%f",&Num_2);
			Operation_Result = DIV(Num_1,Num_2);
			printf("Result of Division of the two numbers is : %0.3f\n",Operation_Result);
		break;
		
		case 5://bit wise and
			printf("enter first operand : ");
			scanf("%d",&Num_11);
			printf("enter second operand : ");
			scanf("%d",&Num_22);
			printf("Result of Anding of the two numbers is : %d\n",AND(Num_11,Num_22));
		break;
		
		case 6: //bit wise Or
			printf("enter first operand : ");
			scanf("%d",&Num_11);
			printf("enter second operand : ");
			scanf("%d",&Num_22);
			printf("Result of Oring of the two numbers is : %d\n",OR(Num_11,Num_22));
		break;
		
		case 7: //bit wise Not
			printf("enter first operand : ");
			scanf("%d",&Num_11);
			printf("Result of Not of the the number is : %d\n",NOT(Num_11));
		break;
		
		case 8: //Xor
			printf("enter first operand : ");
			scanf("%d",&Num_11);
			printf("enter second operand : ");
			scanf("%d",&Num_22);
			printf("Result of xOring of the two numbers is : %d\n",XOR(Num_11,Num_22));
		break;
		
		case 9: //remainder
			printf("enter first operand : ");
			scanf("%d",&Num_11);
			printf("enter second operand : ");
			scanf("%d",&Num_22);
			printf("Result of Remainder of the two numbers is : %d\n",Remainder(Num_11,Num_22));
		break;
		
		case 10: //Increment
			printf("enter first operand : ");
			scanf("%d",&Num_11);
			printf("Result of Incremnting of the number is : %d\n",Incremenet(Num_11));
		break;
		
		case 11: //Decrement
			printf("enter first operand : ");
			scanf("%d",&Num_11);
			printf("Result of Decremnting of the number is : %d\n",Decrement(Num_11));
		break;
	}
}

float ADD(float Nmber_1, float Number_2)
{
	return (Nmber_1 + Number_2);
}

float SUB(float Nmber_1, float Number_2)
{
	return (Nmber_1 -Number_2);
}

float MUL(float Nmber_1, float Number_2)
{
	return (Nmber_1 * Number_2);
}

float DIV(float Nmber_1, float Number_2)
{
	return (Nmber_1 / Number_2);
}

int AND(int Number_1, int Number_2)
{
	return (Number_1 & Number_2);
}

int OR(int Number_1, int Number_2)
{
	return (Number_1 | Number_2);
}

int XOR(int Number_1, int Number_2)
{
	return (Number_1^Number_2);
}

int NOT(int Nmber_1)
{
	return (~Nmber_1);
}

int Remainder (int Number_1,int Number_2)
{
	return (Number_1 % Number_2);
}

int Incremenet(int Number_1)
{
	return (Number_1++);
}

int Decrement(int Number_2)
{
	return (Number_2++);
}