#include"STD_TYPES.h"
#include"DIO_interface.h"


	u8 Local_u8Input_Value=1;



	 while (1){
		DIO_U8GetPinValue(DIO_u8PORTB, DIO_u8PIN0, &Local_u8Input_Value);
		if(Local_u8Input_Value==0){
			DIO_U8SetPinValue(DIO_u8PORTD, DIO_u8PIN1, DIO_u8PIN_HIGH);
		}
		else{
			DIO_U8SetPinValue(DIO_u8PORTD, DIO_u8PIN1, DIO_u8PIN_LOW);

		}


	 }
 }
