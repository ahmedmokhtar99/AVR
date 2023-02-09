#include"STD_TYPES.h"
#include"CLCD_interfaces.h"
#include "DIO_interface.h"
#include"PORT_interface.h"
void main(void){
	/*Initialise LCD pins directions */
    PORT_voidInit();
	CLCD_voidInit();
	CLCD_voidSendData('a');
	CLCD_voidSendData('a');
	CLCD_voidSendData('a');
	CLCD_voidSendData('a');
	CLCD_voidSendData('a');
	CLCD_voidSendData('a');

	    while(1){

	}
	}
