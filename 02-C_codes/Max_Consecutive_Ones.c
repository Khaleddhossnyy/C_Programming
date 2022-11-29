#include <stdio.h>

int max(int num1, int num2);

int main()
{
	int counter=0;
	int check=0;
	int Max_Number=0;
	long unsigned int Value=7612370;
	for(int i =0;i<32;i++)
	{
		check = ((Value>>i)&(0x01));
		//printf("%d",check);
		if (check == 0)
		{
			counter=0;
			//printf("here");
		}
		else
		{
			counter++;
			//printf("%d\n",counter);
			Max_Number= max(Max_Number,counter); 
		}
		
	}
	printf("The max number of consecutive ones is : %d ",Max_Number);
}

int max(int num1, int num2)
{
	return (num1 > num2 ) ? num1 : num2;
}