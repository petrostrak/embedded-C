/*
 * main.c
 *
 *  Created on: Mar 5, 2023
 *      Author: petrostrak
 */
#include <stdio.h>
#include <stdint.h>
#include "car.h"

int main(void) {
	struct CarModel BMW = {2021, 15000,220, 1330};
	struct CarModel Honda = {
			.carNumber = 2022,
			.carPrice = 17600,
			.carMaxSpeed = 210,
			.carWeight = 15000,
	};

	printCar(BMW);
	printCar(Honda);
}
