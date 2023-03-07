/*
 * leds.h
 *
 *  Created on: Mar 7, 2023
 *      Author: petros
 */

#ifndef LEDS_H_
#define LEDS_H_
#include "peripherals.h"

// ledON sets the (i + 8)-th bit of the output data register HIGH (value: 1) (3,3 Volts)
void ledON(uint32_t volatile *led, uint8_t i)
{
	*led |= (1 << (i + 8));
}

// ledOFF clears the i-th bit of the output data register to LOW (value: 0) (0 Volts)
void ledOFF(uint32_t volatile *led, uint8_t i)
{
	*led &= ~(1 << i);
}

// delay simulates a human-eye-visible delay
void delay(uint32_t volatile seconds)
{
	seconds *= 30000;
	for(uint32_t i = 0; i < seconds; i++);
}

void clearPins(GPIOx_ODR_t volatile *led)
{
	led->ODR8  = 0;
	led->ODR9  = 0;
	led->ODR10 = 0;
	led->ODR11 = 0;
	led->ODR12 = 0;
	led->ODR13 = 0;
	led->ODR14 = 0;
	led->ODR15 = 0;
}

#endif /* LEDS_H_ */
