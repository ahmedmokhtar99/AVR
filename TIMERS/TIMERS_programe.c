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


static void(*TIMER0_pvcallbackfunc)(void)=NULL;
static void(*TIMER1_pvcallbackfunc)(void)=NULL;
static void(*TIMER2_pvcallbackfunc)(void)=NULL;


static void(*TIMER0_pvcallbackcompfuncA)(void)=NULL;
static void(*TIMER1_pvcallbackcompfuncA)(void)=NULL;
static void(*TIMER2_pvcallbackcompfuncA)(void)=NULL;
static void(*TIMER0_pvcallbackcompfuncB)(void)=NULL;
static void(*TIMER1_pvcallbackcompfuncB)(void)=NULL;
static void(*TIMER2_pvcallbackcompfuncB)(void)=NULL;



void TIMER0_voidinit(void){
#if TIMER0_MODE==NORMAL_MODE
	CLEAR_BIT(TCCR0A,TCCR0A_WGM00);
	CLEAR_BIT(TCCR0A,TCCR0A_WGM01);
	CLEAR_BIT(TCCR0A,TCCR0B_WGM02);
#elif TIMER0_MODE==COMPAREMATCH_MODE
	CLEAR_BIT(TCCR0A,TCCR0A_WGM00);
	SET_BIT(TCCR0A,TCCR0A_WGM01);
	CLEAR_BIT(TCCR0A,TCCR0B_WGM02);
#elif TIMER0_MODE==FASTPWM_NORMALMDOE
	SET_BIT(TCCR0A,TCCR0A_WGM00);
	SET_BIT(TCCR0A,TCCR0A_WGM01);
	CLEAR_BIT(TCCR0A,TCCR0B_WGM02);
#elif TIMER0_MODE==FASTPWM_OCMODE
	SET_BIT(TCCR0A,TCCR0A_WGM00);
	SET_BIT(TCCR0A,TCCR0A_WGM01);
	SET_BIT(TCCR0A,TCCR0B_WGM02);
#elif TIMER0_MODE==PHASECORRECTPWM_NORMALMODE
	SET_BIT(TCCR0A,TCCR0A_WGM00);
	CLEAR_BIT(TCCR0A,TCCR0A_WGM01);
	CLEAR_BIT(TCCR0A,TCCR0B_WGM02);
#elif TIMER0_MODE==PHASECORRECTPWM_OCMODE
	SET_BIT(TCCR0A,TCCR0A_WGM00);
	CLEAR_BIT(TCCR0A,TCCR0A_WGM01);
	SET_BIT(TCCR0A,TCCR0B_WGM02);
#else
#error"WRONG PRAMATERS"
#endif
	void TIMER1_voidinit(void){
#if TIMER1_MODE==NORMAL_MODE
		CLEAR_BIT(TCCR1A,TCCR1A_WGM10);
		CLEAR_BIT(TCCR1A,TCCR1A_WGM11);
		CLEAR_BIT(TCCR1A,TCCR1B_WGM12);
		CLEAR_BIT(TCCR1A,TCCR1B_WGM13);

#elif TIMER1_MODE==COMPAREMATCH_MODEOC
		CLEAR_BIT(TCCR1A,TCCR1A_WGM10);
		CLEAR_BIT(TCCR1A,TCCR1A_WGM11);
		SET_BIT(TCCR1A,TCCR1B_WGM12);
		CLEAR_BIT(TCCR1A,TCCR1B_WGM13);
#elif TIMER1_MODE==COMPAREMATCH_MODEIC
		CLEAR_BIT(TCCR1A,TCCR1A_WGM10);
		CLEAR_BIT(TCCR1A,TCCR1A_WGM11);
		SET_BIT(TCCR1A,TCCR1B_WGM12);
		SET_BIT(TCCR1A,TCCR1B_WGM13);
#elif TIMER1_MODE==FASTPWM_NORMAL8BITMODE
		SET_BIT(TCCR1A,TCCR1A_WGM10);
		CLEAR_BIT(TCCR1A,TCCR1A_WGM11);
		SET_BIT(TCCR1A,TCCR1B_WGM12);
		CLEAR_BIT(TCCR1A,TCCR1B_WGM13);
#elif TIMER1_MODE==FASTPWM_NORMAL9BITMODE
		CLEAR_BIT(TCCR1A,TCCR1A_WGM10);
		SET_BIT(TCCR1A,TCCR1A_WGM11);
		SET_BIT(TCCR1A,TCCR1B_WGM12);
		CLEAR_BIT(TCCR1A,TCCR1B_WGM13);
#elif TIMER1_MODE==FASTPWM_NORMAL10BITMODE
		SET_BIT(TCCR1A,TCCR1A_WGM10);
		SET_BIT(TCCR1A,TCCR1A_WGM11);
		SET_BIT(TCCR1A,TCCR1B_WGM12);
		CLEAR_BIT(TCCR1A,TCCR1B_WGM13);
#elif TIMER1_MODE==FASTPWM_OCMODE
		SET_BIT(TCCR1A,TCCR1A_WGM10);
		SET_BIT(TCCR1A,TCCR1A_WGM11);
		SET_BIT(TCCR1A,TCCR1B_WGM12);
		SET_BIT(TCCR1A,TCCR1B_WGM13);
#elif TIMER1_MODE==FASTPWM_ICMODE
		CLEAR_BIT(TCCR1A,TCCR1A_WGM10);
		SET_BIT(TCCR1A,TCCR1A_WGM11);
		SET_BIT(TCCR1A,TCCR1B_WGM12);
		SET_BIT(TCCR1A,TCCR1B_WGM13);
#elif TIMER1_MODE==PHASECORRECTPWM_NORMAL8BITMODE
		SET_BIT(TCCR1A,TCCR1A_WGM10);
		CLEAR_BIT(TCCR1A,TCCR1A_WGM11);
		CLEAR_BIT(TCCR1A,TCCR1B_WGM12);
		CLEAR_BIT(TCCR1A,TCCR1B_WGM13);
#elif TIMER1_MODE==PHASECORRECTPWM_NORMAL9BITMODE
		CLEAR_BIT(TCCR1A,TCCR1A_WGM10);
		SET_BIT(TCCR1A,TCCR1A_WGM11);
		CLEAR_BIT(TCCR1A,TCCR1B_WGM12);
		CLEAR_BIT(TCCR1A,TCCR1B_WGM13);
#elif TIMER1_MODE==PHASECORRECTPWM_NORMAL10BITMODE
		SET_BIT(TCCR1A,TCCR1A_WGM10);
		SET_BIT(TCCR1A,TCCR1A_WGM11);
		CLEAR_BIT(TCCR1A,TCCR1B_WGM12);
		CLEAR_BIT(TCCR1A,TCCR1B_WGM13);
#elif TIMER1_MODE==PHASECORRECTPWM_ICMODE
		CLEAR_BIT(TCCR1A,TCCR1A_WGM10);
		SET_BIT(TCCR1A,TCCR1A_WGM11);
		CLEAR_BIT(TCCR1A,TCCR1B_WGM12);
		SET_BIT(TCCR1A,TCCR1B_WGM13);
#elif TIMER1_MODE==PHASECORRECTPWM_OCMODE
		SET_BIT(TCCR1A,TCCR1A_WGM10);
		SET_BIT(TCCR1A,TCCR1A_WGM11);
		CLEAR_BIT(TCCR1A,TCCR1B_WGM12);
		SET_BIT(TCCR1A,TCCR1B_WGM13);
#else
#error"WRONG PRAMATERS"
#endif

	}
	void TIMER0_voidchoosecmpmodechanA(void){
#if  COMP_MODE==NORMAL_MODE
		CLEAR_BIT(TCCR0A,TCCR0A_COM0A0);
		CLEAR_BIT(TCCR0A,TCCR0A_COM0A1);
#elif COMP_MODE==TOOGLE_MODE
		SET_BIT(TCCR0A,TCCR0A_COM0A0);
		CLEAR_BIT(TCCR0A,TCCR0A_COM0A1);
#elif COMP_MODE==CLEAR_MODE
		CLEAR_BIT(TCCR0A,TCCR0A_COM0A0);
		SET_BIT(TCCR0A,TCCR0A_COM0A1);
#elif COMP_MODE==SET_MODE
		SET_BIT(TCCR0A,TCCR0A_COM0A0);
		SET_BIT(TCCR0A,TCCR0A_COM0A1);
#else
#error "WRONG PRAMATERS"
#endif

	}
	void TIMER0_voidchoosecmpmodechanB(void){
#if COMP_MODE==NORMAL_MODE
		CLEAR_BIT(TCCR0A,TCCR0A_COM0B0);
		CLEAR_BIT(TCCR0A,TCCR0A_COM0B1);
#elif COMP_MODE==TOOGLE_MODE
		SET_BIT(TCCR0A,TCCR0A_COM0B0);
		CLEAR_BIT(TCCR0A,TCCR0A_COM0B1);
#elif COMP_MODE==CLEAR_MODE
		CLEAR_BIT(TCCR0A,TCCR0A_COM0B0);
		SET_BIT(TCCR0A,TCCR0A_COM0B1);
#elif COMP_MODE==SET_MODE
		SET_BIT(TCCR0A,TCCR0A_COM0B0);
		SET_BIT(TCCR0A,TCCR0A_COM0B1);
#else
#error "WRONG PRAMATERS"
#endif

	}
	void TIMER0_voidchoosefastorphasepwmmodechanA(void){
#if FASTORPHASEPWM_MODE==NORMAL_MODE
		CLEAR_BIT(TCCR0A,TCCR0A_COM0A0);
		CLEAR_BIT(TCCR0A,TCCR0A_COM0A1);
#elif FASTPWM_MODE==SECOND_MODE
		SET_BIT(TCCR0A,TCCR0A_COM0A0);
		CLEAR_BIT(TCCR0A,TCCR0A_COM0A1);
#elif FASTPWM_MODE==NONINVERTING_MODE
		CLEAR_BIT(TCCR0A,TCCR0A_COM0A0);
		SET_BIT(TCCR0A,TCCR0A_COM0A1);
#elif FASTPWM_MODE==INVERTING_MODE
		SET_BIT(TCCR0A,TCCR0A_COM0A0);
		SET_BIT(TCCR0A,TCCR0A_COM0A1);
#else
#error "WRONG PRAMATERS"
#endif

	}
	void TIMER0_voidchoosefastorphasepwmmodechanB(void){
#if FASTPWM_MODE==NORMAL_MODE
		CLEAR_BIT(TCCR0A,TCCR0A_COM0B0);
		CLEAR_BIT(TCCR0A,TCCR0A_COM0B1);
#elif FASTPWM_MODE==NONINVERTIING_MODE
		CLEAR_BIT(TCCR0A,TCCR0A_COM0B0);
		SET_BIT(TCCR0A,TCCR0A_COM0B1);
#elif FASTPWM_MODE==INVERTING_MODE
		SET_BIT(TCCR0A,TCCR0A_COM0B0);
		SET_BIT(TCCR0A,TCCR0A_COM0B1);
#else
#error "WRONG PRAMATERS"
#endif

	}
	void TIMER0_voidchooseprescaler(void){
#if PRESCALE_MODE==SHUTDOWN_MODE
		CLEAR_BIT(TCCR0B,TCCR0B_CS00);
		CLEAR_BIT(TCCR0B,TCCR0B_CS01);
		CLEAR_BIT(TCCR0B,TCCR0B_CS02);
#elif PRESCALE_MODE==NOPRESCALE_MODE
		SET_BIT(TCCR0B,TCCR0B_CS00);
		CLEAR_BIT(TCCR0B,TCCR0B_CS01);
		CLEAR_BIT(TCCR0B,TCCR0B_CS02);
#elif PRESCALE_MODE==PRESCALE8_MODE
		CLEAR_BIT(TCCR0B,TCCR0B_CS00);
		SET_BIT(TCCR0B,TCCR0B_CS01);
		CLEAR_BIT(TCCR0B,TCCR0B_CS02);
#elif PRESCALE_MODE==PRESCALE64_MODE

		SET_BIT(TCCR0B,TCCR0B_CS00);
		SET_BIT(TCCR0B,TCCR0B_CS01);
		CLEAR_BIT(TCCR0B,TCCR0B_CS02);
#elif PRESCALE_MODE==PRESCALE256_MODE
		CLEAR_BIT(TCCR0B,TCCR0B_CS00);
		CLEAR_BIT(TCCR0B,TCCR0B_CS01);
		SET_BIT(TCCR0B,TCCR0B_CS02);
#elif PRESCALE_MODE==PRESCALE1024_MODE
		SET_BIT(TCCR0B,TCCR0B_CS00);
		CLEAR_BIT(TCCR0B,TCCR0B_CS01);
		SET_BIT(TCCR0B,TCCR0B_CS02);
#elif PRESCALE_MODE==EXTCLMFALLING_MODE
		CLEAR_BIT(TCCR0B,TCCR0B_CS00);
		SET	_BIT(TCCR0B,TCCR0B_CS01);
		SET_BIT(TCCR0B,TCCR0B_CS02);
#elif PRESCALE_MODE==EXTCLMRISISNG_MODE
		SET_BIT(TCCR0B,TCCR0B_CS00);
		SET	_BIT(TCCR0B,TCCR0B_CS01);
		SET_BIT(TCCR0B,TCCR0B_CS02);
#else
#error "WRONG PRAMATERS"

#endif
		void TIMER0_voidsetoverflowint(void){
#if TIMER0_OVINT==ENABLE
			SET_BIT(TIMSK0,TIMSK0_TOIE0);
#elif TIMER0_OVINT==DISABLE
			SET_BIT(TIMSK0,TIMSK0_TOIE0);

#else
#error "WRONG PRAMATERS"
#endif
		}
		void TIMER0_voidsetcompint(void){
#if TIMER0_COMPINT==ENABLE
			SET_BIT(TIMSK0,TIMSK0_OCIE0A);
#elif TIMER0_COMPINT==DISABLE
			CLEAR_BIT(TIMSK0,TIMSK0_OCIE0A);

#else
#error "WRONG PRAMATERS"
#endif
		}


	}
	void TIMER1_voidchoosecmpmodechanA(void){
#if  COMP_MODE==NORMAL_MODE
		CLEAR_BIT(TCCR1A,TCCR1A_COM1A0);
		CLEAR_BIT(TCCR1A,TCCR1A_COM1A1);
#elif COMP_MODE==TOOGLE_MODE
		SET_BIT(TCCR1A,TCCR1A_COM1A0);
		CLEAR_BIT(TCCR1A,TCCR1A_COM1A1);
#elif COMP_MODE==CLEAR_MODE
		CLEAR_BIT(TCCR1A,TCCR1A_COM1A0);
		SET_BIT(TCCR1A,TCCR1A_COM1A1);
#elif COMP_MODE==SET_MODE
		SET_BIT(TCCR1A,TCCR1A_COM1A0);
		SET_BIT(TCCR1A,TCCR1A_COM1A1);
#else
#error "WRONG PRAMATERS"
#endif

	}
	void TIMER1_voidchoosecmpmodechanB(void){
#if COMP_MODE==NORMAL_MODE
		CLEAR_BIT(TCCR1A,TCCR1A_COM1B0);
		CLEAR_BIT(TCCR1A,TCCR1A_COM1B1);
#elif COMP_MODE==TOOGLE_MODE
		SET_BIT(TCCR1A,TCCR1A_COM1B0);
		CLEAR_BIT(TCCR1A,TCCR1A_COM1B1);
#elif COMP_MODE==CLEAR_MODE
		CLEAR_BIT(TCCR1A,TCCR1A_COM1B0);
		SET_BIT(TCCR1A,TCCR1A_COM1B1);
#elif COMP_MODE==SET_MODE
		SET_BIT(TCCR1A,TCCR1A_COM1B0);
		SET_BIT(TCCR1A,TCCR1A_COM1B1);
#else
#error "WRONG PRAMATERS"
#endif

	}
	void TIMER1_voidchoosefastorphasepwmmodechanA(void){
#if FASTORPHASEPWM_MODE==NORMAL_MODE
		CLEAR_BIT(TCCR1A,TCCR1A_COM1A0);
		CLEAR_BIT(TCCR1A,TCCR1A_COM1A1);
#elif FASTPWM_MODE==SECOND_MODE
		SET_BIT(TCCR1A,TCCR1A_COM1A0);
		CLEAR_BIT(TCCR1A,TCCR1A_COM1A1);
#elif FASTPWM_MODE==NONINVERTING_MODE
		CLEAR_BIT(TCCR1A,TCCR1A_COM1A0);
		SET_BIT(TCCR1A,TCCR1A_COM1A1);
#elif FASTPWM_MODE==INVERTING_MODE
		SET_BIT(TCCR1A,TCCR1A_COM1A0);
		SET_BIT(TCCR1A,TCCR1A_COM1A1);
#else
#error "WRONG PRAMATERS"
#endif

	}
	void TIMER1_voidchoosefastorphasepwmmodechanB(void){
#if FASTPWM_MODE==NORMAL_MODE
		CLEAR_BIT(TCCR1A,TCCR1A_COM1B0);
		CLEAR_BIT(TCCR1A,TCCR1A_COM1B1);
#elif FASTPWM_MODE==NONINVERTIING_MODE
		CLEAR_BIT(TCCR1A,TCCR1A_COM1B0);
		SET_BIT(TCCR1A,TCCR1A_COM1B1);
#elif FASTPWM_MODE==INVERTING_MODE
		SET_BIT(TCCR1A,TCCR1A_COM1B0);
		SET_BIT(TCCR1A,TCCR1A_COM1B1);
#else
#error "WRONG PRAMATERS"
#endif

	}
	void TIMER1_voidchooseprescaler(void){
#if PRESCALE_MODE==SHUTDOWN_MODE
		CLEAR_BIT(TCCR1B,TCCR1B_CS10);
		CLEAR_BIT(TCCR1B,TCCR1B_CS11);
		CLEAR_BIT(TCCR1B,TCCR1B_CS12);
#elif PRESCALE_MODE==NOPRESCALE_MODE
		SET_BIT(TCCR1B,TCCR1B_CS10);
		CLEAR_BIT(TCCR1B,TCCR1B_CS11);
		CLEAR_BIT(TCCR1B,TCCR1B_CS12);
#elif PRESCALE_MODE==PRESCALE8_MODE
		CLEAR_BIT(TCCR1B,TCCR1B_CS10);
		SET_BIT(TCCR1B,TCCR1B_CS11);
		CLEAR_BIT(TCCR1B,TCCR1B_CS12);
#elif PRESCALE_MODE==PRESCALE64_MODE

		SET_BIT(TCCR1B,TCCR1B_CS10);
		SET_BIT(TCCR1B,TCCR1B_CS11);
		CLEAR_BIT(TCCR1B,TCCR1B_CS12);
#elif PRESCALE_MODE==PRESCALE256_MODE
		CLEAR_BIT(TCCR1B,TCCR1B_CS10);
		CLEAR_BIT(TCCR1B,TCCR1B_CS11);
		SET_BIT(TCCR1B,TCCR1B_CS12);
#elif PRESCALE_MODE==PRESCALE1024_MODE
		SET_BIT(TCCR1B,TCCR1B_CS10);
		CLEAR_BIT(TCCR1B,TCCR1B_CS11);
		SET_BIT(TCCR1B,TCCR1B_CS12);
#elif PRESCALE_MODE==EXTCLMFALLING_MODE
		CLEAR_BIT(TCCR1B,TCCR1B_CS10);
		SET_BIT(TCCR1B,TCCR1B_CS11);
		SET_BIT(TCCR1B,TCCR1B_CS12);
#elif PRESCALE_MODE==EXTCLMRISISNG_MODE
		SET_BIT(TCCR1B,TCCR1B_CS10);
		SET_BIT(TCCR1B,TCCR1B_CS11);
		SET_BIT(TCCR1B,TCCR1B_CS12);
#else
#error "WRONG PRAMATERS"

#endif
	}
	void TIMER1_voidsetoverflowint(void){
#if TIMER1_OVINT==ENABLE
		SET_BIT(TIMSK1,TIMSK1_TOIE1);
#elif TIMER1_OVINT==DISABLE
		SET_BIT(TIMSK1,TIMSK1_TOIE1);

#else
#error "WRONG PRAMATERS"
#endif
	}
	void TIMER1_voidsetcompint(void){
#if TIMER1_COMPINT==ENABLE
		SET_BIT(TIMSK1,TIMSK1_OCIE1A);
#elif TIMER1_COMPINT==DISABLE
		CLEAR_BIT(TIMSK1,TIMSK1_OCIE1A);

#else
#error "WRONG PRAMATERS"
#endif
	}

	void TIMER2_voidinit(void){
#if TIMER2_MODE==NORMAL_MODE
		CLEAR_BIT(TCCR2A,TCCR2A_WGM20);
		CLEAR_BIT(TCCR2A,TCCR2A_WGM21);
		CLEAR_BIT(TCCR2A,TCCR2B_WGM22);
#elif TIMER0_MODE==COMPAREMATCH_MODE
		CLEAR_BIT(TCCR2A,TCCR2A_WGM20);
		SET_BIT(TCCR2A,TCCR2A_WGM21);
		CLEAR_BIT(TCCR2A,TCCR2B_WGM22);
#elif TIMER0_MODE==FASTPWM_NORMALMDOE
		SET_BIT(TCCR2A,TCCR2A_WGM20);
		SET_BIT(TCCR2A,TCCR2A_WGM21);
		CLEAR_BIT(TCCR2A,TCCR2B_WGM22);
#elif TIMER0_MODE==FASTPWM_OCMODE
		SET_BIT(TCCR2A,TCCR2A_WGM20);
		SET_BIT(TCCR2A,TCCR2A_WGM21);
		SET_BIT(TCCR2A,TCCR2B_WGM22);
#elif TIMER0_MODE==PHASECORRECTPWM_NORMALMODE
		SET_BIT(TCCR2A,TCCR2A_WGM20);
		CLEAR_BIT(TCCR2A,TCCR2A_WGM21);
		CLEAR_BIT(TCCR2A,TCCR2B_WGM22);
#elif TIMER0_MODE==PHASECORRECTPWM_OCMODE
		SET_BIT(TCCR2A,TCCR2A_WGM20);
		CLEAR_BIT(TCCR2A,TCCR2A_WGM21);
		SET_BIT(TCCR2A,TCCR2B_WGM22);
#else
#error"WRONG PRAMATERS"
		SET_BIT(TIMSK2,TIMSK2_TOIE2);
		SET_BIT(TIMSK2,TIMSK2_OCIE2A);

#endif


	}
	void TIMER2_voidchoosecmpmodechanA(void){
#if  COMP_MODE==NORMAL_MODE
		CLEAR_BIT(TCCR2A,TCCR2A_COM2A0);
		CLEAR_BIT(TCCR2A,TCCR2A_COM2A1);
#elif COMP_MODE==TOOGLE_MODE
		SET_BIT(TCCR2A,TCCR2A_COM2A0);
		CLEAR_BIT(TCCR2A,TCCR2A_COM2A1);
#elif COMP_MODE==CLEAR_MODE
		CLEAR_BIT(TCCR2A,TCCR2A_COM2A0);
		SET_BIT(TCCR2A,TCCR2A_COM2A1);
#elif COMP_MODE==SET_MODE
		SET_BIT(TCCR2A,TCCR2A_COM2A0);
		SET_BIT(TCCR2A,TCCR2A_COM2A1);
#else
#error "WRONG PRAMATERS"
#endif

	}
	void TIMER2_voidchoosecmpmodechanB(void){
#if COMP_MODE==NORMAL_MODE
		CLEAR_BIT(TCCR2A,TCCR2A_COM2B0);
		CLEAR_BIT(TCCR2A,TCCR2A_COM2B1);
#elif COMP_MODE==TOOGLE_MODE
		SET_BIT(TCCR2A,TCCR2A_COM2B0);
		CLEAR_BIT(TCCR2A,TCCR2A_COM2B1);
#elif COMP_MODE==CLEAR_MODE
		CLEAR_BIT(TCCR2A,TCCR2A_COM2B0);
		SET_BIT(TCCR2A,TCCR2A_COM2B1);
#elif COMP_MODE==SET_MODE
		SET_BIT(TCCR2A,TCCR2A_COM2B0);
		SET_BIT(TCCR2A,TCCR2A_COM2B1);
#else
#error "WRONG PRAMATERS"
#endif

	}
	void TIMER2_voidchoosefastorphasepwmmodechanA(void){
#if FASTORPHASEPWM_MODE==NORMAL_MODE
		CLEAR_BIT(TCCR2A,TCCR2A_COM2A0);
		CLEAR_BIT(TCCR2A,TCCR2A_COM2A1);
#elif FASTPWM_MODE==SECOND_MODE
		SET_BIT(TCCR2A,TCCR2A_COM2A0);
		CLEAR_BIT(TCCR2A,TCCR2A_COM2A1);
#elif FASTPWM_MODE==NONINVERTING_MODE
		CLEAR_BIT(TCCR2A,TCCR2A_COM2A0);
		SET_BIT(TCCR2A,TCCR2A_COM2A1);
#elif FASTPWM_MODE==INVERTING_MODE
		SET_BIT(TCCR2A,TCCR2A_COM2A0);
		SET_BIT(TCCR2A,TCCR2A_COM2A1);
#else
#error "WRONG PRAMATERS"
#endif

	}
	void TIMER2_voidchoosefastorphasepwmmodechanB(void){
#if FASTPWM_MODE==NORMAL_MODE
		CLEAR_BIT(TCCR2A,TCCR2A_COM2B0);
		CLEAR_BIT(TCCR2A,TCCR2A_COM2B1);
#elif FASTPWM_MODE==NONINVERTIING_MODE
		CLEAR_BIT(TCCR2A,TCCR2A_COM2B0);
		SET_BIT(TCCR2A,TCCR2A_COM2B1);
#elif FASTPWM_MODE==INVERTING_MODE
		SET_BIT(TCCR2A,TCCR2A_COM2B0);
		SET_BIT(TCCR2A,TCCR2A_COM2B1);
#else
#error "WRONG PRAMATERS"
#endif

	}
	void TIMER2_voidchooseprescaler(void){
#if PRESCALE_MODE==SHUTDOWN_MODE
		CLEAR_BIT(TCCR2B,TCCR2B_CS20);
		CLEAR_BIT(TCCR2B,TCCR2B_CS21);
		CLEAR_BIT(TCCR2B,TCCR2B_CS22);
#elif PRESCALE_MODE==NOPRESCALE_MODE
		SET_BIT(TCCR2B,TCCR2B_CS20);
		CLEAR_BIT(TCCR2B,TCCR2B_CS21);
		CLEAR_BIT(TCCR2B,TCCR2B_CS22);
#elif PRESCALE_MODE==PRESCALE8_MODE
		CLEAR_BIT(TCCR2B,TCCR2B_CS20);
		SET_BIT(TCCR2B,TCCR2B_CS21);
		CLEAR_BIT(TCCR2B,TCCR2B_CS22);
#elif PRESCALE_MODE==PRESCALE64_MODE

		SET_BIT(TCCR2B,TCCR2B_CS20);
		SET_BIT(TCCR2B,TCCR2B_CS21);
		CLEAR_BIT(TCCR2B,TCCR2B_CS22);
#elif PRESCALE_MODE==PRESCALE256_MODE
		CLEAR_BIT(TCCR2B,TCCR2B_CS20);
		CLEAR_BIT(TCCR2B,TCCR2B_CS21);
		SER_BIT(TCCR2B,TCCR2B_CS22);
#elif PRESCALE_MODE==PRESCALE1024_MODE
		SET_BIT(TCCR2B,TCCR2B_CS20);
		CLEAR_BIT(TCCR2B,TCCR2B_CS21);
		SET_BIT(TCCR2B,TCCR2B_CS22);
#elif PRESCALE_MODE==EXTCLMFALLING_MODE
		CLEAR_BIT(TCCR2B,TCCR2B_CS20);
		SET_BIT(TCCR2B,TCCR2B_CS21);
		SET_BIT(TCCR2B,TCCR2B_CS22);
#elif PRESCALE_MODE==EXTCLMRISISNG_MODE
		SET_BIT(TCCR2B,TCCR2B_CS20);
		SET_BIT(TCCR2B,TCCR2B_CS21);
		SET_BIT(TCCR2B,TCCR2B_CS22);
#else
#error "WRONG PRAMATERS"

#endif


	}
	void TIMER2_voidsetoverflowint(void){
#if TIMER2_OVINT==ENABLE
		SET_BIT(TIMSK2,TIMSK2_TOIE2);
#elif TIMER2_OVINT==DISABLE
		SET_BIT(TIMSK2,TIMSK2_TOIE2);

#else
#error "WRONG PRAMATERS"
#endif
	}
	void TIMER2_voidsetcompint(void){
#if TIMER2_COMPINT==ENABLE
		SET_BIT(TIMSK2,TIMSK2_OCIE2A);
#elif TIMER2_COMPINT==DISABLE
		CLEAR_BIT(TIMSK2,TIMSK2_OCIE2A);

#else
#error "WRONG PRAMATERS"
#endif
	}
	u8 TIMER_u8setmode(u8 copy_u8timerno,u8 copy_u8initmode){
		u8 Local_u8errorstate=OK;
		if(copy_u8timerno==TIMER0){
			switch(copy_u8initmode){
			case NORMAL_MODE:
				CLEAR_BIT(TCCR0A,TCCR0A_WGM00);
				CLEAR_BIT(TCCR0A,TCCR0A_WGM01);
				CLEAR_BIT(TCCR0A,TCCR0B_WGM02);
				break;
			case COMPAREMATCH_MODE:
				CLEAR_BIT(TCCR0A,TCCR0A_WGM00);
				SET_BIT(TCCR0A,TCCR0A_WGM01);
				CLEAR_BIT(TCCR0A,TCCR0B_WGM02);
				break;
			case FASTPWM_NORMALMDOE:
				SET_BIT(TCCR0A,TCCR0A_WGM00);
				SET_BIT(TCCR0A,TCCR0A_WGM01);
				CLEAR_BIT(TCCR0A,TCCR0B_WGM02);
				break;
			case FASTPWM_OCMODE:
				SET_BIT(TCCR0A,TCCR0A_WGM00);
				SET_BIT(TCCR0A,TCCR0A_WGM01);
				SET_BIT(TCCR0A,TCCR0B_WGM02);
				break;
			case PHASECORRECTPWM_NORMALMODE:
				SET_BIT(TCCR0A,TCCR0A_WGM00);
				CLEAR_BIT(TCCR0A,TCCR0A_WGM01);
				CLEAR_BIT(TCCR0A,TCCR0B_WGM02);
				break;
			case PHASECORRECTPWM_OCMODE:
				SET_BIT(TCCR0A,TCCR0A_WGM00);
				CLEAR_BIT(TCCR0A,TCCR0A_WGM01);
				SET_BIT(TCCR0A,TCCR0B_WGM02);
				break;
			default:Local_u8errorstate=NOK;
			}
		}
		else if(copy_u8timerno==TIMER1){
			switch(copy_u8initmode){
			case NORMAL_MODE:
				CLEAR_BIT(TCCR1A,TCCR1A_WGM10);
				CLEAR_BIT(TCCR1A,TCCR1A_WGM11);
				CLEAR_BIT(TCCR1A,TCCR1B_WGM12);
				CLEAR_BIT(TCCR1A,TCCR1B_WGM13);
				break;
			case COMPAREMATCH_MODEOC:
				CLEAR_BIT(TCCR1A,TCCR1A_WGM10);
				CLEAR_BIT(TCCR1A,TCCR1A_WGM11);
				SET_BIT(TCCR1A,TCCR1B_WGM12);
				CLEAR_BIT(TCCR1A,TCCR1B_WGM13);
				break;
			case COMPAREMATCH_MODEIC:

				CLEAR_BIT(TCCR1A,TCCR1A_WGM10);
				CLEAR_BIT(TCCR1A,TCCR1A_WGM11);
				SET_BIT(TCCR1A,TCCR1B_WGM12);
				SET_BIT(TCCR1A,TCCR1B_WGM13);
				break;
			case FASTPWM_NORMAL8BITMODE:
				SET_BIT(TCCR1A,TCCR1A_WGM10);
				CLEAR_BIT(TCCR1A,TCCR1A_WGM11);
				SET_BIT(TCCR1A,TCCR1B_WGM12);
				CLEAR_BIT(TCCR1A,TCCR1B_WGM13);
				break;
			case FASTPWM_NORMAL9BITMODE:
				CLEAR_BIT(TCCR1A,TCCR1A_WGM10);
				SET_BIT(TCCR1A,TCCR1A_WGM11);
				SET_BIT(TCCR1A,TCCR1B_WGM12);
				CLEAR_BIT(TCCR1A,TCCR1B_WGM13);
				break;
			case FASTPWM_NORMAL10BITMODE:
				SET_BIT(TCCR1A,TCCR1A_WGM10);
				SET_BIT(TCCR1A,TCCR1A_WGM11);
				SET_BIT(TCCR1A,TCCR1B_WGM12);
				CLEAR_BIT(TCCR1A,TCCR1B_WGM13);
				break;
			case FASTPWM_ICMODE:
				CLEAR_BIT(TCCR1A,TCCR1A_WGM10);
				SET_BIT(TCCR1A,TCCR1A_WGM11);
				SET_BIT(TCCR1A,TCCR1B_WGM12);
				SET_BIT(TCCR1A,TCCR1B_WGM13);
				break;
			case FASTPWM_OCMODE:
				SET_BIT(TCCR1A,TCCR1A_WGM10);
				SET_BIT(TCCR1A,TCCR1A_WGM11);
				SET_BIT(TCCR1A,TCCR1B_WGM12);
				SET_BIT(TCCR1A,TCCR1B_WGM13);
				break;

			case PHASECORRECTPWM_NORMAL8BITMODE:
				SET_BIT(TCCR1A,TCCR1A_WGM10);
				CLEAR_BIT(TCCR1A,TCCR1A_WGM11);
				CLEAR_BIT(TCCR1A,TCCR1B_WGM12);
				CLEAR_BIT(TCCR1A,TCCR1B_WGM13);
				break;
			case PHASECORRECTPWM_NORMAL9BITMODE:
				CLEAR_BIT(TCCR1A,TCCR1A_WGM10);
				SET_BIT(TCCR1A,TCCR1A_WGM11);
				CLEAR_BIT(TCCR1A,TCCR1B_WGM12);
				CLEAR_BIT(TCCR1A,TCCR1B_WGM13);
				break;

			case PHASECORRECTPWM_NORMAL10BITMODE:
				SET_BIT(TCCR1A,TCCR1A_WGM10);
				SET_BIT(TCCR1A,TCCR1A_WGM11);
				CLEAR_BIT(TCCR1A,TCCR1B_WGM12);
				CLEAR_BIT(TCCR1A,TCCR1B_WGM13);
				break;
			case PHASECORRECTPWM_ICMODE:
				CLEAR_BIT(TCCR1A,TCCR1A_WGM10);
				SET_BIT(TCCR1A,TCCR1A_WGM11);
				CLEAR_BIT(TCCR1A,TCCR1B_WGM12);
				SET_BIT(TCCR1A,TCCR1B_WGM13);
				break;
			case PHASECORRECTPWM_OCMODE:
				SET_BIT(TCCR1A,TCCR1A_WGM10);
				SET_BIT(TCCR1A,TCCR1A_WGM11);
				CLEAR_BIT(TCCR1A,TCCR1B_WGM12);
				SET_BIT(TCCR1A,TCCR1B_WGM13);
				break;
			default:Local_u8errorstate=NOK;
			}
		}
		else if(copy_u8timerno==TIMER2){
			switch(copy_u8initmode){
			case NORMAL_MODE:
				CLEAR_BIT(TCCR2A,TCCR2A_WGM20);
				CLEAR_BIT(TCCR2A,TCCR2A_WGM21);
				CLEAR_BIT(TCCR2A,TCCR2B_WGM22);
				break;
			case COMPAREMATCH_MODE:
				CLEAR_BIT(TCCR2A,TCCR2A_WGM20);
				SET_BIT(TCCR2A,TCCR2A_WGM21);
				CLEAR_BIT(TCCR2A,TCCR2B_WGM22);
				break;
			case FASTPWM_NORMALMDOE:
				SET_BIT(TCCR2A,TCCR2A_WGM20);
				SET_BIT(TCCR2A,TCCR2A_WGM21);
				CLEAR_BIT(TCCR2A,TCCR2B_WGM22);
				break;
			case FASTPWM_OCMODE:
				SET_BIT(TCCR2A,TCCR2A_WGM20);
				SET_BIT(TCCR2A,TCCR2A_WGM21);
				SET_BIT(TCCR2A,TCCR2B_WGM22);
				break;
			case PHASECORRECTPWM_NORMALMODE:
				SET_BIT(TCCR2A,TCCR2A_WGM20);
				CLEAR_BIT(TCCR2A,TCCR2A_WGM21);
				CLEAR_BIT(TCCR2A,TCCR2B_WGM22);
				break;
			case PHASECORRECTPWM_OCMODE:
				SET_BIT(TCCR2A,TCCR2A_WGM20);
				CLEAR_BIT(TCCR2A,TCCR2A_WGM21);
				SET_BIT(TCCR2A,TCCR2B_WGM22);
				break;
			default:Local_u8errorstate=NOK;

			}
		}
		else {
			Local_u8errorstate=NOK;
		}
		return Local_u8errorstate;
	}

}
u8 TIMER_u8choosecompmode(u8 copy_u8timerno,u8 copy_channelno,u8 copy_u8mode){
	u8 Locla_u8errorstate=OK;
	if(copy_u8timerno==TIMER0){
		if(copy_channelno==CHAN_A){
			switch(copy_u8mode){
			case NORMAL_MODE:
				CLEAR_BIT(TCCR0A,TCCR0A_COM0A0);
				CLEAR_BIT(TCCR0A,TCCR0A_COM0A1);
				break;
			case TOOGLE_MODE:
				SET_BIT(TCCR0A,TCCR0A_COM0A0);
				CLEAR_BIT(TCCR0A,TCCR0A_COM0A1);
				break;
			case CLEAR_MODE:
				CLEAR_BIT(TCCR0A,TCCR0A_COM0A0);
				SET_BIT(TCCR0A,TCCR0A_COM0A1);
				break;
			case SET_MODE:
				SET_BIT(TCCR0A,TCCR0A_COM0A0);
				SET_BIT(TCCR0A,TCCR0A_COM0A1);
				break;
			default: Locla_u8errorstate=NOK;
			}
		}
		else if(copy_channelno==CHAN_B){
			switch(copy_u8mode){
			case NORMAL_MODE:
				CLEAR_BIT(TCCR0A,TCCR0A_COM0B0);
				CLEAR_BIT(TCCR0A,TCCR0A_COM0B1);
				break;
			case TOOGLE_MODE:
				SET_BIT(TCCR0A,TCCR0A_COM0B0);
				CLEAR_BIT(TCCR0A,TCCR0A_COM0B1);
				break;
			case CLEAR_MODE:
				CLEAR_BIT(TCCR0A,TCCR0A_COM0B0);
				SET_BIT(TCCR0A,TCCR0A_COM0B1);
				break;
			case SET_MODE:
				SET_BIT(TCCR0A,TCCR0A_COM0B0);
				SET_BIT(TCCR0A,TCCR0A_COM0B1);
				break;
			default:Locla_u8errorstate=NOK;

			}

		}
		else{
			Locla_u8errorstate=NOK;
		}
	}
	else if(copy_u8timerno==TIMER1){
		if(copy_channelno==CHAN_A){
			switch(copy_u8mode){
			case NORMAL_MODE:
				CLEAR_BIT(TCCR1A,TCCR1A_COM1A0);
				CLEAR_BIT(TCCR1A,TCCR1A_COM1A1);
				break;
			case TOOGLE_MODE:
				SET_BIT(TCCR1A,TCCR1A_COM1A0);
				CLEAR_BIT(TCCR1A,TCCR1A_COM1A1);
				break;

			case CLEAR_MODE:
				CLEAR_BIT(TCCR1A,TCCR1A_COM1A0);
				SET_BIT(TCCR1A,TCCR1A_COM1A1);
				break;
			case SET_MODE:
				SET_BIT(TCCR1A,TCCR1A_COM1A0);
				SET_BIT(TCCR1A,TCCR1A_COM1A1);
				break;
			default:Locla_u8errorstate=NOK;
			}
		}
		else if(copy_channelno==CHAN_B){
			switch(copy_u8mode){
			case NORMAL_MODE:
				CLEAR_BIT(TCCR1A,TCCR1A_COM1B0);
				CLEAR_BIT(TCCR1A,TCCR1A_COM1B1);
				break;
			case TOOGLE_MODE:
				SET_BIT(TCCR1A,TCCR1A_COM1B0);
				CLEAR_BIT(TCCR1A,TCCR1A_COM1B1);
				break;
			case CLEAR_MODE:
				CLEAR_BIT(TCCR1A,TCCR1A_COM1B0);
				SET_BIT(TCCR1A,TCCR1A_COM1B1);
				break;
			case SET_MODE:
				SET_BIT(TCCR1A,TCCR1A_COM1B0);
				SET_BIT(TCCR1A,TCCR1A_COM1B1);
				break;
			default:Locla_u8errorstate=NOK;




			}
		}
		else{
			Locla_u8errorstate=NOK;
		}
	}
	else if(copy_u8timerno==TIMER2){
		if(copy_channelno==CHAN_A){
			switch(copy_u8mode){
			case NORMAL_MODE:
				CLEAR_BIT(TCCR2A,TCCR2A_COM2B0);
				CLEAR_BIT(TCCR2A,TCCR2A_COM2B1);
				break;
			case TOOGLE_MODE:
				SET_BIT(TCCR2A,TCCR2A_COM2B0);
				CLEAR_BIT(TCCR2A,TCCR2A_COM2B1);
				break;
			case CLEAR_MODE:
				CLEAR_BIT(TCCR2A,TCCR2A_COM2B0);
				SET_BIT(TCCR2A,TCCR2A_COM2B1);
				break;
			case SET_MODE:
				SET_BIT(TCCR2A,TCCR2A_COM2B0);
				SET_BIT(TCCR2A,TCCR2A_COM2B1);
				break;
			default:Locla_u8errorstate=NOK;

			}
		}
		else if(copy_channelno==CHAN_B){
			switch(copy_u8mode){
			case NORMAL_MODE:
				CLEAR_BIT(TCCR2A,TCCR2A_COM2B0);
				CLEAR_BIT(TCCR2A,TCCR2A_COM2B1);
				break;
			case TOOGLE_MODE:
				SET_BIT(TCCR2A,TCCR2A_COM2B0);
				CLEAR_BIT(TCCR2A,TCCR2A_COM2B1);
				break;
			case CLEAR_MODE:
				CLEAR_BIT(TCCR2A,TCCR2A_COM2B0);
				SET_BIT(TCCR2A,TCCR2A_COM2B1);
				break;
			case SET_MODE:
				SET_BIT(TCCR2A,TCCR2A_COM2B0);
				SET_BIT(TCCR2A,TCCR2A_COM2B1);
				break;
			default:Locla_u8errorstate=NOK;



			}
		}
		else{
			Locla_u8errorstate=NOK;
		}
	}
	else {
		Locla_u8errorstate=NOK;
	}
	return Locla_u8errorstate;
}
u8 TIMER_u8choosefastorphasemode(u8 copy_u8timerno,u8 copy_channelno,u8 copy_u8mode){
	u8 Local_u8errorstate=OK;
	if(copy_u8timerno==TIMER0){
		if(copy_channelno==CHAN_A){
			switch(copy_u8mode){
			case NORMAL_MODE:
				CLEAR_BIT(TCCR0A,TCCR0A_COM0A0);
				CLEAR_BIT(TCCR0A,TCCR0A_COM0A1);
				break;
			case SECOND_MODE:
				SET_BIT(TCCR0A,TCCR0A_COM0A0);
				CLEAR_BIT(TCCR0A,TCCR0A_COM0A1);
				break;
			case NONINVERTING_MODE:
				CLEAR_BIT(TCCR0A,TCCR0A_COM0A0);
				SET_BIT(TCCR0A,TCCR0A_COM0A1);
				break;
			case INVERTING_MODE:
				SET_BIT(TCCR0A,TCCR0A_COM0A0);
				SET_BIT(TCCR0A,TCCR0A_COM0A1);
				break;
			default: Local_u8errorstate=NOK;

			}
		}
		else if(copy_channelno==CHAN_B){
			switch(copy_u8mode){
			case NORMAL_MODE:
				CLEAR_BIT(TCCR0A,TCCR0A_COM0B0);
				CLEAR_BIT(TCCR0A,TCCR0A_COM0B1);
				break;
			case NONINVERTING_MODE:
				CLEAR_BIT(TCCR0A,TCCR0A_COM0B0);
				SET_BIT(TCCR0A,TCCR0A_COM0B1);
				break;
			case INVERTING_MODE:
				SET_BIT(TCCR0A,TCCR0A_COM0B0);
				SET_BIT(TCCR0A,TCCR0A_COM0B1);
				break;
			default:Local_u8errorstate=NOK;


			}
		}
		else{
			Local_u8errorstate=NOK;
		}
	}
	else if(copy_u8timerno==TIMER1){
		if(copy_channelno==CHAN_A){
			switch(copy_u8mode){
			case NORMAL_MODE:
				CLEAR_BIT(TCCR1A,TCCR1A_COM1A0);
				CLEAR_BIT(TCCR1A,TCCR1A_COM1A1);
				break;
			case SECOND_MODE:
				SET_BIT(TCCR1A,TCCR1A_COM1A0);
				CLEAR_BIT(TCCR1A,TCCR1A_COM1A1);
				break;
			case NONINVERTING_MODE:
				CLEAR_BIT(TCCR1A,TCCR1A_COM1A0);
				SET_BIT(TCCR1A,TCCR1A_COM1A1);
				break;
			case INVERTING_MODE:
				SET_BIT(TCCR1A,TCCR1A_COM1A0);
				SET_BIT(TCCR1A,TCCR1A_COM1A1);
				break;
			default:Local_u8errorstate=NOK;

			}
		}
		else if (copy_channelno==CHAN_B){
			switch(copy_u8mode){
			case NORMAL_MODE:
				CLEAR_BIT(TCCR1A,TCCR1A_COM1B0);
				CLEAR_BIT(TCCR1A,TCCR1A_COM1B1);
				break;
			case NONINVERTING_MODE:
				CLEAR_BIT(TCCR1A,TCCR1A_COM1B0);
				SET_BIT(TCCR1A,TCCR1A_COM1B1);
				break;
			case INVERTING_MODE:
				SET_BIT(TCCR1A,TCCR1A_COM1B0);
				SET_BIT(TCCR1A,TCCR1A_COM1B1);
				break;
			default:Local_u8errorstate=NOK;
			}
		}
		else{
			Local_u8errorstate=NOK;
		}
	}
	else if(copy_u8timerno==TIMER2){
		if(copy_channelno==CHAN_A){
			switch(copy_u8mode){
			case NORMAL_MODE:
				CLEAR_BIT(TCCR2A,TCCR2A_COM2A0);
				CLEAR_BIT(TCCR2A,TCCR2A_COM2A1);
				break;
			case SECOND_MODE:
				SET_BIT(TCCR2A,TCCR2A_COM2A0);
				CLEAR_BIT(TCCR2A,TCCR2A_COM2A1);
				break;
			case NONINVERTING_MODE:
				CLEAR_BIT(TCCR2A,TCCR2A_COM2A0);
				SET_BIT(TCCR2A,TCCR2A_COM2A1);
				break;
			case INVERTING_MODE:
				SET_BIT(TCCR2A,TCCR2A_COM2A0);
				SET_BIT(TCCR2A,TCCR2A_COM2A1);
				break;
			default:Local_u8errorstate=NOK;
			}
		}
		else if(copy_channelno==CHAN_B){
			switch(copy_u8mode){
			case NORMAL_MODE:
				CLEAR_BIT(TCCR2A,TCCR2A_COM2B0);
				CLEAR_BIT(TCCR2A,TCCR2A_COM2B1);
				break;
			case NONINVERTING_MODE:
				CLEAR_BIT(TCCR2A,TCCR2A_COM2B0);
				SET_BIT(TCCR2A,TCCR2A_COM2B1);
				break;
			case INVERTING_MODE:
				SET_BIT(TCCR2A,TCCR2A_COM2B0);
				SET_BIT(TCCR2A,TCCR2A_COM2B1);
				break;
			default:Local_u8errorstate=NOK;

			}
		}
		else{
			Local_u8errorstate=NOK;
		}
	}
	else{
		Local_u8errorstate=NOK;
	}
	return Local_u8errorstate;

}
u8 TIMER_u8setprescaler(u8 copy_u8timerno,u8 copy_u8prescale){
	u8 Local_u8errorstate=OK;
	if(copy_u8timerno==TIMER0){
		TCCR0B&=CLEAR_MASK;
		TCCR0B|=copy_u8prescale;
	}
	else if (copy_u8timerno==TIMER1){
		TCCR1B&=CLEAR_MASK;
		TCCR1B|=copy_u8prescale;
	}
	else if(copy_u8timerno==TIMER2){
		TCCR2B&=CLEAR_MASK;
		TCCR2B|=copy_u8prescale;
	}
	else{
		Local_u8errorstate=NOK;
	}
	return Local_u8errorstate;
}
u8 TIMER_u8setoverflowcallback(u8 copy_u8timerno,void(* copy_pvfunc)(void)){
	u8 Local_u8errorstate=OK;
	if(copy_pvfunc==NULL){
		Local_u8errorstate=NOK;
	}
	else{
		if(copy_u8timerno==TIMER0){
			TIMER0_pvcallbackfunc=copy_pvfunc;
		}
		else if(copy_u8timerno==TIMER1){
			TIMER1_pvcallbackfunc=copy_pvfunc;
		}
		else if(copy_u8timerno==TIMER2){
			TIMER2_pvcallbackfunc=copy_pvfunc;
		}
		else {
			Local_u8errorstate=NOK;
		}
	}
	return Local_u8errorstate;
}
u8 TIMER_u8setcompmatchcallback(u8 copy_u8timerno,void(* copy_pvfunc)(void),u8 copy_u8channel){
	u8 Local_u8errorstate=OK;
	if(copy_pvfunc==NULL){
		Local_u8errorstate=NOK;
	}
	else{
		if(copy_u8timerno==TIMER0){
			if(copy_u8channel==CHAN_A){
				TIMER0_pvcallbackcompfuncA=copy_pvfunc;
			}
			else if(copy_u8channel==CHAN_B){
				TIMER0_pvcallbackcompfuncB=copy_pvfunc;

			}
			else {
				Local_u8errorstate=NOK;
			}

		}
		else if(copy_u8timerno==TIMER1){
			if(copy_u8channel==CHAN_A){
				TIMER1_pvcallbackcompfuncA=copy_pvfunc;
			}
			else if(copy_u8channel==CHAN_B){
				TIMER1_pvcallbackcompfuncB=copy_pvfunc;

			}
			else {
				Local_u8errorstate=NOK;
			}

		}
		else if(copy_u8timerno==TIMER2){
			if(copy_u8channel==CHAN_A){
				TIMER2_pvcallbackcompfuncA=copy_pvfunc;
			}
			else if(copy_u8channel==CHAN_B){
				TIMER2_pvcallbackcompfuncB=copy_pvfunc;

			}
			else {
				Local_u8errorstate=NOK;
			}


		}
		else {
			Local_u8errorstate=NOK;
		}
	}
	return Local_u8errorstate;
}
u8 TIMER_u8settimervalue(u8 copy_u8timerno,u8 copy_u8rimervalue){
	u8 Local_u8errorstate=OK;
	if(copy_u8timerno==TIMER0){
		TCNT0=copy_u8rimervalue;
	}
	else if(copy_u8timerno==TIMER2){
		TCNT2=copy_u8rimervalue;
	}
	else{
		Local_u8errorstate=NOK;
	}
	return Local_u8errorstate;
}
void TIMER1_u8settimervalue(u16 copy_u16rimervalue){
	TCNT1=copy_u16rimervalue;
}
u8 TIMER_u8getimervalue(u8 copy_u8timerno,u16* copy_pu8rimervalue){
	u8 Local_u8errorstate=OK;
	if(copy_pu8rimervalue==NULL){
		Local_u8errorstate=NOK;
	}
	else{
		if(copy_u8timerno==TIMER0){
			*copy_pu8rimervalue=TCNT0;
	}
		else if(copy_u8timerno==TIMER1){
			*copy_pu8rimervalue=TCNT1;
		}
		else if(copy_u8timerno==TIMER2){
			*copy_pu8rimervalue=TCNT2;
		}
	}


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
}

void __vector_16 (void)__attribute__((signal));
void __vector_16 (void){
	if(TIMER0_pvcallbackfunc!=NULL){
		TIMER0_pvcallbackfunc();
	}
}
void __vector_13 (void)__attribute__((signal));
void __vector_13 (void){
	if(TIMER1_pvcallbackfunc!=NULL){
		TIMER1_pvcallbackfunc();
	}
}
void __vector_9 (void)__attribute__((signal));
void __vector_9 (void){
	if(TIMER2_pvcallbackfunc!=NULL){
		TIMER2_pvcallbackfunc();
	}
}
void __vector_14 (void)__attribute__((signal));
void __vector_14 (void){
	if(TIMER0_pvcallbackcompfuncA!=NULL){
		TIMER0_pvcallbackcompfuncA();
	}
}
void __vector_15 (void)__attribute__((signal));
void __vector_15 (void){
	if(TIMER0_pvcallbackcompfuncB!=NULL){
		TIMER0_pvcallbackcompfuncB();
	}
}
void __vector_11 (void)__attribute__((signal));
void __vector_11 (void){
	if(TIMER1_pvcallbackcompfuncA!=NULL){
		TIMER1_pvcallbackcompfuncA();
	}
}
void __vector_12 (void)__attribute__((signal));
void __vector_12 (void){
	if(TIMER1_pvcallbackcompfuncB!=NULL){
		TIMER1_pvcallbackcompfuncB();
	}
}
void __vector_7 (void)__attribute__((signal));
void __vector_7 (void){
	if(TIMER2_pvcallbackcompfuncA!=NULL){
		TIMER2_pvcallbackcompfuncA();
	}
}
void __vector_8 (void)__attribute__((signal));
void __vector_8 (void){
	if(TIMER2_pvcallbackcompfuncB!=NULL){
		TIMER2_pvcallbackcompfuncB();
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


