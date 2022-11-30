#ifndef ADMIN_FUNCTIONS
#define ADMIN_FUNCTIONS 

#include "STD_Types.h"
//-----------------------------------------------
//struct to include the data of the bank account
typedef struct struct_1{
	
	u8 Full_Name[100];           //character string to read the full name
	u8 Full_Address[100];        //character string to read the full address
	u8 National_ID[14];          //18,446,744,073,709,551,616 is the max to be stored here but it couldn't accept the national ID so i made it a string
	u16 Age;					 //to read the age 
	u32 Bank_Account_ID;		 //4,294,967,296 is the max to be stored here
	u8 Guardian[100];			 //character string to read the anme of the guardian
	u8 Guardian_National_ID[14];    //4,294,967,296is the max to be stored here
	u8 Account_Status[12];       //restricted is the max to be written here
	u64 Balance;                 //18,446,744,073,709,551,616 is the max to be stored here
	u32 Password;                //20 random characters to be the password
	//u32 Counter_For_BanK_ID;     //this counter will be used to generate unique bank Id for each customer
	
}Bank_Account;
//-----------------Admin functions---------------
void Create_IMT_Bank_Account(Bank_Account *Pointer_To_Bank_Account); //function to creat a bank account
u8 Admin_Check(u8 *Pointer_To_Name_To_Search_For,u32 Password_To_Check_for,u16 Size_Of_Name); //function to check for admin nmae and password
Bank_Account Set_user_Data(Bank_Account *ptr_to_user_Data_Array_Struct,Bank_Account *User_Data_struct, u16 Client_Number);//function to set the data of each client in it's loc
u8 Bank_Account_ID_Check (u32 Bank_Account_ID_To_Check_For,Bank_Account *ptr_to_user_Data_Array_Struct); //checking if the entered bank account id is valid or not
u8 Make_A_Transaction(u32 Sending_Bank_Account_ID,Bank_Account *ptr_to_user_Data_Array_Struct); //function to allow for makking a transaction
u8 SET_Bank_Account_Status(u32 Bank_Account_ID_To_Change_Status,Bank_Account *ptr_to_user_Data_Array_Struct);// function to change bank account status
u64 Get_Cash(u32 Bank_Account_Idd,Bank_Account *ptr_to_user_Data_Array_Struct);//function to allow for getting cash from the account
u8 Deposit_Cash(u32 Bank_Account_Idd,Bank_Account *ptr_to_user_Data_Array_Struct);//function to allow for depositing cash in an account
//-----------------------------------------------



#endif

