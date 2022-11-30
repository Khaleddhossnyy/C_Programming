#include <stdio.h>


int main()
{
	int ID_Array[5]={1234,2902,300,450,560};  //array to hold the Id's of users where each number is an id of a user
	char  *User_Name_Array[5]={"Ahmed","Alaa","Hossny","Mohamed","Khlood"}; //an array to hold the user names
	long int Password_Array[5]={7788,234,456,345,678}; //password of each user 
	
	int Entered_ID;
	char Entered_ID_Checker=0;
	long int Entered_Password;
	int Counter=0;
	int Index;
	int Password_Checker=0;
	
	printf("Please enter your ID here : ");
	scanf("%d",&Entered_ID);
	
	for (int i=0;i<5;i++)
	{
		if( ID_Array[i] == Entered_ID)
		{
			Entered_ID_Checker=1;
			Index=i;
			break;
		}
	}
	
	if (Entered_ID_Checker == 1)
	{
		printf("Please enter your password here : ");
		scanf("%d",&Entered_Password);
		
		while( (Entered_ID_Checker==1) && (Counter != 2) )
		{
			{
				if( Password_Array[Index] == Entered_Password)
				{
					Password_Checker=1;
					printf("Welcome %s \n",User_Name_Array[Index]);
					break;
				}
				else
				{
					printf("Try again : ");
					scanf("%d",&Entered_Password);
					Counter++;
				}
			}
		}
		
		if(Password_Checker==0)
		{
			printf("Incorrect password for 3 times,No more tries\n");
		}
	}
	else
	{
		printf("You are Not registered\n");
	}
	return 0;
}