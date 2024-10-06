/*
 * buzzer.h
 *
 *  Created on: Oct 5, 2024
 *      Author: elouf
 */

#ifndef BUZZER_H_
#define BUZZER_H_
#include "std_types.h"

#define BUZZER_PORT_ID PORTD_ID
#define BUZZER_PIN_ID PIN3_ID

#define BUZZER_ON LOGIC_HIGH
#define BUZZER_OFF LOGIC_LOW

void BUZZER_init();
void BUZZER_on();
void BUZZER_off();

#endif /* BUZZER_H_ */
