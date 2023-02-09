/************************************************************************************/
/************************************************************************************/
/**********************      AUTHOR: AHMED MOKHTAR       ****************************/
/**********************      LAYER: MCAL                 ****************************/
/**********************      SWC:ADC                     ****************************/
/**********************      VERSION: 1.00               ****************************/
/************************************************************************************/
/************************************************************************************/
#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"ADC_config.h"
#include"ADC_interface.h"
#include"ADC_private.h"
#include"ADC_register.h"
static u8* ADC_pu8reading=NULL;
static void(*ADC_pvcallbacknotificationfunc)(void)=NULL;
u8 ADC_u8busystate=IDLE;
static u8* ADC_pu8channelarr=NULL;
static u8 ADC_u8chainsize;
static u16* ADC_PU16resultarr=NULL;
static void (*ADC_u8pvnotificationfunc)(void)=NULL;
static u8 ADC_u8channelindex=0;






void ADC_voidintit(void){
	/*reference selection */
#if REFERENCE_SELECTION==AREF
	CLEAR_BIT(ADMUX,ADMUX_REFS0);
	CLEAR_BIT(ADMUX,ADMUX_REFS1);
#elif REFERENCE_SELECTION==AVCC
	SET_BIT(ADMUX,ADMUX_REFS0);
	CLEAR_BIT(ADMUX,ADMUX_REFS1);
#elif REFERENCE_SELECTION==INTERNAL_VOLTAGE
	SET_BIT(ADMUX,ADMUX_REFS0);
	SET_BIT(ADMUX,ADMUX_REFS1);

#else
#error"wrong REFERENCE SELECTION INPUT"
#endif
	/*result adjust selection*/
#if ADJUST_RESULT==LEFT_ADJUST
	SET_BIT(ADMUX,ADMUX_ADLAR);
#elif ADJUST_RESULT==RIGHT_ADJUST
	CLEAR_BIT(ADMUX,ADMUX_ADLAR);
#else
#error"wrong ADJUST_RESULT input"
#endif
	/*set prescaler option*/
	CLEAR_BIT(ADCSRA,ADCSRA_ADPS0);
	CLEAR_BIT(ADCSRA,ADCSRA_ADPS1);
	CLEAR_BIT(ADCSRA,ADCSRA_ADPS2);
	ADCSRA|=DIV_FACTOR;

	/*enable state selections*/
#if  ENABLE_STATE==ENABLED
	SET_BIT(ADCSRA,ADCSRA_ADEN);
#elif ENABLE_STATE==DISABLED
	CLEAR_BIT(ADCSRA,ADCSRA_ADEN);
#else
#error"wrong ENABLE_STATE selection"
#endif

}
u8 ADC_u8startconversionsynch(u8 copy_u8channel,u8* copy_pu8reading){
	u8 Local_u8statesrror=OK;
	if(ADC_u8busystate==IDLE){
		ADC_u8busystate=BUSY;
		u32 Local_u32counter=0;
		/*clear the mux bits in admux register*/
		ADMUX&=0b11110000;
		/*set the required channel into themux bits*/
		ADMUX|=copy_u8channel;
		/*start conversion */
		SET_BIT(ADCSRA,ADCSRA_ADCS);
		/*polling busy wating until the the conversion complete flag is set or counter reach timeout*/
		while((GET_BIT(ADCSRA,ADCSRA_ADIF)==0)&&(Local_u32counter!=ADC_u32TIMEOUT)){
			Local_u32counter++;
		}
		if(Local_u32counter==ADC_u32TIMEOUT){
			/*loop is broken because the timeout is reached*/
			Local_u8statesrror=NOK;
		}
		else{
			/*loop is broken because the flag is raised*/
			/*clear flag*/
			SET_BIT(ADCSRA,ADCSRA_ADIF);
			*copy_pu8reading=ADCH;
			ADC_u8busystate=IDLE;
		}
	}
	else{
		Local_u8statesrror=BUSY_FUNC;
	}
	return Local_u8statesrror;

}
u8 ADC_u8startconversionasynch(u8 copy_u8channel,u8* copy_pu8reading,void(*copy_u8pvnotificationfunc)(void)){
	u8 Local_u8errorstate=OK;

	if(ADC_u8busystate==IDLE){
		if(copy_pu8reading==NULL||copy_u8pvnotificationfunc==NULL){
			Local_u8errorstate=NULL_POINTER;
		}else{
			ADC_u8busystate=BUSY;
			/*set the global pointers to point to the address whic the use choose*/
			ADC_pu8reading=copy_pu8reading;
			ADC_pvcallbacknotificationfunc=copy_u8pvnotificationfunc;
			/*clear the mux bits in admux register*/
			ADMUX&=0b11110000;
			/*set the required channel into themux bits*/
			ADMUX|=copy_u8channel;
			/*start conversion */
			SET_BIT(ADCSRA,ADCSRA_ADCS);
			/*enable ADC interrupt enable*/
			SET_BIT(ADCSRA,ADCSRA_ADIE);
		}
	}
	else{
		Local_u8errorstate=BUSY_FUNC;
	}
	return Local_u8errorstate;
}

u8 ADC_u8startchainconversion( ADC_chainstruct* copy_structobject){
	u8 Local_u8errorstate=OK;
	if(copy_structobject==NULL){
		Local_u8errorstate=NULL_POINTER;
	}
	else{
		if(ADC_u8busystate==IDLE){
		ADC_u8busystate=BUSY;
		/*pass the struct variables to global variables to be used in ISR*/
		ADC_pu8channelarr=copy_structobject->channels;
		ADC_u8chainsize=copy_structobject->size;
		ADC_pvcallbacknotificationfunc=copy_structobject->notificationfunc;
		ADC_pu8channelarr=copy_structobject->result;
		ADC_u8channelindex=0;
		/*start the first conversion */
		/*set the first channel*/
		ADMUX&=0b11110000;
		ADMUX|=ADC_pu8channelarr[ADC_u8channelindex];
		/*start the first conversion*/
		SET_BIT(ADCSRA,ADCSRA_ADCS);
		/*enable ADC complete  interrupt*/
		SET_BIT(ADCSRA,ADCSRA_ADIE);
		}
		else{
			Local_u8errorstate=BUSY_FUNC;
		}
	}
	return Local_u8errorstate;



}












void __vector_16 (void) __attribute__((signal));
void __vector_16 (void){
	if(ADC_CONVERSIONTYPE==SINGLE){

		/*read the ADC result*/
		*ADC_pu8reading=ADCH;
		/*reset the ADC busy state */
		ADC_u8busystate=IDLE;
		/*callback notification function*/
		ADC_pvcallbacknotificationfunc();
		/*disable the ADC conversion interrupt*/
		CLEAR_BIT(ADCSRA,ADCSRA_ADIE);
	}
	else if(ADC_CONVERSIONTYPE==MULTI){
		/*save the value of the last conversion*/
		ADC_PU16resultarr[ADC_u8channelindex]=ADCH;
		ADC_u8channelindex++;
		if(ADC_u8channelindex<ADC_u8chainsize){
			/*start the new conversion*/
			ADMUX&=0b11110000;
			ADMUX|=ADC_pu8channelarr[ADC_u8channelindex];
			SET_BIT(ADCSRA,ADCSRA_ADCS);
		}
		else{
			ADC_u8busystate=IDLE;
			/*disable the interrupt*/
			SET_BIT(ADCSRA,ADCSRA_ADIE);
			/*notification function*/
			ADC_u8pvnotificationfunc();

		}

	}
	else{
		/*do nothing*/
	}
}

s32 MAPING_s32mapingvalue(s32 copy_s32min_input,s32 copy_s32max_input,
		s32 copy_s32min_output,s32 copy_s32max_output,s32 copy_s32input_value){
	s32 OUTPUT_s32vlaue;
	OUTPUT_s32vlaue=((copy_s32max_output-copy_s32min_output)/(copy_s32max_input-copy_s32min_input)*(copy_s32input_value-copy_s32min_input))-copy_s32min_output;
	return OUTPUT_s32vlaue;
}


