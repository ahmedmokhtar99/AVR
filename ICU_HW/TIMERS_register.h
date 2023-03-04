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
#define TCCR0A_WGM00     0                           /*waveform generation mode bit0*/
#define TCCR0A_WGM01     1                           /*waveform generation mode bit1*/
#define TCCR0A_COM0A0    6                           /*compare output mode bit0*/
#define TCCR0A_COM0A1    7                           /*compare output mode bit1*/

#define TCCR0B          *((volatile u8*)0x45)        /*timer 0 control register A*/
#define TCCR0B_CS00     0                            /*prescaler bit0*/
#define TCCR0B_CS01     1                            /*prescaler bit1*/
#define TCCR0B_CS02     2                            /*prescaler bit2*/

#define OCOR0A          *((volatile u8*)0x47)       /*output compare register 0A*/
#define OCOR0B          *((volatile u8*)0x48)       /*output compare register 0A*/



#define TIMSK0          *((volatile u8*)0x6E)      /*timer0 mask*/
#define TIMSK0_TOIE0    0                          /*overflow interrupt enable*/
#define TIMSK0_OCIE0A   1                          /*output compare interrupt enable*/



#define TCCR1A          *((volatile u8*)0x80)        /*timer 1 control register A*/
#define TCCR1A_WGM10     0                           /*waveform generation mode bit0*/
#define TCCR1A_WGM11     1                           /*waveform generation mode bit1*/
#define TCCR1A_COM1A0    6                           /*compare output mode bit0*/
#define TCCR1A_COM1A1    7                           /*compare output mode bit1*/

#define TCCR1B          *((volatile u8*)0x81)        /*timer 0 control register A*/
#define TCCR1B_CS10     0                            /*prescaler bit0*/
#define TCCR1B_CS11     1                            /*prescaler bit1*/
#define TCCR1B_CS12     2                            /*prescaler bit2*/
#define TCCR1B_WGM12    3                            /*waveform generation bit2*/
#define TCCR1B_WGM13    4                            /*waveform generation bit3*/
#define TCCR1B_ICES1    6                            /*input capture edge select*/
#define TCCR1B_ICNC1    7                            /*input capture noise cancel*/

#define TIMSK1           *((volatile u8*)0x6F)        /*timer 1 mask*/
#define TIMSK1_ICIE1      5                             /*input capture interrupt enable*/


#define ICR1L          *((volatile u16*)0x86)        /*low input capture register*/
#define OCOR1AL        *((volatile u16*)0x88)       /*output compare register 1A*/
#define TCNT1         *((volatile u16*)0x84)       /*the timer/counter 1 register*/




#endif










