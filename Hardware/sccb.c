/*
 * @Author: 星必尘Sguan
 * @Date: 2025-06-04 15:40:57
 * @LastEditors: 星必尘Sguan|3464647102@qq.com
 * @LastEditTime: 2025-06-04 19:37:10
 * @FilePath: \demo_STM32H750code\Hardware\sccb.c
 * @Description: sccb总线读写函数
 * 
 * Copyright (c) 2025 by $JUST, All Rights Reserved. 
 */
#include "sccb.h"
#include "main.h"  // 确保包含hi2c1的声明


/************************************ 8位地址寄存器操作（OV2640） ************************************/
uint8_t SCCB_WriteReg(uint8_t addr, uint8_t value) {
    uint8_t data[2] = {addr, value};
    if (HAL_I2C_Master_Transmit(&hi2c1, OV2640_DEVICE_ADDRESS << 1, data, 2, HAL_MAX_DELAY) != HAL_OK) {
        return ACK_ERR;
    }
    return ACK_OK;
}

uint8_t SCCB_ReadReg(uint8_t addr) {
    uint8_t value = 0;
    // 先发送寄存器地址
    if (HAL_I2C_Master_Transmit(&hi2c1, OV2640_DEVICE_ADDRESS << 1, &addr, 1, HAL_MAX_DELAY) != HAL_OK) {
        return 0xFF; // 错误值
    }
    // 再读取数据
    if (HAL_I2C_Master_Receive(&hi2c1, (OV2640_DEVICE_ADDRESS << 1) | 0x01, &value, 1, HAL_MAX_DELAY) != HAL_OK) {
        return 0xFF;
    }
    return value;
}

/************************************ 16位地址寄存器操作（OV5640） ************************************/
uint8_t SCCB_WriteReg_16Bit(uint16_t addr, uint8_t value) {
    uint8_t data[3] = {addr >> 8, addr & 0xFF, value};
    if (HAL_I2C_Master_Transmit(&hi2c1, OV5640_DEVICE_ADDRESS << 1, data, 3, HAL_MAX_DELAY) != HAL_OK) {
        return ACK_ERR;
    }
    return ACK_OK;
}

uint8_t SCCB_ReadReg_16Bit(uint16_t addr) {
    uint8_t value = 0;
    uint8_t addr_bytes[2] = {addr >> 8, addr & 0xFF};
    // 先发送寄存器地址（16位）
    if (HAL_I2C_Master_Transmit(&hi2c1, OV5640_DEVICE_ADDRESS << 1, addr_bytes, 2, HAL_MAX_DELAY) != HAL_OK) {
        return 0xFF;
    }
    // 再读取数据
    if (HAL_I2C_Master_Receive(&hi2c1, (OV5640_DEVICE_ADDRESS << 1) | 0x01, &value, 1, HAL_MAX_DELAY) != HAL_OK) {
        return 0xFF;
    }
    return value;
}

uint8_t SCCB_WriteBuffer_16Bit(uint16_t addr, uint8_t *pData, uint32_t size) {
    uint8_t addr_bytes[2] = {addr >> 8, addr & 0xFF};
    // 先发送寄存器地址（16位）
    if (HAL_I2C_Master_Transmit(&hi2c1, OV5640_DEVICE_ADDRESS << 1, addr_bytes, 2, HAL_MAX_DELAY) != HAL_OK) {
        return ACK_ERR;
    }
    // 再写入数据
    if (HAL_I2C_Master_Transmit(&hi2c1, OV5640_DEVICE_ADDRESS << 1, pData, size, HAL_MAX_DELAY) != HAL_OK) {
        return ACK_ERR;
    }
    return ACK_OK;
}
