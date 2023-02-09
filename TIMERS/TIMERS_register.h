/************************************************************************************/
/************************************************************************************/
/**********************      AUTHOR: AHMED MOKHTAR       ****************************/
/**********************      LAYER: MCAL                 ****************************/
/**********************      SWC:TIMERS                  ****************************/
/**********************      VERSION: 1.00               ****************************/
/************************************************************************************/
/************************************************************************************/
#ifndef TIMERS_REGISTER_H
#define TIMERS_REGISTER_H

#define TCCR0A          *((volatile u8*)0x44)        /*timer 0 control register A*/
#define TCCR0A_WGM00     0                           /*wavefoem generation mode bit0*/
#define TCCR0A_WGM01     1                           /*wavefoem generation mode bit0*/

#define TCCR0B          *((volatile u8*)0x45)        /*timer 0 control register A*/
#define TCCR0B_CS00     0                            /*prescaler bit0*/
#define TCCR0B_CS01     1                            /*prescaler bit1*/
#define TCCR0B_CS02     2                            /*prescaler bit2*/

#define OCOR0A          *((volatile u8*)0x47)       /*output compare register 0A*/
#define OCOR0B          *((volatile u8*)0x48)       /*output compare register 0A*/



#define TIMSK0          *((volatile u8*)0x6E)      /*timer mask*/
#define TIMSK0_TOIE0    0                          /*overflow interrupt enable*/
#define TIMSK0_OCIE0A   1                          /*output compare interrupt enable*/
#endif










