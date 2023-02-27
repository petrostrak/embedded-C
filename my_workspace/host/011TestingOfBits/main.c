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

	if (x & mask_value) { // if its 1 then its odd
		printf("The given number is odd.\n");
	} else { // else if its 0 its even
		printf("The given number is even.\n");
	}

	return EXIT_SUCCESS;
}

