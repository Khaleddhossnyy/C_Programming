#include <stdio.h>
#include "Admin.h"
#include "Client.h"
#include "STD_Types.h"
#include <string.h>


u8 Operating_Option;  //0 for admin and 1 for client 

u8 Admin_Checker; // to check if the entered admin is a valid or not
u8 Admin_Mode; // bool to save the admin mode status
u8 Admin[6];  //admin name
u8 Admin_Choice; // to save what is the oeration the admin wants to do
u8 Admin_Choice_inside; // to choose between Making a transaction, changing account status ,..etc
u32 Admin_Pass; //admin password

u8 Client_Mode;

Bank_Account Accounts_Array[100]={}; //array of structs to save clients info, each client in a struct 
u16 Client_Number=0; // a variable to be incremented each time the admin wants to create a new account

u8 Transaction_Checker;
u8 returner;

u64 To_Get;
u64 Existing;

u64 Amount_To_Get;

u32 GLOBAL_Bank_ID;
u32 GLOBAL_Bank_Password;

extern u64 Amount_To_Be_Sent;

int main()
{	
	//--------------------------------------------------
	printf("---- Wlecome to IMT BANK ---- \n");
while(1) //to return to home page
{
	printf("--> For Admin window press 0 \n");
	printf("--> For User/Client window press 1\n");
	printf("--> To exit press 2\n");
	printf("--> Enter the number corresponding to your choice : ");
	scanf("%d", &Operating_Option);
	printf("\n");
	if (Operating_Option == 0) //admin mode is needed
	{
		printf(" Please enter your admin name here : ");
		scanf("%s",&Admin);
		//printf("%c\n",Admin[0]);
		
		printf(" Please enter your admin password here : ");
		scanf("%d",&Admin_Pass);
		printf("\n");
		
		Admin_Checker = Admin_Check(Admin,Admin_Pass);
		//printf("%d",Admin_Checker);
		while (Admin_Checker == 0) //not approved admin , so keep entering the admin name  and password until they match the correct ones
		{
			Admin_Checker = Admin_Check(Admin,Admin_Pass);
			//printf("%d",Admin_Checker);
			if(Admin_Checker == 1) //admin_approved
			{
				Admin_Mode = 1;
				break;
			}
			printf("!!!! Admin name or password is incorrect please try entering both correct again \n");
			printf(" Please enter your admin name here : ");
			scanf("%s",&Admin);
			printf(" Please enter your admin password here : ");
			scanf("%d",&Admin_Pass);
			printf("\n");
		}
		Admin_Mode =1;
	}		
	//printf("%d",Admin_Mode);
	else if(Operating_Option == 1) //client mode is needed
	{
		printf("Please enter your bank ID here : ");
		scanf("%d",&GLOBAL_Bank_ID);
		printf("Please enter your password ID here : ");
		scanf("%d",&GLOBAL_Bank_Password);
		printf("\n");
		u8 User_Checker = BanK_Account_Check(GLOBAL_Bank_ID,GLOBAL_Bank_Password,Accounts_Array);
		
		while (User_Checker == 0 || User_Checker == 2) //not approved client, so keep entering the userID and password until they match the correct ones
		{
			User_Checker = BanK_Account_Check(GLOBAL_Bank_ID,GLOBAL_Bank_Password,Accounts_Array);
			//printf("%d",Admin_Checker);
			if(User_Checker == 1) //user_approved
			{
				Admin_Mode = 0; //client mode
				break;
			}
			printf("!!!! User Bank Account ID or password is incorrect please try entering both correct again \n");
			printf(" Please enter your Bank Account ID here : ");
			scanf("%d",&GLOBAL_Bank_ID);
			printf(" Please enter your password here : ");
			scanf("%d",&GLOBAL_Bank_Password);
			printf("\n");
		}
		Admin_Mode =0;
		
	}
	else if(Operating_Option == 2)
	{
		break;
	}
	//------------------------------------------------- 
	if (Admin_Mode == 1)
	{
		while(1) //keep in this part until the admin wants to exit 
		{
			//ask the admin which operation he wants to does from these 3 options
			printf("--> For Creating a new account press 1\n");
			printf("--> For Opening an existing account press 2\n");
			printf("--> For returning to the Application home page 3\n");
			printf("--> Enter the number corresponding to your choice here : ");
			scanf("%d",&Admin_Choice);
			printf("\n");
			
			if (Admin_Choice == 1) //the admin wants to create a new a account 
			{
				printf("\n");
				//Bank_Account Accounts_Array[100]={}; //array of structs to save clients info, each client in a struct 
				Bank_Account Account;  //create an object from bank account struct to represent an account for each user
				Bank_Account *Ptr_BAccount = &Account; //pointt to this struct 
				Bank_Account ptr_User_Accounts; //will recieve the returned struct from the creation of account function
				Create_IMT_Bank_Account(Ptr_BAccount); //create the account and set it's data 
				ptr_User_Accounts = Set_user_Data(Accounts_Array,Ptr_BAccount,Client_Number); //set the entered user data in the array of struct
				//Accounts_Array[Client_Number].Bank_Account_ID = Accounts_Array[Client_Number-1].Bank_Account_ID+1;
				printf("Member number : %d full name is : %s\n",Client_Number,ptr_User_Accounts.Full_Name);
				printf("Member number : %d full Address is : %s\n",Client_Number,ptr_User_Accounts.Full_Address);
				printf("Member number : %d National ID is : ",Client_Number);
				for (int i=0;i<14;i++)
				{
					printf("%c",ptr_User_Accounts.National_ID[i]);
				}
				printf("\n");
				printf("Member number : %d Age is : %d\n",Client_Number,ptr_User_Accounts.Age);
				printf("Member number : %d Bank Account ID is : %d\n",Client_Number,ptr_User_Accounts.Bank_Account_ID);
				printf("Member number : %d Guardian is : %s\n",Client_Number,ptr_User_Accounts.Guardian);
				printf("Member number : %d Guardian Ntaional ID is : ",Client_Number);
				for (int i=0;i<14;i++)
				{
					printf("%c",ptr_User_Accounts.Guardian_National_ID[i]);
				}
				printf("\n");
				printf("Member number : %d Account status is : %s\n",Client_Number,ptr_User_Accounts.Account_Status);
				printf("Member number : %d Account Balance is : %d\n",Client_Number,ptr_User_Accounts.Balance);
				printf("Member number : %d Account Password is : %d\n",Client_Number,ptr_User_Accounts.Password);
				printf("\n");
				//Client_Number = Client_Number+1; //for setting the data of next user
				for(u16 i =0;i<100;i++)
				{
					if( strcmp(Accounts_Array[i].Full_Name,"")==0) //to get the number of the next client
					{
						Client_Number =i;
						break;
					}
				}
			}
			
			else if (Admin_Choice == 2) // there is a list of options in here 
			{
				while(1)
				{
					printf("--> Enter client Bank account ID of the account you want to open here : ");
					u32 Temp_Bank_Account_ID;
					u8 Bank_Account_ID_Checker;
					scanf("%d",&Temp_Bank_Account_ID);
					Bank_Account_ID_Checker=Bank_Account_ID_Check(Temp_Bank_Account_ID,Accounts_Array);
					while(Bank_Account_ID_Checker == 0)
					{
						printf("The entered bank account ID doesn't exist, try again here : ");
						scanf("%d",&Temp_Bank_Account_ID);
						Bank_Account_ID_Checker=Bank_Account_ID_Check(Temp_Bank_Account_ID,Accounts_Array);
					}
					printf("\n");
					//printf("%d",Bank_Account_ID_Checker);
					
					printf("--> For Making a transaction press 1\n");
					printf("--> For Changing an account status press 2\n");
					printf("--> For getting cash press 3\n");
					printf("--> For Depositing in an account press 4\n");
					printf("--> For returning to the Admin home page press 5\n");
					printf("--> Enter the number corresponding to your choice here : ");
					scanf("%d",&Admin_Choice_inside);
					printf("\n");
					
					if(Admin_Choice_inside == 1) //make a transaction
					{
						Make_A_Transaction(Temp_Bank_Account_ID,Accounts_Array);
						break;
					}
					else if(Admin_Choice_inside == 2) //change account status 
					{
						SET_Bank_Account_Status(Temp_Bank_Account_ID,Accounts_Array);
						break;
					}
					else if(Admin_Choice_inside == 3) //get cash
					{
						u64 Existing_Amount_of_money;
						Existing_Amount_of_money = Get_Cash(Temp_Bank_Account_ID,Accounts_Array);
						printf("The exisiting amount of money of bank account with ID %d is %d\n",Temp_Bank_Account_ID,Existing_Amount_of_money);
						printf("Please enter the amount of money you want to get from the account with ID %d here : ",Temp_Bank_Account_ID);
						scanf("%d",&Amount_To_Get);
						for(int i=0;i<100;i++)
						{
							if(Accounts_Array[i].Bank_Account_ID == Temp_Bank_Account_ID)
							{
								u64 Old_Balance = Existing_Amount_of_money;
								if(Old_Balance >= Amount_To_Get)
								{
									Accounts_Array[i].Balance =(Accounts_Array[i].Balance) - (Amount_To_Get);
									u64 New_Balance;
									New_Balance = Accounts_Array[i].Balance;
									printf("The New balance of bank Account with ID %d is %d\n",Temp_Bank_Account_ID,Accounts_Array[i].Balance);
									printf("\n");
								}
								else
								{
									Accounts_Array[i].Balance = Old_Balance ;
									printf("The requested amount is more than the available one\n");
									printf("\n");
								}
							}
						}
						break;
					}
					else if(Admin_Choice_inside == 4) //deposit in account
					{
						Deposit_Cash(Temp_Bank_Account_ID,Accounts_Array);
						break;
					}
					else if(Admin_Choice_inside == 5) //return to admin main page
					{
						break;
					}
				}
				
			}
			
			else if (Admin_Choice == 3) //to retrun to home page 
			{
				printf("\n");
				break;
			}
		}
	}
	
	else if (Admin_Mode ==0) //client actions 
	{
		while(1)
		{
			u8 Client_Choice;
			printf("--> For Making a transaction press 1\n");
			printf("--> For Changing the account password press 2\n");
			printf("--> For getting cash press 3\n");
			printf("--> For Depositing in an account press 4\n");
			printf("--> For returning to the Admin home page press 5\n");
			printf("--> Enter the number corresponding to your choice here : ");
			scanf("%d",&Client_Choice);
			printf("\n");
			
			if(Client_Choice == 1) //make a transaction
			{
				Make_A_Transaction_Client(GLOBAL_Bank_ID,Accounts_Array);
				for (int i=0;i<100;i++)
				{
					if(Accounts_Array[i].Bank_Account_ID ==GLOBAL_Bank_ID)
					{
						Accounts_Array[i].Balance = Accounts_Array[i].Balance - Amount_To_Be_Sent;
						printf("The New balance of bank account with ID %d is %d\n",GLOBAL_Bank_ID,Accounts_Array[i].Balance);
						printf("\n");
					}
				}
				break;
			}
			else if(Client_Choice == 2)
			{
				Change_Account_Password(GLOBAL_Bank_ID,Accounts_Array);
				break;
			}
			else if(Client_Choice == 3)
			{
				u64 Existing_Amount_of_money;
				Existing_Amount_of_money = Get_Cash_Client(GLOBAL_Bank_ID,Accounts_Array);
				printf("The exisiting amount of money of bank account with ID %d is %d\n",GLOBAL_Bank_ID,Existing_Amount_of_money);
				printf("Please enter the amount of money you want to get from the account with ID %d here : ",GLOBAL_Bank_ID);
				scanf("%d",&Amount_To_Get);
				for(int i=0;i<100;i++)
				{
					if(Accounts_Array[i].Bank_Account_ID == GLOBAL_Bank_ID)
					{
						u64 Old_Balance = Existing_Amount_of_money;
						if(Old_Balance >= Amount_To_Get)
						{
							Accounts_Array[i].Balance =(Accounts_Array[i].Balance) - (Amount_To_Get);
							u64 New_Balance;
							New_Balance = Accounts_Array[i].Balance;
							printf("The New balance of bank Account with ID %d is %d\n",GLOBAL_Bank_ID,Accounts_Array[i].Balance);
							printf("\n");
						}
						else
						{
							Accounts_Array[i].Balance = Old_Balance ;
							printf("The requested amount is more than the available one\n");
							printf("\n");
						}
					}
				}
				break;
			}
			else if( Client_Choice== 4)
			{
				Deposit_Cash_Client(GLOBAL_Bank_ID,Accounts_Array);
				break;
			}
			
			else if(Client_Choice == 5)
			{
				break;
			}				
		}
	}
	
}
	return 0;
}