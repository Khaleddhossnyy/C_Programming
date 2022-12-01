#include <stdio.h>

void Bubble_Sort(int *ptr_to_Array, int Size)
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
	
	printf("The Array data after applying bubble sort is : \n");
	for(int i =0;i<Size;i++)
	{
		printf("%d  ",ptr_to_Array[i]);
	}
	
}



int main()
{
	int Number_Array[10] = {10,20,90,40,30,60,85,100,2000,0};
	Bubble_Sort(Number_Array,10);
	return 0;
}