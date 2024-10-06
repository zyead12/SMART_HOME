/*
 * adc.h
 *
 *  Created on: Oct 3, 2024
 *      Author: elouf
 */

#include "std_types.h"
#define ADC_EXTERNAL_AREF_MODE 5
#define ADC_INTERNAL_AREF_MODE 2.56
#define ADC_EXTERNAL_AVCC_MODE 5

extern volatile uint16 global_var_adc;

typedef enum{
	AREF,AVCC,INTERNAL_VREF=3 /* numbers TO EASE INSERTION show in data sheet*/
}ADC_VREFModeType;

typedef enum{
	F_CPU_2_0,F_CPU_2,F_CPU_4,F_CPU_8,F_CPU_16,F_CPU_32,F_CPU_64,F_CPU_128 /*TO EASE INSERTION*/
}ADC_precsallerClock;

typedef struct
{
	ADC_VREFModeType VREF;
	ADC_precsallerClock PRESCALLER;

}ADC_configerableType;


#define ADC_MAX_COUNT 1023

void ADC_init(ADC_configerableType * PTR_ADC);

uint16 ADC_readChannel(uint8 ch_num);




void ADC_deinit(void);

