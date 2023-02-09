/************************************************************************************/
/************************************************************************************/
/**********************      AUTHOR: AHMED MOKHTAR       ****************************/
/**********************      LAYER: HAL                  ****************************/
/**********************      SWC:KPD                     ****************************/
/**********************      VERSION: 1.00               ****************************/
/************************************************************************************/
/************************************************************************************/
#ifndef KPD_CONFIG_H
#define KPD_CONFIG_H
#define KPD_PORT               DIO_u8PORTD
#define KPD_NO_PREASED_KEY     0xff
#define kPD_ARR_VALL              {{1,2,3},{4,5,6},{7,8,9},{-6,0,10}}


#define KPD_COULMN0_PIN           DIO_u8PIN0
#define KPD_COULMN1_PIN           DIO_u8PIN1
#define KPD_COULMN2_PIN           DIO_u8PIN2

#define KPD_ROW0_PIN              DIO_u8PIN3
#define KPD_ROW1_PIN              DIO_u8PIN4
#define KPD_ROW2_PIN              DIO_u8PIN5
#define KPD_ROW3_PIN              DIO_u8PIN6


#endif
