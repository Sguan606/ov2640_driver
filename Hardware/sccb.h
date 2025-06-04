#ifndef __CAMERA_SCCB_H
#define __CAMERA_SCCB_H

#include "stm32h7xx_hal.h"

// �豸��ַ��Ӳ��I2Cģʽ�£���ַ������1λ��
#define OV2640_DEVICE_ADDRESS     0x60    // OV2640��ַ��ʵ��д��I2Cʱ��0x60 << 1 = 0xC0��
#define OV5640_DEVICE_ADDRESS     0x78    // OV5640��ַ��ʵ��д��I2Cʱ��0x78 << 1 = 0xF0��

// Ӳ��I2C����������ⲿ��������extern I2C_HandleTypeDef hi2c1��
extern I2C_HandleTypeDef hi2c1;

/*------------------------------------------ IIC��ض��� -------------------------------------------------*/
#define ACK_OK      1   // ��Ӧ����
#define ACK_ERR     0   // ��Ӧ����

/*--------------------------------------------- �������� -------------------------------------------------*/  
uint8_t SCCB_WriteReg(uint8_t addr, uint8_t value);       // 8λ��ַд���ݣ�OV2640��
uint8_t SCCB_ReadReg(uint8_t addr);                       // 8λ��ַ�����ݣ�OV2640��
uint8_t SCCB_WriteReg_16Bit(uint16_t addr, uint8_t value); // 16λ��ַд���ݣ�OV5640��
uint8_t SCCB_ReadReg_16Bit(uint16_t addr);                // 16λ��ַ�����ݣ�OV5640��
uint8_t SCCB_WriteBuffer_16Bit(uint16_t addr, uint8_t *pData, uint32_t size); // 16λ��ַ����д

#endif //__CAMERA_SCCB_H
