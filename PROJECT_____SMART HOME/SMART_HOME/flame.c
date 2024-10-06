/*
 * flame.c
 *
 *  Created on: Oct 6, 2024
 *      Author: elouf
 */
#include "flame.h"
#include "gpio.h"

void FlameSensor_init(void)
{
	GPIO_setupPinDirection(FLAME_INPUT_PORT_ID,FLAME_INPUT_PIN_ID,PIN_OUTPUT);
}
flame_state_type FlameSensor_getVALUE(void)
{
	//flame_state_type fire_state;
	return GPIO_readPin(FLAME_INPUT_PORT_ID,FLAME_INPUT_PIN_ID);
}
