/*
 * main.c
 *
 *  Created on: Mar 6, 2023
 *      Author: petros
 */
#include <stdio.h>
#include <stdint.h>

struct DataSet
{
	char data1;
	int data2;
	char data3;
	short data4;
}__attribute__((packed));

struct DataSetUnaligned
{
	char data1;
	int data2;
	char data3;
	short data4;
}__attribute__((packed));

int main(void) {
	struct DataSet data;
	struct DataSetUnaligned data1;

	data.data1 = 0x11;
	data.data2 = 0xEEEEFFFF;
	data.data3 = 0x22;
	data.data4 = 0xABCD;

	data1.data1 = 0x11;
	data1.data2 = 0xEEEEFFFF;
	data1.data3 = 0x22;
	data1.data4 = 0xABCD;

	uint8_t *ptr = (uint8_t*)&data;
	uint32_t totalSize = sizeof(data);

	printf("Memory address		Content\n");
	printf("===========================\n");

	for(uint32_t i = 0; i < totalSize; i++)
	{
		printf("%p		%X\n", ptr, *ptr);
		ptr++;
	}
	printf("Total memory consumed by this struct variable is %lubytes, but should be 8bytes\n", sizeof(data));

	uint8_t *ptr1 = (uint8_t*)&data1;
	uint32_t totalSize1 = sizeof(data1);

	printf("Memory address		Content\n");
	printf("===========================\n");

	for(uint32_t i = 0; i < totalSize1; i++)
	{
		printf("%p		%X\n", ptr1, *ptr1);
		ptr1++;
	}
	printf("Total memory consumed by this struct variable is %lubytes, but should be 8bytes\n", sizeof(data1));
}



