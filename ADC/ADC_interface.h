/************************************************************************************/
/************************************************************************************/
/**********************      AUTHOR: AHMED MOKHTAR       ****************************/
/**********************      LAYER: MCAL                 ****************************/
/**********************      SWC:ADC                     ****************************/
/**********************      VERSION: 1.00               ****************************/
/************************************************************************************/
/************************************************************************************/
#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H
void ADC_voidintit(void);
 typedef struct ADC_chainstruct{
	u8* channels;
	u8 size;
	u16* result;
	void (*notificationfunc)(void);
}ADC_chainstruct;


u8 ADC_u8startconversionsynch(u8 copy_u8channel,u8* copu_pu8reading);


s32 MAPING_s32mapingvalue(s32 copy_s32min_input,s32 copy_s32max_input,s32 copy_s32min_output,s32 copy_s32max_output,s32 copy_s32input_value);


u8 ADC_u8startconversionasynch(u8 copy_u8channel,u8* copy_pu8reading,void(*copy_u8pvnotificationfunc)(void));

u8 ADC_u8startchainconversion(ADC_chainstruct*copy_structobject);







/*voltage reference selection options*/
#define AREF      1
#define AVCC      2
#define INTERNAL_VOLTAGE  3
/*left adjust result*/
#define LEFT_ADJUST    1
#define RIGHT_ADJUST   2
/*division factor selection*/
#define DIV_BY_2     	0b00000000
#define DIV_BY_4     	0b00000010
#define DIV_BY_8     	0b00000011
#define DIV_BY_16     	0b00000100
#define DIV_BY_32    	0b00000101
#define DIV_BY_64    	0b00000110
#define DIV_BY_128     	0b00000111

/*ADC ENABLE STATE*/
#define ENABLED     1
#define DISABLED    2
/*ADC MODE STATE*/

#define SINGLE      1
#define MULTI       2











#endif
