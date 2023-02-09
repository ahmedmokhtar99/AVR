#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"PORT_interface.h"
#include"DIO_interface.h"
#include"GIE_interface.h"
#include"TIMERS_interface.h"
void LED(void);

void main(void){
	PORT_voidInit();
	TIMER0_voidinit();
	TIMER0_setcallback(&LED);
	GIE_voidenable();

	while(1){

	}
}
void LED(void){
	static u16 Local_u16counter=0;
	static u8 Local_u8ledstate=0;

	Local_u16counter++;
	if(Local_u16counter==4000){
		TOOGLE_BIT(Local_u8ledstate,0);
		DIO_U8SetPinValue(DIO_u8PORTD, DIO_u8PIN0, Local_u8ledstate);
		Local_u16counter=0;

	}
}
