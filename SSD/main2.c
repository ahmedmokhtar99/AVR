#include"STD_TYPES.h"
#include"SSD_interfaces.h"
#include"DIO_interface.h"
#include<util/delay.h>
void main(void){
	SSD_Struct Local_u8SSD_Struct={SSD_u8Com_Cathode,DIO_u8PORTD,DIO_u8PORTB,DIO_u8PIN0};
	SSD_Struct Local_u8SSD_Struct1={SSD_u8Com_Cathode,DIO_u8PORTD,DIO_u8PORTB,DIO_u8PIN1};

	while(1){
		SSD_u8Turn_On(&Local_u8SSD_Struct, SSD_u8Num_Seven);
		_delay_ms(20);
		SSD_u8Turn_Off(&Local_u8SSD_Struct);
		SSD_u8Turn_On(&Local_u8SSD_Struct1, SSD_u8Num_Nine);
		_delay_ms(20);
		SSD_u8Turn_Off(&Local_u8SSD_Struct1);

}
}
