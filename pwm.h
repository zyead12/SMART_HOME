/*
 * pwm.h
 *
 *  Created on: Oct 5, 2024
 *      Author: elouf
 */

#ifndef PWM_H_
#define PWM_H_
#include "std_types.h"


#define OVERFLOW_MAX_COUNT 256


void PWM_Timer0_Start (uint8 duty_cycle);

#endif /* PWM_H_ */
