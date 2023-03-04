#include <stdint.h>

void delay(uint32_t);
void ledON(uint32_t*, uint8_t);
void ledOFF(uint32_t*, uint8_t);

int main(void)
{
	uint32_t *const pRCCE = (uint32_t*) 0x40021014;
	uint32_t *const pRCCA = (uint32_t*) 0x40021014;
	uint32_t *const pGPIOEmode = (uint32_t*) 0x48001000;
	uint32_t *const pGPIOEoutput = (uint32_t*) 0x48001014;
	uint32_t *const pGPIOAmode = (uint32_t*) 0x48000000;
	uint32_t *const pGPIOAinput = (uint32_t*) 0x48000010;

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
		uint8_t PA0Status = (uint8_t)*pGPIOAinput & 0x1; // Since we only need to read the 1st bit, we zeroed all others

		if(PA0Status)
		{
			*pGPIOEoutput &= 0x0; // Clear all output bits before start the iteration
			for(uint8_t current = 8; current < 16; current++)
			{
				uint8_t next = (current + 1) % 8;

				ledON(pGPIOEoutput, next);

				delay(1);

				ledOFF(pGPIOEoutput, current);

				delay(1);
			}
		} else {
			*pGPIOEoutput &= 0x0; // Clear all output bits before start the iteration
			for(uint8_t current = 15; current >= 8; current--)
			{
				uint8_t next = (current - 1) % 8;

				ledON(pGPIOEoutput, next);

				delay(1);

				ledOFF(pGPIOEoutput, current);

				delay(1);
			}
		}
	}

}

// ledON sets the (i + 8)-th bit of the output data register HIGH (value: 1) (3,3 Volts)
void ledON(uint32_t *const led, uint8_t i)
{
	*led |= (1 << (i + 8));
}

// ledOFF clears the i-th bit of the output data register to LOW (value: 0) (0 Volts)
void ledOFF(uint32_t *const led, uint8_t i)
{
	*led &= ~(1 << i);
}

// delay simulates a human-eye-visible delay
void delay(uint32_t seconds)
{
	seconds *= 30000;
	for(uint32_t i = 0; i < seconds; i++);
}
