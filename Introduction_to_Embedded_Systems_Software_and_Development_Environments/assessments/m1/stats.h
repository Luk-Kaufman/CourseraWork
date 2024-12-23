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
 * @file <Add File Name> 
 * @brief <Add Brief Description Here >
 *
 * <Add Extended Description Here>
 *
 * @author <Add FirsName LastName>
 * @date <Add date >
 *
 */

#ifndef STATS_H
#define STATS_H

#ifndef STATS_H
#define STATS_H

// Function to print statistics of an array: min, max, mean, median
void print_statistics(unsigned char *array, int length);

// Function to print the array
void print_array(unsigned char *array, int length);

// Function to find and return the median value of the array
int find_median(unsigned char *array, int length);

// Function to find and return the mean of the array
double find_mean(unsigned char *array, int length);

// Function to find and return the maximum value in the array
int find_maximum(unsigned char *array, int length);

// Function to find and return the minimum value in the array
int find_minimum(unsigned char *array, int length);

// Function to sort the array from smallest to largest
void sort_array(unsigned char *array, int length);

#endif // STATS_H
// Function prototypes
