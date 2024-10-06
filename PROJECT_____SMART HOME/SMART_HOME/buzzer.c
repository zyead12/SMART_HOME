/*
 * buzzer.c
 *
 *  Created on: Oct 5, 2024
 *      Author: elouf
 */
#include "buzzer.h"
#include "gpio.h"


void BUZZER_init()
{
	GPIO_setupPinDirection(BUZZER_PORT_ID,BUZZER_PIN_ID,PIN_OUTPUT);
	BUZZER_off();
}
void BUZZER_on()
{
	GPIO_writePin(BUZZER_PORT_ID,BUZZER_PIN_ID,BUZZER_ON);
}
void BUZZER_off()
{
	GPIO_writePin(BUZZER_PORT_ID,BUZZER_PIN_ID,BUZZER_OFF);
}


