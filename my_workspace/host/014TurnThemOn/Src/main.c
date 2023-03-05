#include <stdint.h>
#include "leds.h"

uint32_t volatile *const pRCCE = (uint32_t*) 0x40021014;
uint32_t volatile *const pRCCA = (uint32_t*) 0x40021014;
uint32_t volatile *const pGPIOEmode = (uint32_t*) 0x48001000;
uint32_t volatile *const pGPIOEoutput = (uint32_t*) 0x48001014;
uint32_t volatile *const pGPIOAmode = (uint32_t*) 0x48000000;
uint32_t const volatile *const pGPIOAinput = (uint32_t*) 0x48000010; // we can use const volatile in read only memory addresses

int main(void)
{
	// Enable the clock for GPIOE peripheral in the AHBENR
	*pRCCE |= (1 << 21); // SET the 21st bit position

	// Enable the clock for GPIOA peripheral in the AHBENR
	*pRCCA |= (1 << 17); // SET the 21st bit position

	// Configure the mode of the IO pins as output.
	*pGPIOEmode |= 0x55550000; // set the 8th-15th pin mode to 01 general purpose output mode)

	// Configure the mode of the IO pin PA0 as input
	*pGPIOAmode &= ~(3 << 0);


	while(1)
	{
		// Read the PA0 status (GPIOA input data register)
		uint8_t PA0Status = (uint8_t)(*pGPIOAinput & 0x1); // Since we only need to read the 1st bit, we zeroed all others

		if(PA0Status)
		{
			*pGPIOEoutput &= 0x0; // Clear all output bits before start the iteration
			for(uint8_t current = 8; current < 16; current++)
			{
				uint8_t next = (current + 1) % 8;

				ledON(pGPIOEoutput, next);

				delay(2);

				ledOFF(pGPIOEoutput, current);

				delay(2);
			}
		} else {
			*pGPIOEoutput &= 0x0; // Clear all output bits before start the iteration
			for(uint8_t current = 15; current >= 8; current--)
			{
				uint8_t next = (current - 1) % 8;

				ledON(pGPIOEoutput, next);

				delay(2);

				ledOFF(pGPIOEoutput, current);

				delay(2);
			}
		}
	}

}
