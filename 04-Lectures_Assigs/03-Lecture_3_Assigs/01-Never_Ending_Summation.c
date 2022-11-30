#include <stdio.h>



int main()
{
	int Num_1;
	int Num_2;
	int Sumation=0;
	while(1)
	{
		printf("Enter value of Number 1 here : ");
		scanf("%d",&Num_1);
		
		printf("Enter value of Number 2 here : ");
		scanf("%d",&Num_2);
		
		Sumation = Num_1 + Num_2;
		
		printf("The result is : %d\n",Sumation);
		printf("\n");
	}
	return 0;
}