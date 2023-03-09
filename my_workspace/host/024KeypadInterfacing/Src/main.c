/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
#include "peripherals.h"
#include "keys.h"

int main(void)
{
	// Enable the clock for GPIOD peripheral in the AHBENR
	set_gpiod_bus();

	// Configure the mode of the PDO, PD1, PD2, PD3 pins as output.
	set_gpiod_mode_output();

	// Configure the mode of the PD8, PD9, PD10, PD11 pins as input
	clear_gpiod_mode_input();

	// Set internal pull-up resistors for PD8, PD9, PD10 and PD11
	set_pull_up_resistors();

	while(1)
	{
		set_rows_high();
		scan_row_1();
		scan_row_2();
		scan_row_3();
		scan_row_4();
	}
}
