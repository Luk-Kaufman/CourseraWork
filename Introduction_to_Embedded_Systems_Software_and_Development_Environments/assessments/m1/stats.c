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
 * @brief performs data anaylsis on table
 * @author Luke Kaufman
 * @date 12/22/2024
 *
 */


#include <stdio.h>
#include "stats.h"

#define SIZE (40)

int main() {
    unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                                 114, 88,   45,  76, 123,  87,  25,  23,
                                 200, 122, 150, 90,   92,  87, 177, 244,
                                 201,   6,  12,  60,   8,   2,   5,  67,
                                  7,  87, 250, 230,  99,   3, 100,  90};

    sort_array(test, SIZE);
    print_statistics(test, SIZE);
    return 0;
}

// Function to print statistics of an array: min, max, mean, median
void print_statistics(unsigned char *array, int length) {
    printf("===== Array Statistics =====\n");
    printf("Maximum Value: %d\n", find_maximum(array, length));
    printf("Minimum Value: %d\n", find_minimum(array, length));
    printf("Mean Value: %.2f\n", find_mean(array, length));
    printf("Median Value: %d\n", find_median(array, length));
    printf("===========================\n");
}

// Function to print the array (optional)
void print_array(unsigned char *array, int length) {
    printf("Array Contents: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Function to find and return the median value of the array
int find_median(unsigned char *array, int length) {
    // Since the array is sorted, we can directly find the median
    if (length % 2 == 1) {
        return array[length / 2];  // For odd length, middle element
    }
    // For even length, average of the two middle elements
    return (array[length / 2] + array[length / 2 - 1]) / 2;
}

// Function to find and return the mean of the array
double find_mean(unsigned char *array, int length) {
    unsigned int sum = 0;  // Using unsigned int for sum to prevent overflow
    for (int i = 0; i < length; i++) {
        sum += array[i];
    }
    return (double)sum / length;  // Returning the mean as a double
}

// Function to find and return the maximum value in the array
int find_maximum(unsigned char *array, int length) {
    unsigned char max = array[0];  // Initialize to the first element
    for (int i = 1; i < length; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

// Function to find and return the minimum value in the array
int find_minimum(unsigned char *array, int length) {
    unsigned char min = array[0];  // Initialize to the first element
    for (int i = 1; i < length; i++) {
        if (array[i] < min) {
            min = array[i];
        }
    }
    return min;
}

// Function to sort the array from smallest to largest
void sort_array(unsigned char *array, int length) {
    for (int i = 0; i < length; i++) {
        unsigned char lowest = array[i];
        int pos = -1;
        for (int ptr = i; ptr < length; ptr++) {
            if (array[ptr] < lowest) {
                pos = ptr;
                lowest = array[ptr];
            }
        }
        if (pos > -1) {
            unsigned char temp = array[i];
            array[i] = lowest;
            array[pos] = temp;
        }
    }
}

