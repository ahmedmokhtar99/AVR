#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"PORT_interface.h"
#include"DIO_interface.h"
#include"ADC_interface.h"
#include "CLCD_interfaces.h"
#include "GIE_interface.h"
#include <util/delay.h>
	u8 APP_u8ADCreading;
	void ADCnotification(void);
void main(void){
	PORT_voidInit();
	CLCD_voidInit();
    ADC_voidintit();
    GIE_voidenable();

	while(1){

      ADC_u8startconversionasynch(0, APP_u8ADCreading, &ADCnotification);
	}
}
void ADCnotification(void){
	DIO_U8SetPortValue(DIO_u8PORTD,APP_u8ADCreading);
}
