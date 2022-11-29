#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Binary_Array[8] ={0};
int Binary_Array_Rev[8]={0};

int* Convert_Decimal_to_Binary(int Decimal)
{
	int Counter=0;
	while( Decimal > 0)
	{
		Binary_Array[Counter]= Decimal%2;
		printf("Binary_Array[%d] is %d \n",Counter,Binary_Array[Counter]);
		Decimal = Decimal /2;
		Counter++;
	}
	
    printf("Binary_Array[%d] is %d \n",4,Binary_Array[4]);
	printf("Binary_Array[%d] is %d \n",5,Binary_Array[5]);
	printf("Binary_Array[%d] is %d \n",6,Binary_Array[6]);   
	printf("Binary_Array[%d] is %d \n",7,Binary_Array[7]);
	
	int size_Binary = sizeof(Binary_Array)/sizeof(int);
	printf("size_Binary is: %d\n",size_Binary);
	int temp=0;
	for(int i=0;i<size_Binary;i++)
	{
		Binary_Array_Rev[i]= Binary_Array[size_Binary-i-1];
		printf("Binary_Array_Rev %d is %d\n",i,Binary_Array_Rev[i]);
	}

	return Binary_Array_Rev;
}


int main()
{
	int decimal;
	printf("Please enter a decimal number:");
	scanf("%d",&decimal);
	int * ptr_to_Binary_Array;
	ptr_to_Binary_Array = Convert_Decimal_to_Binary(decimal);
	//int size=sizeof(ptr_to_Binary_Array)/sizeof(int);
	//printf("size equals : %d\n",size);
	printf("The pointer points to: %d \n",ptr_to_Binary_Array);
	for(int i=0;i<8;i++)
	{
		printf("%d ",*(ptr_to_Binary_Array+i));
	}
}