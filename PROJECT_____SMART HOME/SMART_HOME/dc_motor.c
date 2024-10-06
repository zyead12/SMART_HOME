/*
 * dc_motor.c
 *
 *  Created on: Oct 5, 2024
 *      Author: elouf
 */
#include "dc_motor.h"
#include "gpio.h"
#include "pwm.h"
static void  DC_MOTOR_cw(void);
static void  DC_MOTOR_acw(void);
static void  DC_MOTOR_stop(void);

void DC_MOTOR_init(void)
{
	GPIO_setupPinDirection(DC_MOTOR_IN1_DIRECTION1_PORT_ID,DC_MOTOR_IN1_DIRECTION1_PIN_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(DC_MOTOR_IN2_DIRECTION2_PORT_ID,DC_MOTOR_IN2_DIRECTION2_PIN_ID,PIN_OUTPUT);
	/*STOP*/
	DC_MOTOR_stop();


}
void DC_MOTOR_rotate(MOTOR_STATE state ,uint8 speed)
{
	switch(state)
	{
	case CW :
		DC_MOTOR_cw();
		break;
	case ACW :
			DC_MOTOR_acw();
			break;
	case STOP :
		DC_MOTOR_stop();
			break;
	}
	PWM_Timer0_Start(speed);


}
static void  DC_MOTOR_cw(void)
{
	GPIO_writePin(DC_MOTOR_IN1_DIRECTION1_PORT_ID,DC_MOTOR_IN1_DIRECTION1_PIN_ID,LOGIC_HIGH);
			GPIO_writePin(DC_MOTOR_IN2_DIRECTION2_PORT_ID,DC_MOTOR_IN2_DIRECTION2_PIN_ID,LOGIC_LOW);
}
static void  DC_MOTOR_acw(void)
{
	GPIO_writePin(DC_MOTOR_IN1_DIRECTION1_PORT_ID,DC_MOTOR_IN1_DIRECTION1_PIN_ID,LOGIC_LOW);
		GPIO_writePin(DC_MOTOR_IN2_DIRECTION2_PORT_ID,DC_MOTOR_IN2_DIRECTION2_PIN_ID,LOGIC_HIGH);

}
static void  DC_MOTOR_stop(void)
{
	GPIO_writePin(DC_MOTOR_IN1_DIRECTION1_PORT_ID,DC_MOTOR_IN1_DIRECTION1_PIN_ID,LOGIC_LOW);
		GPIO_writePin(DC_MOTOR_IN2_DIRECTION2_PORT_ID,DC_MOTOR_IN2_DIRECTION2_PIN_ID,LOGIC_LOW);
}




