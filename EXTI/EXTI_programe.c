/************************************************************************************/
/************************************************************************************/
/**********************      AUTHOR: AHMED MOKHTAR       ****************************/
/**********************      LAYER: MCAL                 ****************************/
/**********************      SWC:EXTI                    ****************************/
/**********************      VERSION: 1.00               ****************************/
/************************************************************************************/
/************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "EXTI_interface.h"
#include "EXTI_config.h"
#include "EXTI_private.h"
#include "EXTI_register.h"
void(*EXTI_pvint0Func)(void)=NULL;
void(*EXTI_pvint1Func)(void)=NULL;



void EXTI_voidint0init(void){
 /*set INT0 sense */
#if INT0_SENSE == LOW_LEVEL
	CLEAR_BIT(MCUCR,MCUCR_ISC00);
	CLEAR_BIT(MCUCR,MCUCR_ISC01);
#elif INT0_SENSE==ON_CHANGE
	SET_BIT(MCUCR,MCUCR_ISC00);
	CLEAR_BIT(MCUCR,MCUCR_ISC01);
#elif INT0_SENSE==FALLING_EDGE
	CLEAR_BIT(MCUCR,MCUCR_ISC00);
	SET_BIT(MCUCR,MCUCR_ISC01);
#elif INT0_SENSE==RISING_EDGE
	SET_BIT(MCUCR,MCUCR_ISC00);
	SET_BIT(MCUCR,MCUCR_ISC01);
#else
#error "wrong INT0_SENSE configuration input"
#endif
/*set INT0 enable*/
#if INT0_ENABLE_STATE==ENABLED
SET_BIT(GICR,GICR_INT0);
#elif INT0_ENABLE_STATE==DISABLED
CLEAR_BIT(GICR,GICR_INT0);
#else
#error "wrong INT0_ENABLE_STATE configuration input"
#endif
}
void EXTI_voidint1init(void){
	/*set INT1 sense */
	#if INT1_SENSE == LOW_LEVEL
		CLEAR_BIT(MCUCR,MCUCR_ISC10);
		CLEAR_BIT(MCUCR,MCUCR_ISC11);
	#elif INT1_SENSE==ON_CHANGE
		SET_BIT(MCUCR,MCUCR_ISC10);
		CLEAR_BIT(MCUCR,MCUCR_ISC11);
	#elif INT1_SENSE==FALLING_EDGE
		CLEAR_BIT(MCUCR,MCUCR_ISC10);
		SET_BIT(MCUCR,MCUCR_ISC11);
	#elif INT1_SENSE==RISING_EDGE
		SET_BIT(MCUCR,MCUCR_ISC10);
		SET_BIT(MCUCR,MCUCR_ISC11);
	#else
	#error "wrong INT1_SENSE configuration input"
	#endif
	/*set INT1 enable*/
	#if INT1_ENABLE_STATE==ENABLED
	SET_BIT(GICR,GICR_INT1);
	#elif INT1_ENABLE_STATE==DISABLED
	CLEAR_BIT(GICR,GICR_INT1);
	#else
	#error "wrong INT1_ENABLE_STATE configuration input"
	#endif

}
u8 EXTI_u8intset_sensecontrol(u8 copy_u8int,u8 copy_u8sense){
	u8 Local_u8stateerror=OK;
	/*check the interrupt pin*/
	if(copy_u8int==INT0){
		/*set the interrupt sense*/
		switch(copy_u8sense){
		case LOW_LEVEL:CLEAR_BIT(MCUCR,MCUCR_ISC00); CLEAR_BIT(MCUCR,MCUCR_ISC01);break;
		case ON_CHANGE:SET_BIT(MCUCR,MCUCR_ISC00); CLEAR_BIT(MCUCR,MCUCR_ISC01);break;
		case FALLING_EDGE:CLEAR_BIT(MCUCR,MCUCR_ISC00); SET_BIT(MCUCR,MCUCR_ISC01);break;
		case RISING_EDGE:SET_BIT(MCUCR,MCUCR_ISC00); SET_BIT(MCUCR,MCUCR_ISC01);break;
		default:Local_u8stateerror=NOK;
		}}
	else if(copy_u8int==INT1){
		switch(copy_u8sense){
			case LOW_LEVEL:CLEAR_BIT(MCUCR,MCUCR_ISC10); CLEAR_BIT(MCUCR,MCUCR_ISC11);break;
			case ON_CHANGE:SET_BIT(MCUCR,MCUCR_ISC10); CLEAR_BIT(MCUCR,MCUCR_ISC11);break;
			case FALLING_EDGE:CLEAR_BIT(MCUCR,MCUCR_ISC10); SET_BIT(MCUCR,MCUCR_ISC11);break;
			case RISING_EDGE:SET_BIT(MCUCR,MCUCR_ISC10); SET_BIT(MCUCR,MCUCR_ISC11);break;
			default:Local_u8stateerror=NOK;

	}

	}
	else{
		Local_u8stateerror=NOK;
	}
	return Local_u8stateerror;
}
u8 EXTI_u8intcontrol(u8 copy_u8int,u8 copy_u8intcontrol)
{
	u8 Local_u8stateerror=OK;
	if(copy_u8int==INT0){
		/*check the interrupt enable state*/
		if(copy_u8intcontrol==ENABLED){
		SET_BIT(GICR,GICR_INT0);
		}
		else if(copy_u8intcontrol==DISABLED){
			CLEAR_BIT(GICR,GICR_INT0);
		}
		else{
			Local_u8stateerror=NOK;
		}}
    else if(copy_u8int==INT1){
    	if(copy_u8intcontrol==ENABLED){
    			SET_BIT(GICR,GICR_INT0);
    			}
    			else if(copy_u8intcontrol==DISABLED){
    				CLEAR_BIT(GICR,GICR_INT0);
    			}
    			else{
    				Local_u8stateerror=NOK;
    			}

    }
    else {
    	Local_u8stateerror=NOK;
    }
	return Local_u8stateerror;
	}
u8 EXTI_u8intset_callback(void (*copy_pvintfunc)(void),u8 copy_u8int){
	u8 Locla_u8stateerror=OK;
	if (copy_u8int==INT0){
		if(copy_pvintfunc!=NULL){
			EXTI_pvint0Func=copy_pvintfunc;
		}
		else{
			Locla_u8stateerror=NULL_POINTER;
		}
	}
	else if(copy_u8int==INT1){
		if(copy_pvintfunc!=NULL){
		EXTI_pvint1Func=copy_pvintfunc;
		}
		else{
			Locla_u8stateerror=NULL_POINTER;
		}
	}
	else{
		Locla_u8stateerror=NOK;
	}
}
void __vector_1(void) __attribute__((signal));
void __vector_1(void){
	if(EXTI_pvint0Func!=NULL){
		EXTI_pvint0Func();
	}
	else{
		/*do nothing*/
	}
}
void __vector_2(void) __attribute__((signal));
void __vector_2(void){
	if(EXTI_pvint1Func!=NULL){
		EXTI_pvint1Func();
	}
	else{
		/*do nothing*/
	}
}









