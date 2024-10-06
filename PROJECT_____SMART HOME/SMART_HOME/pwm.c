/*
 * pwm.c
 *
 *  Created on: Oct 5, 2024
 *      Author: elouf
 */
#include "common_macros.h"
#include "pwm.h"
#include "avr/io.h"
#include "gpio.h"
/* not confirgable*/
void PWM_Timer0_Start(uint8 duty_cycle)
{
	TCNT0=0;
	if(duty_cycle==100)
	{
		OCR0=255;
	}
	else
	{
		OCR0=(uint8)((uint32)(duty_cycle *OVERFLOW_MAX_COUNT)/100);
	}

	GPIO_setupPinDirection(PORTB_ID,3,PIN_OUTPUT);
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS00) | (1<<CS02);




}
