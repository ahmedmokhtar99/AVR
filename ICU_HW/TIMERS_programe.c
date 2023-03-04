/************************************************************************************/
/************************************************************************************/
/**********************      AUTHOR: AHMED MOKHTAR       ****************************/
/**********************      LAYER: MCAL                 ****************************/
/**********************      SWC:TIMERS                  ****************************/
/**********************      VERSION: 1.00               ****************************/
/************************************************************************************/
/************************************************************************************/
#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"TIMERS_config.h"
#include "TIMERS_interface.h"
#include "TIMERS_private.h"
#include "TIMERS_register.h"


static void(*TIMER_pvcallbackfunc)(void)=NULL;
static void(*ICU_pvcallbackfunc)(void)=NULL;


void TIMER0_voidinit(void){


	/*choose fast PWM mode with input capture
	CLEAR_BIT(TCCR1A,TCCR1A_WGM10);
	SET_BIT(TCCR1A,TCCR1A_WGM11);
	SET_BIT(TCCR1B,TCCR1B_WGM12);
	SET_BIT(TCCR1B,TCCR1B_WGM13);*/

	/* choose fast PWM at timer 0*/
	SET_BIT(TCCR0A,TCCR0A_WGM00);
	SET_BIT(TCCR0A,TCCR0A_WGM01);



	/*enable compare match interrupt
    SET_BIT(TIMSK0,TIMSK0_OCIE0A);*/

	/*set compare match output value to 64 for duty cycle 25%*/
	OCOR0A=64;

	/*clear on compare match set on top*/
	CLEAR_BIT(TCCR0A,TCCR0A_COM0A0);
	SET_BIT(TCCR0A,TCCR0A_COM0A1);

	/*choose prescaler division by 8*/
	CLEAR_BIT(TCCR0B,TCCR0B_CS00);
	SET_BIT(TCCR0B,TCCR0B_CS01);
	CLEAR_BIT(TCCR0B,TCCR0B_CS02);
	/*set the value of input capture value*/


}
void TIMER1_voidsettimer1value(u16 copy_u8timer1value){
	TCNT1=copy_u8timer1value;

}
u16 TIMER1_u16readtimervalue(void){
	return TCNT1;
}
void TIMER1_voidinit(void){
	/* initialize at normal mode*,prescaler timer1 divided by 8	 */
	CLEAR_BIT(TCCR1A,TCCR1A_COM1A0);
	CLEAR_BIT(TCCR1A,TCCR1A_COM1A1);
	CLEAR_BIT(TCCR1B,TCCR1B_CS10);
	SET_BIT(TCCR1B,TCCR1B_CS11);
	CLEAR_BIT(TCCR1B,TCCR1B_CS12);
	OCOR1AL=20000;






}
u8 TIMER0_setcallback(void(*copy_pvcallbackfunc)(void)){
	u8 Local_errorstate=OK;
	if(copy_pvcallbackfunc==NULL){
		Local_errorstate=NULL_POINTER;
	}

	else{
		TIMER_pvcallbackfunc=copy_pvcallbackfunc;

	}

	return Local_errorstate;
}
void ICU_voidinit(void){

	/*set the trigger at rising edge */
	SET_BIT(TCCR1B,TCCR1B_ICES1);
	/*enable input capture interrupt*/
	SET_BIT(TIMSK1,TIMSK1_ICIE1);
}
u8 ICU_u8settriggeredge(u8 copy_u8edge){
	u8 Local_u8errorstate=OK;
	if(copy_u8edge==RISING_EDGE){
		SET_BIT(TCCR1B,TCCR1B_ICES1);
	}
	else if(copy_u8edge==FALLING_EDGE){
		CLEAR_BIT(TCCR1B,TCCR1B_ICES1);
	}
	else{
		Local_u8errorstate=NOK;
	}
	return Local_u8errorstate;

}
void ICU_voidenableinterrupt(void){
	SET_BIT(TIMSK1,TIMSK1_ICIE1);

}
void ICU_voiddisableinterrupt(void){
	CLEAR_BIT(TIMSK1,TIMSK1_ICIE1);
}
u16 ICU_u16readinputcapture(void){
	return ICR1L;

}
u8 ICU_u8pvsetcallback(void(*copy_pvcallbackfunc)(void)){
	u8 Local_u8stateerror=OK;
	if(copy_pvcallbackfunc==NULL){
		Local_u8stateerror=NULL_POINTER;
		return Local_u8stateerror;
	}
	else{
		ICU_pvcallbackfunc=copy_pvcallbackfunc ;
	}

}

void __vector_14 (void)__attribute__((signal));
void __vector_14 (void){
	if(TIMER_pvcallbackfunc!=NULL){
		TIMER_pvcallbackfunc();
	}
}
void __vector_10 (void)__attribute__((signal));
void __vector_10 (void){
	if(ICU_pvcallbackfunc!=NULL){
		ICU_pvcallbackfunc();
	}
}



void TIMER0_voidsetcompmatchvalue(u16 copy_u8vlaue){
	OCOR1AL=copy_u8vlaue;
}
s32 MAPING_s32mapingvalue(MAPING*copy_structobject,u8 copy_u8mapingstate){
	if(copy_u8mapingstate==NORMAL){
		s32 OUTPUT_s32vlaue;
		OUTPUT_s32vlaue=((copy_structobject->copy_s32max_output-copy_structobject->copy_s32min_output)/(copy_structobject->copy_s32max_input-copy_structobject->copy_s32min_input)*(copy_structobject->copy_s32inputvalue-copy_structobject->copy_s32min_input))+copy_structobject->copy_s32min_output;
		return OUTPUT_s32vlaue;
	}
	else if(copy_u8mapingstate==REVERSED){
		s32 INPUT_s32vlaue;
		INPUT_s32vlaue=((copy_structobject->copy_s32max_input-copy_structobject->copy_s32min_input)/(copy_structobject->copy_s32max_output-copy_structobject->copy_s32min_output))*(copy_structobject->copy_s32outputvalue-copy_structobject->copy_s32min_output)+copy_structobject->copy_s32min_input;
		return INPUT_s32vlaue;
	}
	else{
		return 0;
	}

}


