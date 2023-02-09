/************************************************************************************/
/************************************************************************************/
/**********************      AUTHOR: AHMED MOKHTAR       ****************************/
/**********************      LAYER: MCAL                 ****************************/
/**********************      SWC:DIO                     ****************************/
/**********************      VERSION: 1.00               ****************************/
/************************************************************************************/
/************************************************************************************/
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"SSD_interfaces.h"
#include"SSD_config.h"
#include"SSD_private.h"
#include"SSD_register.h"
#include"DIO_interface.h"
#include"DIO_register.h"


u8 SSD_u8Turn_On(SSD_Struct* SSD_Inf,u8 SSD_u8Number){
	u8 SSD_u8Ssd_Array[10]={0b0111111,0b0000110,0b1011011,0b1001111,0b1100110,0b1101101,0b1111101,0b0000111,0b1111111,0b1101111};
	u8 Locla_u8Eror_state=0;
	if(SSD_Inf->SSD_u8Enb_Pin<=DIO_u8PIN7){
		if(SSD_Inf->SSD_u8Type==SSD_u8Com_Anode){
			DIO_U8SetPortDirection(SSD_Inf->SSD_u8Port, DIO_u8PORT_OUTPUT);
            DIO_U8SetPinDirection(SSD_Inf->SSD_u8Enb_Port, SSD_Inf->SSD_u8Enb_Pin,DIO_u8PIN_OUTPUT);
			DIO_U8SetPortValue(SSD_Inf->SSD_u8Port,!SSD_u8Ssd_Array[SSD_u8Number]);
			DIO_U8SetPinValue(SSD_Inf->SSD_u8Enb_Port,SSD_Inf->SSD_u8Enb_Pin, DIO_u8PIN_HIGH);
		}
		else if(SSD_Inf->SSD_u8Type==SSD_u8Com_Cathode){
			DIO_U8SetPortDirection(SSD_Inf->SSD_u8Port, DIO_u8PORT_OUTPUT);
            DIO_U8SetPinDirection(SSD_Inf->SSD_u8Enb_Port, SSD_Inf->SSD_u8Enb_Pin,DIO_u8PIN_OUTPUT);
			DIO_U8SetPortValue(SSD_Inf->SSD_u8Port,SSD_u8Ssd_Array[SSD_u8Number]);
			DIO_U8SetPinValue(SSD_Inf->SSD_u8Enb_Port,SSD_Inf->SSD_u8Enb_Pin, DIO_u8PIN_LOW);
		}
		else {
			Locla_u8Eror_state=1;
		}

	}
	else{
		Locla_u8Eror_state=1;
	}
	return Locla_u8Eror_state;
}
u8 SSD_u8Turn_Off(SSD_Struct* SSD_Inf){
	u8 Locla_u8Eror_state=0;
	if(SSD_Inf->SSD_u8Enb_Pin<=DIO_u8PIN7){
			if(SSD_Inf->SSD_u8Type==SSD_u8Com_Anode){
	            DIO_U8SetPinDirection(SSD_Inf->SSD_u8Enb_Port, SSD_Inf->SSD_u8Enb_Pin,DIO_u8PIN_OUTPUT);
				DIO_U8SetPinValue(SSD_Inf->SSD_u8Enb_Port,SSD_Inf->SSD_u8Enb_Pin, DIO_u8PIN_LOW);
			}
			else if(SSD_Inf->SSD_u8Type==SSD_u8Com_Cathode){
	            DIO_U8SetPinDirection(SSD_Inf->SSD_u8Enb_Port, SSD_Inf->SSD_u8Enb_Pin,DIO_u8PIN_OUTPUT);
				DIO_U8SetPinValue(SSD_Inf->SSD_u8Enb_Port,SSD_Inf->SSD_u8Enb_Pin, DIO_u8PIN_HIGH);
			}
			else {
				Locla_u8Eror_state=1;
			}

		}
		else{
			Locla_u8Eror_state=1;
		}
		return Locla_u8Eror_state;

}
