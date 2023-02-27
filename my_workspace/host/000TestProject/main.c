/*
 * main.c
 *
 *  Created on: Feb 21, 2023
 *      Author: petros
 */
#include<stdio.h>

int main(int argc, char **argv) {
	double charge, chargeE;
	double electrons;
	printf("Enter the charge: ");
	scanf("%lf", &charge);


	printf("Enter the charge of the electron: ");
	scanf("%le", &chargeE);

	electrons = (charge / chargeE) * -1;

	printf("Total of number of electrons = %le\n", electrons);
	printf("Total of number of electrons = %lf\n", electrons);

	return 0;
}
