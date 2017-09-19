/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // Implement a binary search
    // Retrieve first elem, last elem
    int min = 0;
    int max = n-1;

    // While array is still sorted
    while (max >= min)
    {
        // Get middle of array
        int mid = (max+min)/2;
        // If value = middle, true
        if(values[mid] == value)
        {
            return true;
        }

        if(value > values[mid])
        {
            min = mid + 1;
        }
        else
        {
            max = mid - 1;
        }

    }
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement a sorting algorithm
    return;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // Implement bubble sort algorithm
    // Loop through array
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if values[j] > values[j+1]
            {
                int temp = values[j];
                values[j] = values[j+1];
                values[j+1] = temp;
            }
        }
    }
    return;
}






