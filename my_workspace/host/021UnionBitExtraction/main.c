/*
 * main.c
 *
 *  Created on: Mar 7, 2023
 *      Author: petros
 *      Achieve bit-extraction with the combination of unions and bit fields
 */
#include <stdio.h>
#include <stdint.h>

// Structure using Bit field
typedef union
{
	uint32_t value;
	struct
	{
		uint32_t crc		:2;
		uint32_t status		:1;
		uint32_t payload	:12;
		uint32_t bat		:3;
		uint32_t sensor		:3;
		uint32_t longAddr	:8;
		uint32_t shortAddr	:2;
		uint32_t addrMode	:1;
	}packetField;
}Packet_t;

int main(void)
{
	printf("Enter the 32bit packet value: ");
	Packet_t packet;
	scanf("%X", &packet.value);

	printf("crc:\t\t%#x\n", packet.packetField.crc);
	printf("status:\t\t%#x\n", packet.packetField.status);
	printf("payload:\t%#x\n", packet.packetField.payload);
	printf("bat:\t\t%#x\n", packet.packetField.bat);
	printf("sensor:\t\t%#x\n", packet.packetField.sensor);
	printf("longAddr:\t%#x\n", packet.packetField.longAddr);
	printf("shortAddr:\t%#x\n", packet.packetField.shortAddr);
	printf("addrMode:\t%#x\n", packet.packetField.addrMode);

	// Now with the Bit fields structure declaration, the total
	// memory consumption is 4 bytes.
	printf("Size of struct: %lu", sizeof(packet));
}

