/*
 * ldr.c
 *
 *  Created on: Oct 5, 2024
 *      Author: elouf
 */
#include "ldr.h"
#include "adc.h"
#include "std_types.h"
ADC_configerableType ADC_MODE={INTERNAL_VREF,F_CPU_128};
void LDR_init(void)
{
	ADC_init(&ADC_MODE);
}
uint8 LDR_getLightIntensity(void)
{
	uint16 digital_value;
	uint8 light;
	digital_value=ADC_readChannel(LDR_PIN_ID);
	//light= (uint8)(((float32) digital_value * LDR_MAX_LIGHT * ADC_INTERNAL_AREF_MODE)/( ADC_MAX_COUNT * LDR_MAX_VOLTAGE ));
	if(ADC_MODE.VREF == INTERNAL_VREF)
			{
				light= (uint8)(((float32) digital_value * LDR_MAX_LIGHT * ADC_INTERNAL_AREF_MODE)/( ADC_MAX_COUNT * LDR_MAX_VOLTAGE ));
			}
		else if(ADC_MODE.VREF == AVCC)
				{
					light= (uint8)(((float32) digital_value * LDR_MAX_LIGHT * ADC_EXTERNAL_AVCC_MODE)/( ADC_MAX_COUNT * LDR_MAX_VOLTAGE ));
				}
		else if(ADC_MODE.VREF ==AREF )
				{
					light= (uint8)(((float32) digital_value * LDR_MAX_LIGHT * ADC_EXTERNAL_AREF_MODE)/( ADC_MAX_COUNT * LDR_MAX_VOLTAGE ));
				}
		return light;
	return light;


}
