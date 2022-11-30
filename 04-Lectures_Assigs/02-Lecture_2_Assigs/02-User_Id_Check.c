#include <stdio.h>

int main()
{
	int ID_Array[5]={1,2,3,4,5};  //array to hold the Id's of users where each number is an id of a user
	char  *User_Name_Array[5]={"Khaled","Alaa","Hossny","Mohamed","Khlood"}; //an array to hold the user names
	long int Password_Array[5]={123,234,456,345,678}; //password of each user 
	
	int ID;
	int Password;
	int Index;
	char ID_Checker=0;
	char Pass_Checker=0;
	
	while(1)
	{
		printf("Please enter the ID here : ");
		scanf("%d",&ID);
		
		for(int i=0;i<5;i++) //to check if the ID entered is a valid one
		{
			if(ID == ID_Array[i])
			{
				Index = i;
				ID_Checker =1;
				printf("Please enter the Password here : "); // if ID is found check for the password
				scanf("%d",&Password);
				
				if (Password == Password_Array[Index]) 
				{
					printf("The user name is  : %s \n",User_Name_Array[Index]);
					Pass_Checker=1;
					printf("\n");
					break;
				}
			}
		}
		if (ID_Checker == 0)
		{
			printf("!!!! Incorrect ID\n");
			printf("\n");
		}

		if ((ID_Checker == 1) && (Pass_Checker ==0))
		{
			printf("!!!! Incorrect Password\n");
			printf("\n");
		}
	
	}
	return 0;
}