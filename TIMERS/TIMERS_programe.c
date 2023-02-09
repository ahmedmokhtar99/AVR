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


void TIMER0_voidinit(void){
    /*choose CTC mode*/
	CLEAR_BIT(TCCR0A,TCCR0A_WGM00);
    SET_BIT(TCCR0A,TCCR0A_WGM01);

    /*enable compare match interrupt */
    SET_BIT(TIMSK0,TIMSK0_OCIE0A);

    /*set compare match output value*/
    OCOR0A=250;


    /*choose prescaler division by 8*/
    CLEAR_BIT(TCCR0B,TCCR0B_CS00);
    SET_BIT(TCCR0B,TCCR0B_CS01);
	CLEAR_BIT(TCCR0B,TCCR0B_CS02);



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
void __vector_14 (void)__attribute__((signal));
void __vector_14 (void){
	if(TIMER_pvcallbackfunc!=NULL){
		TIMER_pvcallbackfunc();
	}
}


