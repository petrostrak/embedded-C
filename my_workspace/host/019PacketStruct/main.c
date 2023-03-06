/*
 * main.c
 *
 *  Created on: Mar 6, 2023
 *      Author: petrostrak
 */
#include <stdio.h>
#include <stdint.h>

typedef struct
{
	uint8_t crc;
	uint8_t status;
	uint16_t payload;
	uint8_t bat;
	uint8_t sensor;
	uint8_t longAddr;
	uint8_t shortAddr;
	uint8_t addrMode;

}Packet_t;

int main(void)
{
	printf("Enter the 32bit packet value: ");
	int32_t value;
	scanf("%X", &value);


}
