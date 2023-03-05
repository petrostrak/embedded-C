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
