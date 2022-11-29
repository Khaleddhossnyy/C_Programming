#include<stdio.h>
#include "Client.h"
#include <stdio.h>
#include <stdlib.h>
#include "STD_Types.h"
#include <string.h>

u64 Amount_To_Be_Sent;
//------------------------------------------------------------
u8 BanK_Account_Check(u32 Bank_Acountt_ID, u32 Bank_Accountt_Password,Bank_Account *ptr_to_user_Data_Array_Struct)
{
	for(int i=0;i<100;i++)
	{
		if(ptr_to_user_Data_Array_Struct[i].Bank_Account_ID == Bank_Acountt_ID)
		{
			if(ptr_to_user_Data_Array_Struct[i].Password == Bank_Accountt_Password)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			return 2;
		}
	}
}
//------------------------------------------------------------
u8 Make_A_Transaction_Client(u32 Sending_Bank_Account_ID,Bank_Account *ptr_to_user_Data_Array_Struct)
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
//------------------------------------------------------------
u8 Change_Account_Password(u32 Bank_Account_Idd,Bank_Account *ptr_to_user_Data_Array_Struct)
{
	u32 OLD_Password;
	u32 NEW_Password;
	printf("Please enter your old Password here : ");
	scanf("%d",&OLD_Password);
	for(int i=0;i<100;i++)
	{
		if(ptr_to_user_Data_Array_Struct[i].Bank_Account_ID == Bank_Account_Idd)
		{
			if(ptr_to_user_Data_Array_Struct[i].Password == OLD_Password)
			{
				printf("Please enter the new Password here : ");
				scanf("%d",&NEW_Password);
				ptr_to_user_Data_Array_Struct[i].Password = NEW_Password;
				printf("The new password of account with ID %d is %d\n",Bank_Account_Idd,NEW_Password);
				printf("\n");
			}
			else
			{
				printf("!!!!! Wrong Password\n");
				printf("\n");
			}
		}
	}
}
//------------------------------------------------------------
u64 Get_Cash_Client(u32 Bank_Account_Idd,Bank_Account *ptr_to_user_Data_Array_Struct)
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
//-----------------------------------------------------------
u8 Deposit_Cash_Client(u32 Bank_Account_Idd,Bank_Account *ptr_to_user_Data_Array_Struct)
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
//-----------------------------------------------------------