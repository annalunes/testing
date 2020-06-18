/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material.
 *
 *****************************************************************************/
 /**
  * @file stats.c
  * @brief stats.c is the implementation file of the assignment.
  *
  * This assignment proposed a code that analyzes an array of unsigned char data
  * and report on the max, min, mean and medium of the data set. The data set is
  * also reordered from large to small.
  *
  * @author Anna Nunes
  * @date June 17th 2020
  *
  */



#include <stdio.h>
#include "stats.h"

  /* Size of the Data Set */
#define SIZE (40)

void main() {

	unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
								114, 88,   45,  76, 123,  87,  25,  23,
								200, 122, 150, 90,   92,  87, 177, 244,
								201,   6,  12,  60,   8,   2,   5,  67,
								  7,  87, 250, 230,  99,   3, 100,  90 };

	/* Other Variable Declarations Go Here */
	uint16_t min, max, mean, median;

	/* Statistics and Printing Functions Go Here */
	print_array(test, SIZE);
	min = find_minimum(test, SIZE);
	max = find_maximum(test, SIZE);
	mean = find_mean(test, SIZE);
	median = find_median(test, SIZE);
	sort_array(test, SIZE);
	print_array(test, SIZE);
	print_statistics(min, max, mean, median);

}

/* Add other Implementation File Code Here */
uint16_t find_median(unsigned char* array, uint8_t array_size)
{
	uint16_t median = 0;
	sort_array(array, array_size);
	if (array_size % 2 == 0)
	{
		//array has an even amount of items, the median is the average between the two middle values
		median = (array[array_size / 2] + array[(array_size / 2) - 1]) / 2;
	}
	else
	{
		//array has an odd amount of items, the median is the middle value
		median = array[(array_size - 1) / 2];
	}
	return median;
}

uint16_t find_mean(unsigned char* array, uint8_t array_size)
{
	uint16_t sum = 0;
	for (uint8_t i = 0; i < array_size; i++)
	{
		sum += (uint16_t)(array[i]);
	}
	return (sum / array_size);
}

uint16_t find_maximum(unsigned char* array, uint8_t array_size)
{
	uint16_t maximum = 0;
	for (uint8_t i = 0; i < array_size; i++)
	{
		if ((uint16_t)(array[i]) > maximum)
			maximum = (uint16_t)(array[i]);
	}
	return maximum;
}

uint16_t find_minimum(unsigned char* array, uint8_t array_size)
{
	uint16_t minimum = array[0];
	for (uint8_t i = 1; i < array_size; i++)
	{
		if ((uint16_t)(array[i]) < minimum)
			minimum = (uint16_t)(array[i]);
	}
	return minimum;
}

void print_statistics(uint16_t minimum, uint16_t maximum, uint16_t mean, uint16_t median)
{
	printf("\nBelow are the statistics about the set of data:\n");
	printf("The minimum value in the array is %d\n", minimum);
	printf("The maximum value in the array is %d\n", maximum);
	printf("The mean value in the array is %d\n", mean);
	printf("The median value in the array is %d\n", median);
}

void print_array(unsigned char* array, uint8_t array_size)
{
	for (uint8_t i = 0; i < array_size; i++)
		printf("%d ", array[i]);
	printf("\n");
}

void sort_array(unsigned char* array, uint8_t array_size)
{
	unsigned char temp;
	for (uint8_t i = 0; i < array_size; i++)
	{
		for (uint8_t j = i + 1; j < array_size; j++)
		{
			if (array[i] < array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
}