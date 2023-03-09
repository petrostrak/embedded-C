/*
 * keys.h
 *
 *  Created on: Mar 9, 2023
 *      Author: petros
 */

#ifndef KEYS_H_
#define KEYS_H_
#include <stdint.h>
#include <stdio.h>

RCC_AHBENR_t volatile *const pRCCE = RCC_BASE_ADDR;
GPIOx_MODER_t volatile *const pGPIODmode = GPIOD_BASE_ADDR;
GPIOx_ODR_t volatile *const pGPIODoutput = GPIOD_OUTPUT;
GPIOx_IDR_t const volatile *const pGPIODinput = GPIOD_INPUT;

// delay simulates a human-eye-visible delay
void delay(uint32_t volatile seconds)
{
	seconds *= DELAY;
	for(uint32_t i = 0; i < seconds; i++);
}

void setRowsHigh()
{
	pGPIODoutput->ODR0 = STATE_HIGH;
	pGPIODoutput->ODR1 = STATE_HIGH;
	pGPIODoutput->ODR2 = STATE_HIGH;
	pGPIODoutput->ODR3 = STATE_HIGH;
}

void scanRow1()
{
	pGPIODoutput->ODR0 = STATE_LOW;

	// read C1, C2, C3, C4 (PD8, 9, 10, 11)
	uint32_t c1Status = pGPIODinput->IDR8;
	uint32_t c2Status = pGPIODinput->IDR9;
	uint32_t c3Status = pGPIODinput->IDR10;
	uint32_t c4Status = pGPIODinput->IDR11;

	if(c1Status)
	{
		delay(1);
		printf("1");
	} else if(c2Status) {
		delay(1);
		printf("2");
	} else if(c3Status) {
		delay(1);
		printf("3");
	} else if(c4Status) {
		delay(1);
		printf("A");
	}
}

void scanRow2()
{
	pGPIODoutput->ODR0 = STATE_HIGH;
	pGPIODoutput->ODR1 = STATE_LOW;

	// read C1, C2, C3, C4 (PD8, 9, 10, 11)
	uint32_t c1Status = pGPIODinput->IDR8;
	uint32_t c2Status = pGPIODinput->IDR9;
	uint32_t c3Status = pGPIODinput->IDR10;
	uint32_t c4Status = pGPIODinput->IDR11;

	if(c1Status)
	{
		delay(1);
		printf("4");
	} else if(c2Status) {
		delay(1);
		printf("5");
	} else if(c3Status) {
		delay(1);
		printf("6");
	} else if(c4Status) {
		delay(1);
		printf("B");
	}
}

void scanRow3()
{
	pGPIODoutput->ODR1 = STATE_HIGH;
	pGPIODoutput->ODR2 = STATE_LOW;

	// read C1, C2, C3, C4 (PD8, 9, 10, 11)
	uint32_t c1Status = pGPIODinput->IDR8;
	uint32_t c2Status = pGPIODinput->IDR9;
	uint32_t c3Status = pGPIODinput->IDR10;
	uint32_t c4Status = pGPIODinput->IDR11;

	if(c1Status)
	{
		delay(1);
		printf("7");
	} else if(c2Status) {
		delay(1);
		printf("8");
	} else if(c3Status) {
		delay(1);
		printf("9");
	} else if(c4Status) {
		delay(1);
		printf("C");
	}
}

void scanRow4()
{
	pGPIODoutput->ODR2 = STATE_HIGH;
	pGPIODoutput->ODR3 = STATE_LOW;

	// read C1, C2, C3, C4 (PD8, 9, 10, 11)
	uint32_t c1Status = pGPIODinput->IDR8;
	uint32_t c2Status = pGPIODinput->IDR9;
	uint32_t c3Status = pGPIODinput->IDR10;
	uint32_t c4Status = pGPIODinput->IDR11;

	if(c1Status)
	{
		delay(1);
		printf("*");
	} else if(c2Status) {
		delay(1);
		printf("0");
	} else if(c3Status) {
		delay(1);
		printf("#");
	} else if(c4Status) {
		delay(1);
		printf("D");
	}
}

#endif /* KEYS_H_ */
