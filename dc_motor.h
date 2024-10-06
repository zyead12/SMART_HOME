/*
 * dc_motor.h
 *
 *  Created on: Oct 5, 2024
 *      Author: elouf
 */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "std_types.h"

#define  DC_MOTOR_IN1_DIRECTION1_PORT_ID PORTB_ID
#define  DC_MOTOR_IN1_DIRECTION1_PIN_ID PIN0_ID

#define  DC_MOTOR_IN2_DIRECTION2_PORT_ID PORTB_ID
#define  DC_MOTOR_IN2_DIRECTION2_PIN_ID PIN1_ID



typedef enum{
	STOP,CW,ACW

}MOTOR_STATE;

void DC_MOTOR_rotate(MOTOR_STATE state ,uint8 speed);
void DC_MOTOR_init(void);
#endif /* DC_MOTOR_H_ */
