/************************************************************************************/
/************************************************************************************/
/**********************      AUTHOR: AHMED MOKHTAR       ****************************/
/**********************      LAYER: HAL                 ****************************/
/**********************      SWC:SWITCHES                     ****************************/
/**********************      VERSION: 1.00               ****************************/
/************************************************************************************/
/************************************************************************************/
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO_interface.h"
#include"PORT_interface.h"
#include"SWITCHES_confg.h"
#include"SWITCHES_interface.h"
#include"SWITCHES_private.h"
#include<util/delay.h>



void SWITCHES_voidInit(void){
	DIO_U8SetPinValue(SWITCH_Port,SWITCH_Pin,SWITCH_ON);
	_delay_ms(10000);
	DIO_U8SetPinValue(SWITCH_Port,SWITCH_Pin,SWITCH_OFF);
	_delay_ms(10000);


}
