/*
 * adc.c
 *
 *  Created on: Oct 3, 2024
 *      Author: elouf
 */
#include "adc.h"
#include "common_macros.h"
#include "avr/io.h"

volatile uint16 global_var_adc=0;
void ADC_init(ADC_configerableType * PTR_ADC)
{
	ADMUX= (ADMUX & 0X3F )|((PTR_ADC->VREF)<<6); /*AREF IS CONFIGERED WITH DATA FROM (HAL)    */
	ADCSRA|=(1<<ADEN);/* ADC Enable*/
	ADCSRA=(ADCSRA & 0XF8 )|((PTR_ADC->PRESCALLER));/*PRESCALLER IS CONFIGERED WITH DATA FROM (HAL) */
	ADCSRA|=(1<<ADIE);
}

void ADC_deinit(void)
{
	ADMUX= 0;
	ADCSRA=0;


}

uint16 ADC_readChannel(uint8 ch_num)
{
	ADMUX = (ADMUX&0xe0)|(ch_num&0x1f); /*choose chaneel number*/
	ADCSRA|=(1<<ADSC); /*start conversion*/
	while(GET_BIT(ADCSRA,ADIF)==0); /*POLLING UNTIL THE DATA CONVETING*/
	SET_BIT(ADCSRA,ADIF); /*CLEAR FLAG BY WRITE ONE*/
	return ADC;

}




