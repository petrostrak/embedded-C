/*
 * main.c
 *
 *  Created on: Feb 27, 2023
 *      Author: petrostrak
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int32_t x;
	int32_t mask_value = 1;
	printf("Please give a number: ");
	scanf("%d", &x);

	if ((x & mask_value) == 0) {
		printf("The given number is even.\n");
	} else {
		printf("The given number is odd.\n");
	}

	return EXIT_SUCCESS;
}

