/************************************************************************************/
/************************************************************************************/
/**********************      AUTHOR: AHMED MOKHTAR       ****************************/
/**********************      LAYER: HAL                  ****************************/
/**********************      SWC:KPD                     ****************************/
/**********************      VERSION: 1.00               ****************************/
/************************************************************************************/
/************************************************************************************/
#include"STD_TYPES.h"
#include"DIO_interface.h"
#include"KPD_config.h"
#include"KPD_interface.h"
#include"KPD_private.h"



u8 KPD_u8GetPresedKey(){
	u8 Local_u8PreasedKey=KPD_NO_PREASED_KEY;
	u8 Local_u8Coulmn_Index,Local_u8Row_Index,Local_Pin_State;
	static u8 Local_u8KPDArr[Max_Row_Num][Max_Coulmn_Num]=kPD_ARR_VALL;
	static u8 Lcal_u8Coulmn_Arr[Max_Coulmn_Num]={KPD_COULMN0_PIN,KPD_COULMN1_PIN,KPD_COULMN2_PIN};
	static u8 Local_u8Row_Arr[Max_Row_Num]={KPD_ROW0_PIN,KPD_ROW1_PIN,KPD_ROW2_PIN,KPD_ROW3_PIN};
	for(Local_u8Coulmn_Index=0;Local_u8Coulmn_Index<Max_Coulmn_Num;Local_u8Coulmn_Index++){
		DIO_U8SetPinValue(KPD_PORT,Lcal_u8Coulmn_Arr[Local_u8Coulmn_Index] , DIO_u8PIN_LOW);
		for(Local_u8Row_Index=0;Local_u8Row_Index<Max_Row_Num;Local_u8Row_Index++){
			DIO_U8GetPinValue(KPD_PORT,Local_u8Row_Arr[Local_u8Row_Index] , &Local_Pin_State);
			if(Local_Pin_State==DIO_u8PIN_LOW){
				Local_u8PreasedKey=Local_u8KPDArr[Local_u8Row_Index][Local_u8Coulmn_Index];
				while(Local_Pin_State==DIO_u8PIN_LOW){
					DIO_U8GetPinValue(KPD_PORT,Local_u8Row_Arr[Local_u8Row_Index] , &Local_Pin_State);

				}
				return Local_u8PreasedKey;


			}


		}
		DIO_U8SetPinValue(KPD_PORT,Lcal_u8Coulmn_Arr[Local_u8Coulmn_Index] , DIO_u8PIN_HIGH);

	}
	return Local_u8PreasedKey;


}
