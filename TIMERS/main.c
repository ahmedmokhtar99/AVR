#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"PORT_interface.h"
#include"DIO_interface.h"
#include"GIE_interface.h"
#include"TIMERS_interface.h"
#include<util/delay.h>
void PWM(void);

void main(void){
	u16 Local_u8counter;
	PORT_voidInit();
	TIMER0_voidinit();
	MAPING OBJECT1={1000,5000,0,180,0,180};
	s32 inputvalue=MAPING_s32mapingvalue(&OBJECT1,REVERSED);

	/*TIMER0_setcallback(&PWM);
	GIE_voidenable();
	*/

	while(1){
		TIMER0_voidsetcompmatchvalue(1000);
		_delay_ms(1000);
		TIMER0_voidsetcompmatchvalue(5000);
		_delay_ms(1000);








     }

    }



void PWM(void){
 /*static u8 Local_u8counter=0;
 Local_u8counter++;
 if(Local_u8counter==5){
	 DIO_U8SetPinValue(DIO_u8PORTD, DIO_u8PIN0, DIO_u8PIN_LOW);
 }
 else if(Local_u8counter==20){
	 DIO_U8SetPinValue(DIO_u8PORTD, DIO_u8PIN0, DIO_u8PIN_HIGH);
 	 DIO_U8SetPinValue(DIO_u8PORTD, DIO_u8PIN1, DIO_u8PIN_HIGH);
 	 DIO_U8SetPinValue(DIO_u8PORTD, DIO_u8PIN2, DIO_u8PIN_HIGH);
	 Local_u8counter=0;
 }
 else if(Local_u8counter==10){
 	 DIO_U8SetPinValue(DIO_u8PORTD, DIO_u8PIN1, DIO_u8PIN_LOW);
  }

  else if(Local_u8counter==15){
 	 DIO_U8SetPinValue(DIO_u8PORTD, DIO_u8PIN2, DIO_u8PIN_LOW);
  }
*/
	}
