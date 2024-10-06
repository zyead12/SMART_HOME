/*
 * app.c
 *
 *  Created on: Oct 5, 2024
 *      Author: elouf
 */
#include "led.h"
#include "util/delay.h"
#include "buzzer.h"
#include "dc_motor.h"
#include "sensor_lm36.h"
#include "ldr.h"
#include "lcd.h"
#include "flame.h"

void dispaly_temp(void);
void dispaly_light(void);
void AutomaticFanSpeedControl(void);
void AutomaticLightingControl(void);

uint8 light;
uint8 temp;
uint8 x=0;
uint8 flam=0;

int main(void)
{
	LED_init();
BUZZER_init();
	DC_MOTOR_init();
	LM36_init();
	LDR_init();
	LCD_init();
	FlameSensor_init();
	LED_init();




	while(1)
	{

		while(FlameSensor_getVALUE()==ON_FIRE)/*polling*/
		{
			if(flam==0)
			{
				LCD_clearScreen();
				flam=1;
			}

			LCD_moveCursor(0,1);
			LCD_displayString("Critical alert!");
			LCD_displayCharacter(' ');
			BUZZER_on();
			x=1;


		}

		 /*no fire detect*/
		if(x==1)
		{
			LCD_clearScreen();
			x=0;
			BUZZER_off();
			flam=0;
		}






		temp=LM36_getTemperture();
		light=LDR_getLightIntensity();
		dispaly_temp();
		dispaly_light();
		AutomaticFanSpeedControl();
		AutomaticLightingControl();





	}
	return 0;
}
void dispaly_temp(void)
{
	//LCD_displayStringRowColumn(1,0,"TEMP=   LDR=   %");
	LCD_displayStringRowColumn(1,0,"TEMP=");
	LCD_moveCursor(1,5);


				if(temp<10)
				{
					LCD_intgerToString(temp);
					LCD_displayCharacter(' ');
				}
				else
				{
					LCD_intgerToString(temp);
				}

}
void dispaly_light(void)
{
	//LCD_displayStringRowColumn(1,0,"TEMP=   LDR=   %");
	LCD_displayStringRowColumn(1,8,"LDR=");
	LCD_moveCursor(1,12);

				if(light<100)
				{
					LCD_intgerToString(light);
					LCD_displayCharacter('%');
					LCD_displayCharacter(' ');

				}
				else
				{
					LCD_intgerToString(light);
					LCD_displayCharacter('%');
				}

}
void AutomaticFanSpeedControl(void)
{
	LCD_moveCursor(0,3);
			LCD_displayString("FAN IS ");
			if(temp>=40)
			{
				LCD_displayString("ON   ");
				DC_MOTOR_rotate(CW,100);
			}
			else if(temp>=35 && temp<40)
			{
				LCD_displayString("ON   ");
						DC_MOTOR_rotate(CW,75);
			}
			else if(temp>=30 && temp<35)
				{
				LCD_displayString("ON   ");
							DC_MOTOR_rotate(CW,50);
				}
			else if(temp>=25 && temp<30)
				{
				LCD_displayString("ON   ");
							DC_MOTOR_rotate(CW,25);
				}
			else{
				LCD_displayString("OFF  ");
				DC_MOTOR_rotate(STOP,0);

			}



}
void AutomaticLightingControl(void)
{
	if(light>70)
	{
		LED_off(LED_RED);
		LED_off(LED_GREEN);
		LED_off(LED_BLUE);

	}
	else if(light<=70 && light>=51 )

	{
		LED_on(LED_RED);
		LED_off(LED_BLUE);
		LED_off(LED_GREEN);

	}
	else if(light<=50 && light>=16 )

		{
			LED_on(LED_RED);
			LED_off(LED_BLUE);
			LED_on(LED_GREEN);

		}
	else
	{
		LED_on(LED_RED);
		LED_on(LED_GREEN);
		LED_on(LED_BLUE);


	}

}
