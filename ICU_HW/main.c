#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"PORT_interface.h"
#include"TIMERS_interface.h"
#include"GIE_interface.h"

#include "CLCD_interfaces.h"

static u16 periodticks=0;
static u16 onticks=0;
void ICU_HW (void);

void main(void){
	PORT_voidInit();
	ICU_voidinit();
	ICU_u8pvsetcallback(&ICU_HW);

	TIMER1_voidinit();
	TIMER0_voidinit();

	CLCD_voidInit();
	GIE_voidenable();

	while(1){
		while((periodticks==0)&&(onticks==0));
		CLCD_voidGo_To_X_Y(0,0);
		CLCD_voidSend_String("PERIOD TIKCS=");
		CLCD_voidsendnumber(periodticks);
		CLCD_voidGo_To_X_Y(1, 0);
		CLCD_voidSend_String("ON TICKS IS=");
		CLCD_voidsendnumber(onticks);



	}
}
void ICU_HW(void){
	static u16 Reading1,Reading2,Reading3;
	static u8 counter=0;
	counter++;
	if(counter==1){
		Reading1=ICU_u16readinputcapture();
	}
	else if(counter==2){
		Reading2=ICU_u16readinputcapture();
		periodticks=Reading2-Reading1;
		ICU_u8settriggeredge(FALLING_EDGE);
	}
	else if(counter==3){
		Reading3=ICU_u16readinputcapture();
		onticks=Reading3-Reading2;
		ICU_voiddisableinterrupt();
	}


}
