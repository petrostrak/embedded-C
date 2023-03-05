// ledON sets the (i + 8)-th bit of the output data register HIGH (value: 1) (3,3 Volts)
void ledON(uint32_t volatile *led, uint8_t i)
{
	if(i == 8)
		*led |= (1 << 8);
	*led |= (1 << (i + 8));
}
