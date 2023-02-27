/*
 * main.c
 *
 *  Created on: Feb 27, 2023
 *      Author: petrostrak
 *      Write a program to set (make bit state to 1) 4th and 7th
 *      bit position of a given number and print the result.
 *
 *
 *      mask_value: 10010000
 *      128 + 16 = 144
 */
#include <stdio.h>
#include <stdlib.h>

int main() {

	int32_t x;
	int32_t mask_value = 144;
	printf("Please give a number: ");
	scanf("%d", &x);

	printf("The result of setting the 4th-bit and 7th-bit of the given number %d is %d", x, x | mask_value);

	return EXIT_SUCCESS;
}

