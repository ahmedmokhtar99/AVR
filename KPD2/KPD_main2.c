#include"STD_TYPES.h"
#include "DIO_interface.h"
#include"CLCD_interfaces.h"
#include"PORT_interface.h"
#include"KPD_interface.h"
void main(void){
	u8 Local_u8Preased_Value;
    PORT_voidInit();
	CLCD_voidInit();
	u8 Local_u8reading=1;
	CLCD_voidSendData(Local_u8reading);

	    while(1){

	    	do{
	        Local_u8Preased_Value=KPD_u8GetPresedKey();}
	    	while(Local_u8Preased_Value==0xff);
	    	if(Local_u8Preased_Value==10){
	    		CLCD_voidClear_Display();
	    		continue;
	    	}

	        CLCD_voidSendData(Local_u8Preased_Value+'0');




	}
	}
