/*
 * led.c
 *
 *  Created on: Oct 5, 2024
 *      Author: elouf
 */
#include "led.h"
#include "gpio.h"
void LED_init(void)
{
	GPIO_setupPinDirection(RED_PORT_ID,RED_PIN_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(GREEN_PORT_ID,GREEN_PIN_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(BLUE_PORT_ID,BLUE_PIN_ID,PIN_OUTPUT);

}
void LED_on(LED_ID id )
{
	switch (id) {
		case LED_RED :
			GPIO_writePin(RED_PORT_ID,RED_PIN_ID,LED_ON);
			break;
		case LED_GREEN :
			GPIO_writePin(GREEN_PORT_ID,GREEN_PIN_ID,LED_ON);
			break;
		case LED_BLUE:
			GPIO_writePin(BLUE_PORT_ID,BLUE_PIN_ID,LED_ON);
			break;
		default:
			break;
	}

}
void LED_off(LED_ID id )
{
	switch (id) {
		case LED_RED:
			GPIO_writePin(RED_PORT_ID,RED_PIN_ID,LED_OFF);
			break;
		case LED_GREEN:
			GPIO_writePin(GREEN_PORT_ID,GREEN_PIN_ID,LED_OFF);
			break;
		case LED_BLUE:
			GPIO_writePin(BLUE_PORT_ID,BLUE_PIN_ID,LED_OFF);
			break;
		default:
			break;
	}

}



