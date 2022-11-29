#include <stdio.h>
#include <stdlib.h>
#include "Admin.h"
#include "STD_Types.h"
#include <string.h>

//----------------------------------------------------------------
u8 Admin_Namee[6]="Khaled";
u32 Admin_Passwordd =1581999;
//--------------Implmenting admin functions-----------------------
void Create_IMT_Bank_Account(Bank_Account *Pointer_To_Bank_Account)
{
	printf("Please enter the full name of the new bank member here : ");
	scanf(" %[^\n]",&Pointer_To_Bank_Account->Full_Name);
	printf("\n");
	
	printf("Please enter the full address of the new bank member here : ");
	scanf(" %[^\n]",&Pointer_To_Bank_Account->Full_Address);
	printf("\n");
	
	printf("Please enter the 14 digits of the Natinal ID of the new bank member here : ");
	scanf("%s",&Pointer_To_Bank_Account->National_ID);
	//printf("%d",strlen(Pointer_To_Bank_Account->National_ID));
	while( strlen(Pointer_To_Bank_Account->National_ID) != 14)
	{
		//printf("%d",strlen(Pointer_To_Bank_Account->National_ID));
		printf("!!!! Error, please enter the correct 14 digits of the National ID : ");
		scanf("%s",&Pointer_To_Bank_Account->National_ID);
	}
	printf("\n");
	
	printf("Please enter the Age of the new bank member here : ");
	scanf(" %d",&Pointer_To_Bank_Account->Age);
	printf("\n");
	
	
	Pointer_To_Bank_Account->Bank_Account_ID = 1000000000;
	
	if(Pointer_To_Bank_Account->Age < 21)
	{
		printf("Please enter the Guardian name of the new bank member here : ");
		scanf(" %[^\n]",&Pointer_To_Bank_Account->Guardian); 
		printf("\n");
		
		printf("Please enter the Guardian national ID of the new bank member here : ");
		scanf("%s",&Pointer_To_Bank_Account->Guardian_National_ID);
		printf("\n");
	}
	else if (Pointer_To_Bank_Account->Age >= 21)
	{
		strcpy(Pointer_To_Bank_Account->Guardian,"The member is over or 21 years old so no need for guardian");
		strcpy(Pointer_To_Bank_Account->Guardian_National_ID,"NULL");
	}
	
	strcpy(Pointer_To_Bank_Account->Account_Status,"Active"); //initialize the user account with active 
	
	printf("Please enter the balance of the new bank member here : ");
	scanf("%d",&Pointer_To_Bank_Account->Balance);
	//Pointer_To_Bank_Account->Balance = 0; //initialize the user account balance with zero
	printf("\n");
	
	Pointer_To_Bank_Account->Password = rand() % (1000000 + 1 - 1000) + 1000;  //generate a random number from 1000 to 1000000
}
//---------------------------------------------------------------------------------------
u8 Admin_Check(u8 *Pointer_To_Name_To_Search_For,u32 Password_To_Check_for)
{
    //printf("%d\n",Password_To_Check_for);
	for (int i=0;i<strlen(Admin_Namee);i++) //for loop to check for the admin Name
	{
		while(Pointer_To_Name_To_Search_For[i] != Admin_Namee[i])
		{
			return 0;
		}			
	}
	//printf("%d\n",Password_To_Check_for);
	if( Password_To_Check_for == Admin_Passwordd) //both the username and the password of the admin  are correct
	{
		//printf("Here\n");
		return 1;
	}

	else if(Password_To_Check_for != Admin_Passwordd)
	{
		return 0;
	}
}
//---------------------------------------------------------------------------------------
Bank_Account Set_user_Data(Bank_Account *ptr_to_user_Data_Array_Struct,Bank_Account *User_Data_struct,u16 Client_Number)
{
	strcpy(ptr_to_user_Data_Array_Struct[Client_Number].Full_Name,User_Data_struct->Full_Name);
	strcpy(ptr_to_user_Data_Array_Struct[Client_Number].Full_Address,User_Data_struct->Full_Address);
	strcpy(ptr_to_user_Data_Array_Struct[Client_Number].National_ID,User_Data_struct->National_ID);
	ptr_to_user_Data_Array_Struct[Client_Number].Age = User_Data_struct ->Age;
	ptr_to_user_Data_Array_Struct[Client_Number].Bank_Account_ID = User_Data_struct ->Bank_Account_ID +Client_Number;
	strcpy(ptr_to_user_Data_Array_Struct[Client_Number].Guardian,User_Data_struct->Guardian);
	strcpy(ptr_to_user_Data_Array_Struct[Client_Number].Guardian_National_ID,User_Data_struct->Guardian_National_ID);
	strcpy(ptr_to_user_Data_Array_Struct[Client_Number].Account_Status,User_Data_struct->Account_Status);
	ptr_to_user_Data_Array_Struct[Client_Number].Balance= User_Data_struct ->Balance;
	ptr_to_user_Data_Array_Struct[Client_Number].Password= User_Data_struct ->Password;
	
	return (ptr_to_user_Data_Array_Struct[Client_Number]);
}
//---------------------------------------------------------------------------------------
u8 Bank_Account_ID_Check(u32 Bank_Account_ID_To_Check_For,Bank_Account *ptr_to_user_Data_Array_Struct)
{
	for(u16 i=0;i<100;i++)
	{
		if (ptr_to_user_Data_Array_Struct[i].Bank_Account_ID == Bank_Account_ID_To_Check_For)
		{
			return 1; //if this bank account ID is found return 1
			break;
		}
	}
	return 0; // if it is not found return 0
}
//---------------------------------------------------------------------------------------
u8 Make_A_Transaction(u32 Sending_Bank_Account_ID,Bank_Account *ptr_to_user_Data_Array_Struct)
{
	u32 Bank_Account_Id_To_Send_To;
	u8 Bank_Account_Id_To_Send_To_IsActive;
	u8 Sending_Bank_Account_ID_IsActive;
	u8 Amount_To_Be_Sent_Checked;
	
	
	printf("Enter the bank account ID you want to make a transaction to here : ");
	scanf("%d",&Bank_Account_Id_To_Send_To);
	
	for (int i=0;i<100;i++) //to check for the status of the account i am sending money to it and the account sedning this money
	{
		if(ptr_to_user_Data_Array_Struct[i].Bank_Account_ID == Bank_Account_Id_To_Send_To)
		{
			//printf("here 1");
			if( strcmp(ptr_to_user_Data_Array_Struct[i].Account_Status,"Active")==0)
			{
				Bank_Account_Id_To_Send_To_IsActive=1; //the account we are sending to it is active
			}
			else
			{
				printf("The account with ID %d is not active",Bank_Account_Id_To_Send_To);
				return 2; //the account we are sending to it is not active
			}
		}
		
		if(ptr_to_user_Data_Array_Struct[i].Bank_Account_ID == Sending_Bank_Account_ID)
		{
			if( strcmp(ptr_to_user_Data_Array_Struct[i].Account_Status,"Active")==0)
			{
				Sending_Bank_Account_ID_IsActive=1; //the account sending money is active				
			}
			else
			{
				printf("The account with ID %d is not active",Sending_Bank_Account_ID);
				return 3; //the account sending money isn't active
			}
		}
	}
	
	if ( (Sending_Bank_Account_ID_IsActive==1) && (Bank_Account_Id_To_Send_To_IsActive==1) ) //both are active
	{
		u64 Amount_To_Be_Sent;
		u64 Validator;
		printf("Enter the amount of money you want to send to this account here : ");
		scanf("%d",&Amount_To_Be_Sent);
		for(int i=0;i<100;i++)
		{
			if(ptr_to_user_Data_Array_Struct[i].Bank_Account_ID == Sending_Bank_Account_ID)
			{
				//printf("here\n");
				//printf("%d\n",Amount_To_Be_Sent);
				Validator =ptr_to_user_Data_Array_Struct[i].Balance;
				//printf("%d\n",Validator);
				if( (Amount_To_Be_Sent <= Validator) ) //check that the amount we want to send is lower than our balance 
				{
					//printf("here from inside\n");
					Amount_To_Be_Sent_Checked=1;
					break;
				}
			}
		}
		//printf("%d\n",Amount_To_Be_Sent_Checked);
		if(Amount_To_Be_Sent_Checked == 1)
		{
			for(int i=0;i<100;i++)
			{
				if(ptr_to_user_Data_Array_Struct[i].Bank_Account_ID == Bank_Account_Id_To_Send_To)
				{
					ptr_to_user_Data_Array_Struct[i].Balance = ptr_to_user_Data_Array_Struct[i].Balance + Amount_To_Be_Sent;
					printf("The new balance of the account with Bank_Account_ID %d is %d\n",ptr_to_user_Data_Array_Struct[i].Bank_Account_ID,ptr_to_user_Data_Array_Struct[i].Balance );
					printf("\n");
					return 1; //amount trasnacted successfully
				}
			}
			
		}
	}
return 0; //if the amount isn't transacted
}
//---------------------------------------------------------------------------------------
u8 SET_Bank_Account_Status(u32 Bank_Account_ID_To_Change_Status,Bank_Account *ptr_to_user_Data_Array_Struct)
{
	u8 Bank_Id_Check;
	Bank_Id_Check=Bank_Account_ID_Check(Bank_Account_ID_To_Change_Status,ptr_to_user_Data_Array_Struct);
	u8 Account_Statuss[12];
	if(Bank_Id_Check == 1) //account found
	{
		printf("Account status could be : Active or Restricted or Closed \n");
		printf("Enter your choice here : ");
		scanf("%s",&Account_Statuss);
		for(int i=0;i<100;i++)
		{
			if (ptr_to_user_Data_Array_Struct[i].Bank_Account_ID == Bank_Account_ID_To_Change_Status)
			{
				printf("The account status of Bank Account with ID %d is %s\n",Bank_Account_ID_To_Change_Status,ptr_to_user_Data_Array_Struct[i].Account_Status);
				strcpy(ptr_to_user_Data_Array_Struct[i].Account_Status,Account_Statuss);
				printf("The account status of Bank Account with Id %d is changed to %s \n",Bank_Account_ID_To_Change_Status,ptr_to_user_Data_Array_Struct[i].Account_Status);
				printf("\n");
				return 1;
			}
		}
	}
	else
	{
		printf("!!!!!!No bank Account with this ID exists\n");
		printf("\n");
		return 0;
	}
}
//---------------------------------------------------------------------------------------
u64 Get_Cash(u32 Bank_Account_Idd,Bank_Account *ptr_to_user_Data_Array_Struct)
{
	u8 Bank_Id_Check;
	Bank_Id_Check=Bank_Account_ID_Check(Bank_Account_Idd,ptr_to_user_Data_Array_Struct);
	if(Bank_Id_Check == 1) //account found
	{
		u64 Amount_Existing;
		for(int i=0;i<100;i++)
		{
			if (ptr_to_user_Data_Array_Struct[i].Bank_Account_ID == Bank_Account_Idd)
			{
				u64 *Ptr_To_Amount_Existing = &Amount_Existing;
				*Ptr_To_Amount_Existing = ptr_to_user_Data_Array_Struct[i].Balance;
				//return Amount_Existing;
				//printf("%d\n",*Ptr_To_Amount_Existing);
				//printf("%d\n",*Ptr_To_Amount_to_Get);
				//u64 Existing = *Ptr_To_Amount_Existing;
				return *Ptr_To_Amount_Existing;
			}
		}
	}
	else
	{
		printf("!!!!!!No bank Account with this ID exists\n");
		printf("\n");
		return 0;
	}
}
//---------------------------------------------------------------------------------------
u8 Deposit_Cash(u32 Bank_Account_Idd,Bank_Account *ptr_to_user_Data_Array_Struct)
{
	u8 Bank_Id_Check;
	Bank_Id_Check=Bank_Account_ID_Check(Bank_Account_Idd,ptr_to_user_Data_Array_Struct);
	if(Bank_Id_Check == 1) //account found
	{
		u64 Amount_To_Deposit;
		printf("Please enter the amount of money you want to Deposit into account with id %d here : ",Bank_Account_Idd);
		scanf("%d",&Amount_To_Deposit);
		for(int i=0;i<100;i++)
		{
			if (ptr_to_user_Data_Array_Struct[i].Bank_Account_ID == Bank_Account_Idd)
			{
				ptr_to_user_Data_Array_Struct[i].Balance=ptr_to_user_Data_Array_Struct[i].Balance+Amount_To_Deposit;
				printf("The New balance of bank account with Id %d is %d \n",Bank_Account_Idd,ptr_to_user_Data_Array_Struct[i].Balance);
				printf("\n");
				return 1;
			}
		}
	}
	else
	{
		printf("!!!!!!No bank Account with this ID exists\n");
		printf("\n");
		return 0;
	}
}
//---------------------------------------------------------------------------------------