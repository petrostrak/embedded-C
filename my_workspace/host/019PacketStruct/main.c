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

	Packet_t packet;

	// bit extraction for crc
	packet.crc = (uint8_t)(value & 0x3);

	// bit extraction for status
	packet.status = (uint8_t)(value >> 2) & 0x1;

	// bit extraction for payload
	packet.payload = (uint16_t) (value >> 3) & 0xFFF;

	// bit extraction for bat
	packet.bat = (uint8_t) (value >> 15) & 0x7;

	// bit extraction for sensor
	packet.sensor = (uint8_t) (value >> 18) & 0x7;

	// bit extraction for longAddr
	packet.longAddr = (uint8_t) (value >> 21) & 0xFF;

	// bit extraction for shortAddr
	packet.shortAddr = (uint8_t) (value >> 29) & 0x3;

	// bit extraction for addrMode
	packet.addrMode = (uint8_t) (value >> 31) & 0x1;

	printf("crc:\t\t%#x\n", packet.crc);
	printf("status:\t\t%#x\n", packet.status);
	printf("payload:\t%#x\n", packet.payload);
	printf("bat:\t\t%#x\n", packet.bat);
	printf("sensor:\t\t%#x\n", packet.sensor);
	printf("longAddr:\t%#x\n", packet.longAddr);
	printf("shortAddr:\t%#x\n", packet.shortAddr);
	printf("addrMode:\t%#x\n", packet.addrMode);
	printf("Size of struct: %lu", sizeof(packet));
}
