/************************************************************************************/
/************************************************************************************/
/**********************      AUTHOR: AHMED MOKHTAR       ****************************/
/**********************      LAYER: MCAL                 ****************************/
/**********************      SWC:TIMERS                  ****************************/
/**********************      VERSION: 1.00               ****************************/
/************************************************************************************/
/************************************************************************************/
#ifndef TIMERS_INTERFACE_H
#define TIMERS_INTERFACE_H

typedef struct {
	s32 copy_s32min_input;
	s32 copy_s32max_input;
	s32 copy_s32min_output;
	s32 copy_s32max_output;
	s32 copy_s32inputvalue;
	s32 copy_s32outputvalue;


}MAPING;

s32 MAPING_s32mapingvalue(MAPING*copy_structobject,u8 copy_u8mapingstate);

void TIMER0_voidinit(void);
void TIMER1_voidinit(void);
void TIMER1_voidsettimer1value(u16 copy_u8timer1value);
u16 TIMER1_u16readtimervalue(void);
u8 ICU_u8settriggeredge(u8 copy_u8edge);
void ICU_voidinit(void);
void ICU_voidenableinterrupt(void);
void ICU_voiddisableinterrupt(void);
u16 ICU_u16readinputcapture(void);
u8 ICU_u8pvsetcallback(void(*copy_pvcallbackfunc)(void));


u8 TIMER0_setcallback(void(* copy_pvcallbackfunc)(void));
void TIMER0_voidsetcompmatchvalue(u16 copy_u8vlaue);
#define NORMAL       1
#define REVERSED     2
#define RISING_EDGE   1
#define FALLING_EDGE  2


#endif
