/*
 * ldr.h
 *
 *  Created on: Oct 5, 2024
 *      Author: elouf
 */

#ifndef LDR_H_
#define LDR_H_
#include "std_types.h"

#define LDR_PIN_ID 0
#define LDR_MAX_LIGHT 100
#define LDR_MAX_VOLTAGE 2.56

void LDR_init(void);
uint8 LDR_getLightIntensity(void);



#endif /* LDR_H_ */
