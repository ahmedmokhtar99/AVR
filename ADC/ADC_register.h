/************************************************************************************/
/************************************************************************************/
/**********************      AUTHOR: AHMED MOKHTAR       ****************************/
/**********************      LAYER: MCAL                 ****************************/
/**********************      SWC:ADC                     ****************************/
/**********************      VERSION: 1.00               ****************************/
/************************************************************************************/
/************************************************************************************/
#ifndef ADC_REGISTER_H
#define ADC_REGISTER_H


#define ADMUX         *((volatile u8*)0x7C)   /*ADC multiplexer selection register*/
#define ADMUX_REFS1          7                /*reference selection bit1*/
#define ADMUX_REFS0          6                /*reference selection bit0*/
#define ADMUX_ADLAR          5                /*ADC left adjust result*/


#define ADCSRA       *((volatile u8*)0x7A)           /*ADC control and status register a*/

#define ADCSRA_ADEN       7                         /*ADC enable bit*/
#define ADCSRA_ADCS       6                         /*start conversion*/
#define ADCSRA_ADATE      5                         /*auto trigger enable*/
#define ADCSRA_ADIF       4                         /*interrupt flag*/
#define ADCSRA_ADIE       3                         /*interrupt enable*/
#define ADCSRA_ADPS2      2                         /*prescaler bit2*/
#define ADCSRA_ADPS1      1                         /*prescaler bit1*/
#define ADCSRA_ADPS0      0                         /*prescaler bit0*/






#define ADCH         *((volatile u8*)0x79)           /*ADC high register*/






#define ADCL         *((volatile u8*)0x78)             /*ADC low register*/





#endif
