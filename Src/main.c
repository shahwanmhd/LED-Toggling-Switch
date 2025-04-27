/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Shahwan Muhammad
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2025 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************

#include <stdint.h>
#include "main.h"

// Register base addresses as meaningful macros
#define RCC_AHB1ENR_ADDR   ((RCC_AHB1ENR_t *)0x40023830)
#define GPIOD_MODER_ADDR   ((GPIOX_MODER_t *)0x40020C00)
#define GPIOD_ODR_ADDR     ((GPIOX_ODR_t *)0x40020C14)
#define GPIOA_MODER_ADDR   ((GPIOX_MODER_t *)0x40020000)
#define GPIOA_IDR_ADDR     ((GPIOX_IDR_t *)0x40020010)
#define GPIOA_PUP_ADDR     ((GPIOX_PUP_t *)0x4002000C)

void delay(void)
{
    for (uint32_t i = 0; i < 300000; i++);
}

int main(void)
{
    // Enable clock for GPIOA and GPIOD
    RCC_AHB1ENR_t *rcc_en = RCC_AHB1ENR_ADDR;
    rcc_en->gpioa_en = 1;
    rcc_en->gpiod_en = 1;

    // Configure PA0 as input
    GPIOX_MODER_t *gpioa_moder = GPIOA_MODER_ADDR;
    gpioa_moder->pmode_0 = 0x0; // Input Mode

    // Enable internal Pull-down for PA0
    GPIOX_PUP_t *gpioa_pup = GPIOA_PUP_ADDR;
    gpioa_pup->pup_0 = 0x2; // Pull-Down

    // Configure PD13 and PD15 as output
    GPIOX_MODER_t *gpiod_moder = GPIOD_MODER_ADDR;
    gpiod_moder->pmode_13 = 0x1; // Output
    gpiod_moder->pmode_15 = 0x1; // Output

    GPIOX_ODR_t *gpiod_odr = GPIOD_ODR_ADDR;
    GPIOX_IDR_t *gpioa_idr = GPIOA_IDR_ADDR;

    while (1)
    {
        if (gpioa_idr->idr_0) // Button pressed (PA0 LOW)
        {
            gpiod_odr->odr_15 = 1; // Turn ON LED6 (PD15)
            delay();
            gpiod_odr->odr_15 = 0; // Turn OFF LED6
            delay();
        }
        else // Button released (PA0 HIGH)
        {
            gpiod_odr->odr_13 = 1; // Turn ON LED3 (PD13)
            delay();
            gpiod_odr->odr_13 = 0; // Turn OFF LED3
            delay();
        }
    }
}
