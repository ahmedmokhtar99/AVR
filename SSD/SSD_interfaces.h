/************************************************************************************/
/************************************************************************************/
/**********************      AUTHOR: AHMED MOKHTAR       ****************************/
/**********************      LAYER: MCAL                 ****************************/
/**********************      SWC:SSD                     ****************************/
/**********************      VERSION: 1.00               ****************************/
/************************************************************************************/
/************************************************************************************/
#ifndef SSD_INTERFACE_H
#define SSD_INTERFACE_H

#define SSD_u8Com_Anode    1
#define SSD_u8Com_Cathode  0

#define SSD_u8Num_Zero      0
#define SSD_u8Num_One       1
#define SSD_u8Num_Two       2
#define SSD_u8Num_Three     3
#define SSD_u8Num_Four      4
#define SSD_u8Num_Five      5
#define SSD_u8Num_Six       6
#define SSD_u8Num_Seven     7
#define SSD_u8Num_Eight     8
#define SSD_u8Num_Nine      9







typedef struct {
	u8 SSD_u8Type;
	u8 SSD_u8Port;
	u8 SSD_u8Enb_Port;
	u8 SSD_u8Enb_Pin;

}SSD_Struct;

u8 SSD_u8Turn_On(SSD_Struct* SSD_Inf,u8 SSD_u8Number);
u8 SSD_u8Turn_Off(SSD_Struct* SSD_Inf);









#endif
