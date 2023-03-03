#include <stdint.h>

void delay(uint32_t seconds);
void ledON(uint32_t*, uint8_t);
void ledOFF(uint32_t*, uint8_t);

int main(void)
{
	uint32_t *pRCC = (uint32_t*) 0x40021014;
	uint32_t *pGPIOEmode = (uint32_t*) 0x48001000;
	uint32_t *pGPIOEoutput = (uint32_t*) 0x48001014;

	// Enable the clock for GPIOE peripheral in the AHBENR
	*pRCC |= (1 << 21); // SET the 21st bit position

	// Configure the mode of the IO pins as output.
	*pGPIOEmode |= 0x55550000; // set the 8th-15th pin mode to 01 general purpose output mode)

	while(1)
	{
		for(uint8_t current = 8; current < 16; current++)
		{
			uint8_t next = (current + 1) % 8;

			ledON(pGPIOEoutput, next);

			delay(1);

			ledOFF(pGPIOEoutput, current);

			delay(1);
		}

	}

}

// ledON sets the (i + 8)-th bit of the output data register HIGH (value: 1) (3,3 Volts)
void ledON(uint32_t* led, uint8_t i)
{
	*led |= (1 << (i + 8));
}

// ledOFF clears the i-th bit of the output data register to LOW (value: 0) (0 Volts)
void ledOFF(uint32_t* led, uint8_t i)
{
	*led &= ~(1 << i);
}

// delay simulates a human-eye-visible delay
void delay(uint32_t seconds)
{
	seconds *= 30000;
	for(uint32_t i = 0; i < seconds; i++);
}
