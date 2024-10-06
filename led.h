/*
 * led.h
 *
 *  Created on: Oct 5, 2024
 *      Author: elouf
 */

#include "std_types.h"
#define RED_PORT_ID PORTB_ID
#define RED_PIN_ID PIN5_ID

#define GREEN_PORT_ID PORTB_ID
#define GREEN_PIN_ID PIN6_ID

#define BLUE_PORT_ID PORTB_ID
#define BLUE_PIN_ID PIN7_ID

typedef enum
{
	LED_RED=1,LED_GREEN,LED_BLUE
}LED_ID;

#define LED_ON LOGIC_HIGH
#define LED_OFF LOGIC_LOW

void LED_init(void);
void LED_off(LED_ID id );
void LED_on(LED_ID id );
