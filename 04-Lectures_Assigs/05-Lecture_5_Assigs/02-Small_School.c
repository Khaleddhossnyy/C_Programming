#include <stdio.h>

int Get_Max(int *ptr_to_Array, int Size);
int Get_Min(int *ptr_to_Array, int Size);
float Get_Average(int *ptr_to_Array, int Size);
int Number_Passed(int *ptr_to_Array, int Size);

int main()
{
	int Class_1_Array[10]={10,20,80.3,40,60,70,90,88,55,45}; //students grades of class 1
	int Class_2_Array[10]={11,15,22,33,44,55,66,77,80,90.9}; //students grdes of class 2
	int Class_3_Array[10]={12,15,55,60,89,99,44.4,39,50,26.5}; //students grades of class 3
	
	int Max_Grade_1 = Get_Max(Class_1_Array,10);
	int Min_Grade_1 = Get_Min(Class_1_Array,10);
	float Average_1 = Get_Average(Class_1_Array,10);
	int Passing_1 = Number_Passed(Class_1_Array,10);
	int Failling_1 = 10 - Passing_1;
	
	printf("The Number of Passing students in Class 1 is :  %d\n",Passing_1);
	printf("The Number of Failling students in Class 1 is :  %d\n",Failling_1);
	printf("The Highest grade of students in Class 1 is :  %d\n",Max_Grade_1);
	printf("The Lowest grade of students in Class 1 is :  %d\n",Min_Grade_1);
	printf("The Average grade of students in Class 1 is :  %f\n",Average_1);
	printf("\n");

	int Max_Grade_2 = Get_Max(Class_2_Array,10);
	int Min_Grade_2 = Get_Min(Class_2_Array,10);
	float Average_2 = Get_Average(Class_2_Array,10);
	int Passing_2 = Number_Passed(Class_2_Array,10);
	int Failling_2 = 10 - Passing_2;
	
	printf("The Number of Passing students in Class 2 is :  %d\n",Passing_2);
	printf("The Number of Failling students in Class 2 is :  %d\n",Failling_2);
	printf("The Highest grade of students in Class 2 is :  %d\n",Max_Grade_2);
	printf("The Lowest grade of students in Class 2 is :  %d\n",Min_Grade_2);
	printf("The Average grade of students in Class 2 is :  %f\n",Average_2);
	printf("\n");
	
	int Max_Grade_3 = Get_Max(Class_3_Array,10);
	int Min_Grade_3 = Get_Min(Class_3_Array,10);
	float Average_3 = Get_Average(Class_3_Array,10);
	int Passing_3 = Number_Passed(Class_3_Array,10);
	int Failling_3 = 10 - Passing_3;
	
	printf("The Number of Passing students in Class 3 is :  %d\n",Passing_3);
	printf("The Number of Failling students in Class 3 is :  %d\n",Failling_3);
	printf("The Highest grade of students in Class 3 is :  %d\n",Max_Grade_3);
	printf("The Lowest grade of students in Class 3 is :  %d\n",Min_Grade_3);
	printf("The Average grade of students in Class 3 is :  %f\n",Average_3);
	
	return 0;
}

int Get_Max(int *ptr_to_Array, int Size)
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
	
	return ptr_to_Array[Size-1];
}

int Get_Min(int *ptr_to_Array, int Size)
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
	
	return ptr_to_Array[0];
}

float Get_Average(int *ptr_to_Array, int Size)
{
	float Average=0;
	float Sum=0;
	for(int i =0;i<Size;i++)
	{
		Sum = Sum + ptr_to_Array[i];
	}
	
	return (Sum/Size);
}

int Number_Passed(int *ptr_to_Array, int Size)
{
	int Passed = 0;
	for(int i =0 ; i<Size; i++)
	{
		if(ptr_to_Array[i] >= 50)
		{
			Passed ++;
		}
	}
	return Passed;
}