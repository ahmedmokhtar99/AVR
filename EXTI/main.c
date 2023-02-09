#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"EXTI_interface.h"
#include"DIO_interface.h"
#include"PORT_interface.h"
#include"GIE_interface.h"

void main(void){
	PORT_voidInit();
	EXTI_voidint0init();
	GIE_voidenable();
	while(1){

	}
}
 void INT0_ISR(void)
{
	u8 LOCAL_u8Pinvalue;
	DIO_U8GetPinValue(DIO_u8PORTD, DIO_u8PIN0, &LOCAL_u8Pinvalue);
	if(LOCAL_u8Pinvalue==0){
	DIO_U8SetPinValue(DIO_u8PORTD, DIO_u8PIN0, DIO_u8PIN_HIGH);
}
	else{
		DIO_U8SetPinValue(DIO_u8PORTD, DIO_u8PIN0, DIO_u8PIN_LOW);
	}
}

