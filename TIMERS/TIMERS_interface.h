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
void TIMER0_voidchoosecmpmodechanA(void);
void TIMER0_voidchoosecmpmodechanB(void);
void TIMER0_voidchoosefastorphasepwmmodechanA(void);
void TIMER0_voidchoosefastorphasepwmmodechanB(void);
void TIMER0_voidchooseprescaler(void);
void TIMER0_voidsetoverflowint(void);
void TIMER0_voidsetcompint(void);


void TIMER1_voidinit(void);
void TIMER1_voidchoosecmpmodechanA(void);
void TIMER1_voidchoosecmpmodechanB(void);
void TIMER1_voidchoosefastorphasepwmmodechanA(void);
void TIMER1_voidchoosefastorphasepwmmodechanB(void);
void TIMER1_voidchooseprescaler(void);
void TIMER1_voidsetoverflowint(void);
void TIMER1_voidsetcompint(void);

void TIMER2_voidinit(void);
void TIMER2_voidchoosecmpmodechanA(void);
void TIMER2_voidchoosecmpmodechanB(void);
void TIMER2_voidchoosefastorphasepwmmodechanA(void);
void TIMER2_voidchoosefastorphasepwmmodechanB(void);
void TIMER2_voidchooseprescaler(void);
void TIMER2_voidsetoverflowint(void);
void TIMER2_voidsetcompint(void);

u8 TIMER_u8setmode(u8 copy_u8timerno,u8 copy_u8initmode);
u8 TIMER_u8choosecompmode(u8 copy_u8timerno,u8 copy_channelno,u8 copy_u8mode);
u8 TIMER_u8choosefastorphasemode(u8 copy_u8timerno,u8 copy_channelno,u8 copy_u8mode);
u8 TIMER_u8setprescaler(u8 copy_u8timerno,u8 copy_u8prescale);
u8 TIMER_u8setoverflowcallback(u8 copy_u8timerno,void(* copy_pvfunc)(void));
u8 TIMER_u8setcompmatchcallback(u8 copy_u8timerno,void(* copy_pvfunc)(void),u8 copy_channel);

u8 TIMER0_2_u8settimervalue(u8 copy_u8timerno,u8 copy_u8rimervalue);
void TIMER1_u8settimervalue(u16 copy_u16rimervalue);
u8 TIMER0_2_u8getimervalue(u8 copy_u8timerno,u8* copy_pu8rimervalue);














void TIMER1_voidsettimer1value(u16 copy_u8timer1value);
u16 TIMER1_u16readtimervalue(void);



u8 TIMER0_setcallback(void(* copy_pvcallbackfunc)(void));
void TIMER0_voidsetcompmatchvalue(u16 copy_u8vlaue);
#define NORMAL    1
#define REVERSED  2
#define TIMER0    0
#define TIMER1    1
#define TIMER2    2
#define CHAN_A    0
#define CHAN_B    1





#endif
