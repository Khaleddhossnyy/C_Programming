#include <stdio.h>


//struct is like or a box which includes elements not of the same data type 

typedef struct struct_1
	{
		int Salary;
		int Bonus;
		int Deduction;
	}Employee;
		
int main()
{	
	Employee Ahmed;
	Employee Waleed;
	Employee Amr;
	
	int total_Salary=0;
	int total_Bonus=0;
	int total_Deduction=0;
	
	
	printf("Enter the Salary of Ahmed: ");
	scanf("%d",&Ahmed.Salary);
	
	printf("Enter the Bonus of Ahmed: ");
	scanf("%d",&Ahmed.Bonus);
	
	printf("Enter the Deduction of Ahmed: ");
	scanf("%d",&Ahmed.Deduction);
	
	printf("Enter the Salary of Waleed: ");
	scanf("%d",&Waleed.Salary);
	
	printf("Enter the Bonus of Waleed: ");
	scanf("%d",&Waleed.Bonus);
	
	printf("Enter the deduction of Waleed: ");
	scanf("%d",&Waleed.Deduction);
	
	printf("Enter the Salary of Amr: ");
	scanf("%d",&Amr.Salary);
	
	printf("Enter the Bonus of Amr: ");
	scanf("%d",&Amr.Bonus);
	
	printf("Enter the deduction of Amr: ");
	scanf("%d",&Amr.Salary);
	
	total_Salary=Ahmed.Salary + Waleed.Salary + Amr.Salary;
	total_Deduction = Ahmed.Deduction + Waleed.Deduction + Amr.Deduction;
	total_Bonus = Ahmed.Bonus + Waleed.Bonus + Amr.Bonus;

	printf("The total amount should be %d ",total_Salary + total_Bonus - total_Deduction);
	
	
	return 0;
}
