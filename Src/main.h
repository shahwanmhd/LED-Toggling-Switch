/*
 * main.h
 *
 *  Created on: Mar 23, 2025
 *      Author: Shahwan
 */

#ifndef MAIN_H_
#define MAIN_H_
#include <stdint.h>
typedef struct{
	uint32_t gpioa_en		:1;
	uint32_t gpiob_en		:1;
	uint32_t gpioc_en		:1;
	uint32_t gpiod_en		:1;
	uint32_t gpioe_en		:1;
	uint32_t gpiof_en		:1;
	uint32_t gpiog_en		:1;
	uint32_t gpioh_en		:1;
	uint32_t gpioi_en		:1;
	uint32_t res1    		:3;
	uint32_t crc_en  		:1;
	uint32_t res2    		:5;
	uint32_t bkpsram_en		:1;
	uint32_t res3    		:1;
	uint32_t ccmdataram_en 	:1;
	uint32_t dma1_en 		:1;
	uint32_t dma2_en 		:1;
	uint32_t res4    		:2;
	uint32_t ethmac_en 		:1;
	uint32_t ethmactx_en 	:1;
	uint32_t ethmacrx_en 	:1;
	uint32_t ethmacptp_en 	:1;
	uint32_t otghs_en		:1;
	uint32_t otghsulpi_en	:1;
	uint32_t res5			:1;
}RCC_AHB1ENR_t;

typedef struct{
	uint32_t odr_0	:1;
	uint32_t odr_1	:1;
	uint32_t odr_2	:1;
	uint32_t odr_3	:1;
	uint32_t odr_4	:1;
	uint32_t odr_5	:1;
	uint32_t odr_6	:1;
	uint32_t odr_7	:1;
	uint32_t odr_8	:1;
	uint32_t odr_9	:1;
	uint32_t odr_10	:1;
	uint32_t odr_11	:1;
	uint32_t odr_12	:1;
	uint32_t odr_13	:1;
	uint32_t odr_14	:1;
	uint32_t odr_15	:1;
	uint32_t res	:16;
}GPIOX_ODR_t;

typedef struct{
	uint32_t pmode_0 	: 2;
	uint32_t pmode_1 	: 2;
	uint32_t pmode_2 	: 2;
	uint32_t pmode_3 	: 2;
	uint32_t pmode_4 	: 2;
	uint32_t pmode_5 	: 2;
	uint32_t pmode_6 	: 2;
	uint32_t pmode_7 	: 2;
	uint32_t pmode_8 	: 2;
	uint32_t pmode_9 	: 2;
	uint32_t pmode_10 	: 2;
	uint32_t pmode_11 	: 2;
	uint32_t pmode_12 	: 2;
	uint32_t pmode_13 	: 2;
	uint32_t pmode_14 	: 2;
	uint32_t pmode_15 	: 2;
}GPIOX_MODER_t;

typedef struct{
	uint32_t idr_0	:1;
	uint32_t idr_1	:1;
	uint32_t idr_2	:1;
	uint32_t idr_3	:1;
	uint32_t idr_4	:1;
	uint32_t idr_5	:1;
	uint32_t idr_6	:1;
	uint32_t idr_7	:1;
	uint32_t idr_8	:1;
	uint32_t idr_9	:1;
	uint32_t idr_10	:1;
	uint32_t idr_11	:1;
	uint32_t idr_12	:1;
	uint32_t idr_13	:1;
	uint32_t idr_14	:1;
	uint32_t idr_15	:1;
	uint32_t res	:16;
}GPIOX_IDR_t;

typedef struct{
	uint32_t pup_0  :2;
	uint32_t pup_1  :2;
	uint32_t pup_2  :2;
	uint32_t pup_3  :2;
	uint32_t pup_4  :2;
	uint32_t pup_5  :2;
	uint32_t pup_6  :2;
	uint32_t pup_7  :2;
	uint32_t pup_8  :2;
	uint32_t pup_9  :2;
	uint32_t pup_10 :2;
	uint32_t pup_11 :2;
	uint32_t pup_12 :2;
	uint32_t pup_13 :2;
	uint32_t pup_14 :2;
	uint32_t pup_15 :2;

}GPIOX_PUP_t;

#endif /* MAIN_H_ */
