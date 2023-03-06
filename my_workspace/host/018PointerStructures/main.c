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
	char data1;
	int data2;
	char data3;
	short data4;
	struct
	{
		float data5;
		float data6;
	}ExtraData;
}DataSet_t;

int main(void) {

	DataSet_t d = {
			.data1 = 0x11,
			.data2 = 0xEEEEFFFF,
			.data3 = 0x22,
			.data4 = 0xABCD,
			.ExtraData = {
					.data5 = 0.1,
					.data6 = 0.2,
			},
	};

	printf("Initial value of .data1: %d\n", d.data1);

	DataSet_t *pData = &d;
	pData->data1 = 0x44;

	printf("Value of .data1 after we change it via pointer: %d\n", d.data1);
}



