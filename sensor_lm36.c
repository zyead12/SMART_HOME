




#include "sensor_lm36.h"
#include "util/delay.h"
#include "adc.h"
ADC_configerableType s_AdcMode={INTERNAL_VREF,F_CPU_128};
void LM36_init(void)
{
	ADC_init(&s_AdcMode);
}



uint8 LM36_getTemperture(void)
{
	uint16 digital_value,temp;
	digital_value= ADC_readChannel(LM36_PIN_ID);

	if(s_AdcMode.VREF == AVCC)
	{

		temp= (uint8)(((uint32)digital_value * LM36_MAX_TEMP *ADC_EXTERNAL_AVCC_MODE)/( ADC_MAX_COUNT * LM36_MAX_VOLTAGE ));
	}
	else if(s_AdcMode.VREF == INTERNAL_VREF)
		{
		temp= (uint8)(((uint32)digital_value * LM36_MAX_TEMP *ADC_INTERNAL_AREF_MODE)/( ADC_MAX_COUNT * LM36_MAX_VOLTAGE ));
		}
	else if(s_AdcMode.VREF == AREF)
			{
		temp= (uint8)(((uint32)digital_value * LM36_MAX_TEMP *ADC_EXTERNAL_AREF_MODE)/( ADC_MAX_COUNT * LM36_MAX_VOLTAGE ));
			}

	//temp= (uint16)(((uint32)digital_value * LM36_MAX_TEMP *adc_vref)/( ADC_MAX_COUNT * LM36_MAX_VOLTAGE ));
	return temp;
}
