/************************************************************************************/
/************************************************************************************/
/**********************      AUTHOR: AHMED MOKHTAR       ****************************/
/**********************      LAYER: MCAL                 ****************************/
/**********************      SWC:SPI                     ****************************/
/**********************      VERSION: 1.00               ****************************/
/************************************************************************************/
/************************************************************************************/
#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H
void SPI_VoidMasterInit(void);
void SPI_VoidSlaveInit(void);
u8 SPI_u8Transceive(u8 Copy_u8SentData,u8* Copy_Pu8ReceviedData );






#endif
