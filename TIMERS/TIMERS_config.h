/************************************************************************************/
/************************************************************************************/
/**********************      AUTHOR: AHMED MOKHTAR       ****************************/
/**********************      LAYER: MCAL                 ****************************/
/**********************      SWC:TIMERS                  ****************************/
/**********************      VERSION: 1.00               ****************************/
/************************************************************************************/
/************************************************************************************/
#ifndef TIMERS_CONFIG_H
#define TIMERS_CONFIG_H

#define MAPING_STATE                REVERSED

#define TIMER0_MODE                 NORMAL_MODE
#define NORMAL_MODE                     1
#define COMPAREMATCH_MODE      			2
#define FASTPWM_NORMALMDOE   		 	3
#define FASTPWM_OCMODE        			4
#define PHASECORRECTPWM_NORMALMODE     	5
#define PHASECORRECTPWM_OCMODE         	6


#define TIMER1_MODE         		NORMAL_MODE
#define COMPAREMATCH_MODEOC             7
#define COMPAREMATCH_MODEIC             8
#define FASTPWM_NORMAL8BITMODE          9
#define FASTPWM_NORMAL9BITMODE          10
#define FASTPWM_NORMAL10BITMODE         11
#define FASTPWM_ICMODE                  13
#define PHASECORRECTPWM_NORMAL8BITMODE  14
#define PHASECORRECTPWM_NORMAL9BITMODE  15
#define PHASECORRECTPWM_NORMAL10BITMODE 16
#define PHASECORRECTPWM_ICMODE			17

#define COMP_MODE                       TOOGLE_MODE
#define TOOGLE_MODE     				2
#define CLEAR_MODE						3
#define SET_MODE						4

#define FASTORPHASEPWM_MODE             NORMAL_MODE
#define SECOND_MODE                     2
#define NONINVERTING_MODE				3
#define INVERTING_MODE					4

#define PRESCALE_MODE                  SHUTDOWN_MODE
#define SHUTDOWN_MODE    				0
#define NOPRESCALE_MODE 				1
#define PRESCALE8_MODE            		2
#define PRESCALE64_MODE					3
#define PRESCALE256_MODE				4
#define PRESCALE1024_MODE				5
#define EXTCLMFALLING_MODE              6
#define EXTCLMRISISNG_MODE				7

#define TIMER2_MODE                 NORMAL_MODE

#define TIMER0_COMPINT 				ENABLE
#define TIMER0_OVINT                ENABLE
#define TIMER1_COMPINT 				ENABLE
#define TIMER1_OVINT                ENABLE
#define TIMER2_COMPINT 				ENABLE
#define TIMER2_OVINT                ENABLE

#define ENABLE              			1
#define DISABLE							2

#endif
