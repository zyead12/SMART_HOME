/*
 * flame.h
 *
 *  Created on: Oct 6, 2024
 *      Author: elouf
 */

#ifndef FLAME_H_
#define FLAME_H_
#include "std_types.h"
typedef enum
{
OFF_FIRE,ON_FIRE

}flame_state_type;

#define FLAME_INPUT_PORT_ID PORTD_ID
#define FLAME_INPUT_PIN_ID PIN2_ID

void FlameSensor_init(void);
flame_state_type FlameSensor_getVALUE(void);

#endif /* FLAME_H_ */
