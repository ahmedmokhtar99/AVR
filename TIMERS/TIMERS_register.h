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
#define TCCR0A_COM0B0    4
#define TCCR0A_COM0B1    5


#define TCCR0B          *((volatile u8*)0x45)        /*timer 0 control register A*/
#define TCCR0B_CS00     0                            /*prescaler bit0*/
#define TCCR0B_CS01     1                            /*prescaler bit1*/
#define TCCR0B_CS02     2                            /*prescaler bit2*/
#define TCCR0B_WGM02    3

#define OCOR0A          *((volatile u8*)0x47)       /*output compare register 0A*/
#define OCOR0B          *((volatile u8*)0x48)       /*output compare register 0A*/



#define TIMSK0          *((volatile u8*)0x6E)      /*timer mask*/
#define TIMSK0_TOIE0    0                          /*overflow interrupt enable*/
#define TIMSK0_OCIE0A   1                          /*output compare interrupt enable*/
#define TCNT0           *((volatile u8*)0x46)      /*the timer/counter 0 register*/



#define TIMSK1          *((volatile u8*)0x6F)      /*timer mask*/
#define TIMSK1_TOIE1    0                          /*overflow interrupt enable*/
#define TIMSK1_OCIE1A   1                          /*output compare interrupt enable*/




#define TCCR1A          *((volatile u8*)0x80)        /*timer 1 control register A*/
#define TCCR1A_WGM10     0                           /*waveform generation mode bit0*/
#define TCCR1A_WGM11     1                           /*waveform generation mode bit1*/
#define TCCR1A_COM1A0    6                           /*compare output mode bit0*/
#define TCCR1A_COM1A1    7                           /*compare output mode bit1*/
#define TCCR1A_COM1B0    4
#define TCCR1A_COM1B1    5



#define TCCR1B          *((volatile u8*)0x81)        /*timer 0 control register A*/
#define TCCR1B_CS10     0                            /*prescaler bit0*/
#define TCCR1B_CS11     1                            /*prescaler bit1*/
#define TCCR1B_CS12     2                            /*prescaler bit2*/
#define TCCR1B_WGM12    3                            /*waveform generation bit2*/
#define TCCR1B_WGM13    4                            /*waveform generation bit3*/

#define TCCR2A          *((volatile u8*)0xB0)        /*timer 0 control register A*/
#define TCCR2A_WGM20     0                           /*waveform generation mode bit0*/
#define TCCR2A_WGM21     1                           /*waveform generation mode bit1*/
#define TCCR2A_COM2A0    6                           /*compare output mode bit0*/
#define TCCR2A_COM2A1    7                           /*compare output mode bit1*/
#define TCCR2A_COM2B0    4
#define TCCR2A_COM2B1    5

#define TCCR2B          *((volatile u8*)0xB1)        /*timer 0 control register A*/
#define TCCR2B_CS20     0                            /*prescaler bit0*/
#define TCCR2B_CS21     1                            /*prescaler bit1*/
#define TCCR2B_CS22     2                            /*prescaler bit2*/
#define TCCR2B_WGM22    3

#define OCOR2A          *((volatile u8*)0xB3)       /*output compare register 0A*/
#define OCOR2B          *((volatile u8*)0xB4)       /*output compare register 0A*/



#define TIMSK2          *((volatile u8*)0x70)      /*timer mask*/
#define TIMSK2_TOIE2    0                          /*overflow interrupt enable*/
#define TIMSK2_OCIE2A   1                          /*output compare interrupt enable*/
#define TCNT2           *((volatile u8*)0xB2)      /*the timer/counter 2 register*/




#define ICR1L          *((volatile u16*)0x86)        /*low input capture register*/
#define OCOR1AL        *((volatile u16*)0x88)       /*output compare register 1A*/
#define TCNT1         *((volatile u16*)0x84)       /*the timer/counter 1 register*/




#endif










