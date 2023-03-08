/*
 * main.c
 *
 *  Created on: Mar 8, 2023
 *      Author: petros
 */
#include <stdio.h>
#include <stdint.h>

void swapArrays(uint8_t *array1, uint8_t size1, uint8_t *array2, uint8_t size2)
{
	if(size1 == size2)
	{
		for(uint8_t i = 0; i < size1; i++)
		{
			int8_t temp = array1[i];
			array1[i] = array2[i];
			array2[i] = temp;
		}

		printf("array1: ");
		for(uint8_t i = 0; i < size1; i++)
			printf("%d ", array1[i]);


		printf("\narray2: ");
		for(uint8_t i = 0; i < size1; i++)
			printf("%d ", array2[i]);

	} else {
		printf("arrays must be of the same size\n");
	}

}

int main(void)
{
	uint8_t array1[] = {0, 1, 3, 5, 7};
	uint8_t array2[] = {2, 4, 6, 8, 10};

	swapArrays(array1, sizeof(array1), array2, sizeof(array2));

	return 0;
}
