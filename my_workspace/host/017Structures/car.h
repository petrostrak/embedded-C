/*
 * car.h
 *
 *  Created on: Mar 5, 2023
 *      Author: petrostrak
 */

#ifndef CAR_H_
#define CAR_H_

struct CarModel
{
	unsigned int carNumber;
	uint32_t carPrice;
	uint16_t carMaxSpeed;
	float carWeight;
};

void printCar(struct CarModel c)
{
	printf("{\n");
	printf("\tcarNumber: %d\n", c.carNumber);
	printf("\tcarPrice: %d\n", c.carPrice);
	printf("\tcarMaxSpeed: %d\n", c.carMaxSpeed);
	printf("\tcarWeight: %0.2f\n", c.carWeight);
	printf("}\n");
}

#endif /* CAR_H_ */
