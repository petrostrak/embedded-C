/*
 * main.c
 *
 *  Created on: Feb 27, 2023
 *      Author: petrostrak
 *      Write a program to clear (set the state of the bits to 0) the 4th, 5th and 6th bit.
 *
 *      mask_value 10001111 = 0x8F (143)
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {

	int32_t x;
	int32_t mask_value = 0x8F;
	printf("Enter an integer to clear the 4th, 5th and 6th bit: ");
	scanf("%d", &x);

	printf("The result of clearing the 4th-bit, 5th-bit and 6th-bit of the given number %d is %d", x, x & mask_value);


	return EXIT_SUCCESS;
}

