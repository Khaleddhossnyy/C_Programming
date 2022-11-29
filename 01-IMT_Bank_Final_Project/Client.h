#ifndef CLIENT_FUNCTIONS
#define CLIENT_FUNCTIONS 

//-------------------------
#include "STD_Types.h"
#include "Admin.h"
//-------------------------
u8 BanK_Account_Check(u32 Bank_Acountt_ID, u32 Bank_Accountt_Password,Bank_Account *ptr_to_user_Data_Array_Struct);
u8 Make_A_Transaction_Client(u32 Sending_Bank_Account_ID,Bank_Account *ptr_to_user_Data_Array_Struct);
u8 Change_Account_Password(u32 Bank_Account_Idd,Bank_Account *ptr_to_user_Data_Array_Struct);
u64 Get_Cash_Client(u32 Bank_Account_Idd,Bank_Account *ptr_to_user_Data_Array_Struct);//function to allow for getting cash from the account
u8 Deposit_Cash_Client(u32 Bank_Account_Idd,Bank_Account *ptr_to_user_Data_Array_Struct);
#endif