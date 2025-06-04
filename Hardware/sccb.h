#ifndef __CAMERA_SCCB_H
#define __CAMERA_SCCB_H

#include "stm32h7xx_hal.h"

// 设备地址（硬件I2C模式下，地址需左移1位）
#define OV2640_DEVICE_ADDRESS     0x60    // OV2640地址（实际写入I2C时：0x60 << 1 = 0xC0）
#define OV5640_DEVICE_ADDRESS     0x78    // OV5640地址（实际写入I2C时：0x78 << 1 = 0xF0）

// 硬件I2C句柄（需在外部声明，如extern I2C_HandleTypeDef hi2c1）
extern I2C_HandleTypeDef hi2c1;

/*------------------------------------------ IIC相关定义 -------------------------------------------------*/
#define ACK_OK      1   // 响应正常
#define ACK_ERR     0   // 响应错误

/*--------------------------------------------- 函数声明 -------------------------------------------------*/  
uint8_t SCCB_WriteReg(uint8_t addr, uint8_t value);       // 8位地址写数据（OV2640）
uint8_t SCCB_ReadReg(uint8_t addr);                       // 8位地址读数据（OV2640）
uint8_t SCCB_WriteReg_16Bit(uint16_t addr, uint8_t value); // 16位地址写数据（OV5640）
uint8_t SCCB_ReadReg_16Bit(uint16_t addr);                // 16位地址读数据（OV5640）
uint8_t SCCB_WriteBuffer_16Bit(uint16_t addr, uint8_t *pData, uint32_t size); // 16位地址批量写

#endif //__CAMERA_SCCB_H
