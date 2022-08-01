// Counts the number of numbers in the array and rebuilds it sorted
// Pretty good but requires another (or 2) array for storing the counts

// !!! If you want to sort only positive numbers modify it to remove the negative counter

// NEEDS HUGE AMOUNTS OF MEMEORY, but the fastest

#include <stdio.h>
#include <stdlib.h>

void MyCountingSort( int *array, int array_length)
{
    int i,j;

    // Creates an array of numbers and a count for them, as big as how many numbers there are in the array
    long countingArrayPOS[1+array_length][2];
    long countingArrayNEG[1+array_length][2];


    // Fills the array on position 0 with the number and on position 1 with the count, so 0 initially

    for (i=0; i<= array_length; i++) //Count for positive numbers
    {
        countingArrayPOS[i][0] = i;
        countingArrayPOS[i][1] = 0;
    }
    for (i=1; i <= array_length; i++) // Count for negative numbers
    {
        countingArrayNEG[i][0] = i*-1;
        countingArrayNEG[i][1] = 0;
    }

    // Now counts the initial array for numbers
    for (i=j=0 ; i <= array_length ;i++)
    {
        if (array[i] > -1) countingArrayPOS[array[i]][1]++;
        if (array[i] < 0 ) countingArrayNEG[array[i]*-1][1]++;
    }


    // Now rebuilds the main array using the counts
    for (i = array_length, j=0; i >= 1; i--)
    {
        while ( countingArrayNEG[i][1] )
        {
            array[j] = countingArrayNEG[i][0];
            j++;
            countingArrayNEG[i][1]--;
        }
    }

    for (i=0; i <= array_length; i++)
    {
        while ( countingArrayPOS[i][1] )
        {
            array[j] = countingArrayPOS[i][0];
            j++;
            countingArrayPOS[i][1]--;
        }
    }
}
