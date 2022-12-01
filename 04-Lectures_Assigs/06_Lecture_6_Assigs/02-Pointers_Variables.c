#include <stdio.h>

typedef int* Ptr; 

int main()
{
	int X,Y,Z;
	
	X=90;
	Y=80;
	Z=100;
	
	Ptr P,Q,R;
	
	P=&X;
	Q=&Y;
	R=&Z;
	
	printf("The value of X is %d\n",X);
	printf("The value of Y is %d\n",Y);
	printf("The value of Z is %d\n",Z);
	printf("\n");
	
	printf("The value of P is %d\n",P);
	printf("The value of Q is %d\n",Q);
	printf("The value of R is %d\n",R);
	printf("\n");
	
	printf("The value of &X is %d\n",&X);
	printf("The value of &Y is %d\n",&Y);
	printf("The value of &Z is %d\n",&Z);
	printf("\n");
	
	printf("The value of *P is %d\n",*P);
	printf("The value of *Q is %d\n",*Q);
	printf("The value of *R is %d\n",*R);
	printf("\n");
	
	printf("Swapping Pointers \n");
	printf("--------------------------------------------\n");
	Ptr temp = R;
	R=P;
	P=Q;
	Q= temp;
	
	printf("The value of X is %d\n",X);
	printf("The value of Y is %d\n",Y);
	printf("The value of Z is %d\n",Z);
	printf("\n");
	
	printf("The value of P is %d\n",P);
	printf("The value of Q is %d\n",Q);
	printf("The value of R is %d\n",R);
	printf("\n");
	
	printf("The value of &X is %d\n",&X);
	printf("The value of &Y is %d\n",&Y);
	printf("The value of &Z is %d\n",&Z);
	printf("\n");
	
	printf("The value of *P is %d\n",*P);
	printf("The value of *Q is %d\n",*Q);
	printf("The value of *R is %d\n",*R);
	printf("\n");
	
	
	
	
	return 0;
}