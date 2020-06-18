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
 * @file stats.h
 * @brief contains the function declarations used in stats.
 *
 * This assignment proposed a code that analyzes an array of unsigned char data
 * and report on the max, min, mean and medium of the data set. The data set is
 * also reordered from large to small.
 *
 * @author Anna Nunes
 * @date 06/17/2020
 *
 */
#ifndef __STATS_H__
#define __STATS_H__
#include <stdint.h>

/* Add Your Declarations and Function Comments here */ 
/* find_mean():  Given an array of data and a length, returns the mean */
uint16_t find_mean(unsigned char* array, uint8_t array_size);

/* find_maximum(): Given an array of data and a length, returns the maximum */
uint16_t find_maximum(unsigned char* array, uint8_t array_size);

/* find_minimum(): Given an array of data and a length, returns the minimum */
uint16_t find_minimum(unsigned char* array, uint8_t array_size);

/* find_median(): Given an array of data and a length, returns the median */
uint16_t find_median(unsigned char* array, uint8_t array_size);

/* print_statistics(): A function that prints the statistics of an array
* including minimum, maximum, mean, and median. */
void print_statistics(uint16_t minimum, uint16_t maximum, uint16_t mean, uint16_t median);

/* print_array(): Given an array of data and a length, prints the array to the
* screen */
void print_array(unsigned char* array, uint8_t array_size);

/* sort_array(): Given an array of data and a length, sorts the array from
* largest to smallest */
void sort_array(unsigned char* array, uint8_t array_size);

/**
 *
 * @param array array of elements to be analyzed
 * @param array_size size of the array
 * @param minimum smallest value in the analyzed array
 * @param maximum greatest value in the analyzed array
 * @param mean mean value of the analyzed array
 * @param median median value of the analyzed array
 *
 */


#endif /* __STATS_H__ */
