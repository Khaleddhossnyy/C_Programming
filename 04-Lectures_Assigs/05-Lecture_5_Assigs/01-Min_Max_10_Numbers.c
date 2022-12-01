#include <stdio.h>

void Min_Max(int *ptr_to_Array,int *ptr_Max, int *ptr_Min, int Size)
{
	for(int i=0;i<Size-1;i++)
	{
		for( int j=0;j<Size-1-i;j++)
		{
			if(ptr_to_Array[j] > ptr_to_Array[j+1])
			{
				int Temp=0;
				Temp = ptr_to_Array[j];
				ptr_to_Array[j] = ptr_to_Array[j+1];
				ptr_to_Array[j+1]= Temp;
			}
		}
	}
	
	*ptr_Max = ptr_to_Array[Size-1];
	*ptr_Min = ptr_to_Array[0];
}




int main()
{
	int Number_array[10];
	int Min=0;
	int Max=0;
	
	for(int i=0;i<10;i++)
	{
		printf("Enter the element no %d here : ",i+1);
		scanf("%d",&Number_array[i]);
	}
	
	Min_Max(Number_array,&Max,&Min,10);
	
	printf("The maximum of 10 values is %d \n",Max);
	printf("The minimum of 10 values is %d \n",Min);
	
	return 0;
}