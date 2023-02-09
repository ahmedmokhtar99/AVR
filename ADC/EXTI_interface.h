/************************************************************************************/
/************************************************************************************/
/**********************      AUTHOR: AHMED MOKHTAR       ****************************/
/**********************      LAYER: MCAL                 ****************************/
/**********************      SWC:EXTI                    ****************************/
/**********************      VERSION: 1.00               ****************************/
/************************************************************************************/
/************************************************************************************/
#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_
void EXTI_voidint0init(void);
void EXTI_voidint1init(void);
/*DESCRIPTION : A function to set the sense of control of INT0 using postbuild configuration
 * input: copy_u8sense options are :
 *                                    1-LOW_LEVEL
  	  	  	  	  	  	  	  	  	  2-ON_CHANGE
  	  	  	  	  	  	  	  	  	  3-FALLING_EDGE
  									  4-RISING_EDGE

 * outputs: error states :
 *                        1-OK
 *                        2-NOK
 */
u8 EXTI_u8intset_sensecontrol(u8 copy_u8int,u8 copy_u8sense);

/*DESCRIPTION :A function to set the interrupt enable or disable
 * input :copy_u8int options are:
 *                                 1-INT0
 *                                 2-INT1
 *        :copy_u8intcontrol:
 *                                 1-ENABLED
 *                                 2-DISABLED
 *  output:error states:
 *                                 1-OK
 *                                 2-NOK
 */
u8 EXTI_u8intcontrol(u8 copy_u8int,u8 copy_u8intcontrol);
/*DISCRIPTION :A function to pass the address of the ISR function
 * inputs: copy_u8int options are:
 *                                 1-INT0
 *                                 2-INT1
 *        :copy_pvintfunc:address of the ISR function
 * output :error states:
 *                                 1-OK
 *                                 2-NOK
 */

u8 EXTI_u8intset_callback(void (*copy_pvintfunc)(void),u8 copy_u8int);











#define INT0           1
#define INT1           2

#define LOW_LEVEL      1
#define ON_CHANGE      2
#define FALLING_EDGE   3
#define RISING_EDGE    4

#define ENABLED        1
#define DISABLED       2
#endif
