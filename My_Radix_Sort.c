#define NL printf("\n");
#include <stdio.h>
#include <stdlib.h>

void swapArrays(long **array, long **swap_with); // Pointer magic

void MyRadixSort( int *array, int array_length)
{
    short flag_neg = 0;

    // Goes through the entire list checking for negative numbers
    for (int u = 0; u <= array_length; u++)
        if (array[u] < 0)
        {
            flag_neg = 1;
            break;
        }

//==================================================================
    // If the array had negative numbers recursively sorts them
    if (flag_neg == 1)
    {

        int positive_amount = -1, negative_amount = -1;

        for (int u = 0; u <= array_length; u++) // Counts how many positive and negative numbers there are
        {
            if (array[u] < 0) negative_amount++;
            if (array[u] >= 0) positive_amount++;
        }

        if (negative_amount == 0) negative_amount++; // If the array has only 1 element it needs to be created with 1
        if (positive_amount == 0) positive_amount++;

        long pos_array[positive_amount];
        long neg_array[negative_amount];

        // Puts the negative and positive numbers in auxiliary arrays
        // The negative numbers are multiplied by -1 so it becomes a positive number array
        for (int u = 0, k = 0, p = 0; u <= array_length; u++)
        {
            if (array[u] < 0)
            {
                neg_array[k] = array[u] * -1;
                k++;
            }
            else if (positive_amount > 0)
            {
                pos_array[p] = array[u];
                p++;
            }
        }
        // Recursively sorts the 2 arrays resulted
        MyRadixSort(neg_array, negative_amount);
        if (positive_amount > 0)
            MyRadixSort(pos_array, positive_amount);

        // Rebuilds the main array, but takes the neg array from end to start so the biggest numbers will be first
        // Since they will be with minus

        int u = 0, k = 0;
        for (; negative_amount >= 0; negative_amount--)
        {
            array[u] = -neg_array[negative_amount];
            u++;
        }

        if (positive_amount > 0)
            for (k = 0; k <= positive_amount ; u++, k++)
                array[u] = pos_array[k];
    }
//=======================================================================================
// Allocates memory for the output array =================================================
    else
    {
        long *output_array = (long*) malloc(sizeof(long) * array_length);

        if (output_array == 0LL) // 0LL = NULL
        {
            printf("Failed to allocate memory for the output array. Sorting aborted.\n");
        }
//========================================================================================
        else
        {
            int counters[10][2];
            int i, j, iterations_requred = 0;

            // Sees how many digits the largest number has
            for (int largest_nr = array_length; largest_nr > 0; iterations_requred++)
                largest_nr = largest_nr / 10;

            if (iterations_requred % 2 != 0) iterations_requred++; // If the number of iterations would be odd, makes it even

            for (int last_digit = 1; iterations_requred > 0; iterations_requred--) // Main loop
            {


                for (i = 0; i<= 9; i++) // Filling the counters array with the required stuff, and reseting them
                {
                    counters[i][0] = i;
                    counters[i][1] = 0;
                }

                // Counts the last-- digits of the numbers
                for (i=0; i <= array_length ; i++)
                {
                    if      (array[i] / last_digit % 10 == 0) counters[0][1]++;
                    else if (array[i] / last_digit % 10 == 1) counters[1][1]++;
                    else if (array[i] / last_digit % 10 == 2) counters[2][1]++;
                    else if (array[i] / last_digit % 10 == 3) counters[3][1]++;
                    else if (array[i] / last_digit % 10 == 4) counters[4][1]++;
                    else if (array[i] / last_digit % 10 == 5) counters[5][1]++;
                    else if (array[i] / last_digit % 10 == 6) counters[6][1]++;
                    else if (array[i] / last_digit % 10 == 7) counters[7][1]++;
                    else if (array[i] / last_digit % 10 == 8) counters[8][1]++;
                    else if (array[i] / last_digit % 10 == 9) counters[9][1]++;
                }

                // Prefix Sum magic

                counters[1][1] += counters[0][1];
                counters[2][1] += counters[1][1];
                counters[3][1] += counters[2][1];
                counters[4][1] += counters[3][1];
                counters[5][1] += counters[4][1];
                counters[6][1] += counters[5][1];
                counters[7][1] += counters[6][1];
                counters[8][1] += counters[7][1];
                counters[9][1] += counters[8][1];

                for (i = array_length; i >= 0 ; i--) // Goes from end to start, building the new array accordingly
                {
                    if      (array[i] / last_digit % 10 == 0)
                    {
                        counters[0][1]--;
                        output_array[counters[0][1]] = array[i];
                    }
                    else if (array[i] / last_digit % 10 == 1)
                    {
                        counters[1][1]--;
                        output_array[counters[1][1]] = array[i];
                    }
                    else if (array[i] / last_digit % 10 == 2)
                    {
                        counters[2][1]--;
                        output_array[counters[2][1]] = array[i];
                    }
                    else if (array[i] / last_digit % 10 == 3)
                    {
                        counters[3][1]--;
                        output_array[counters[3][1]] = array[i];
                    }
                    else if (array[i] / last_digit % 10 == 4)
                    {
                        counters[4][1]--;
                        output_array[counters[4][1]] = array[i];
                    }
                    else if (array[i] / last_digit % 10 == 5)
                    {
                        counters[5][1]--;
                        output_array[counters[5][1]] = array[i];
                    }
                    else if (array[i] / last_digit % 10 == 6)
                    {
                        counters[6][1]--;
                        output_array[counters[6][1]] = array[i];
                    }
                    else if (array[i] / last_digit % 10 == 7)
                    {
                        counters[7][1]--;
                        output_array[counters[7][1]] = array[i];
                    }
                    else if (array[i] / last_digit % 10 == 8)
                    {
                        counters[8][1]--;
                        output_array[counters[8][1]] = array[i];
                    }
                    else if (array[i] / last_digit % 10 == 9)
                    {
                        counters[9][1]--;
                        output_array[counters[9][1]] = array[i];
                    }
                }


                /*  Probably because the array that exits from the program is actually the output_array
                *   the program cant free the space allocated to the array when it exits the function, like
                *   you cant free the space of the array made by the pc
                */
                swapArrays(&array, &output_array); // Swaps the output array to the initial array

                last_digit *= 10; // Multiplies by 10 so it gets the next digit, like for 234, gets 4, next time 3, next time 2, etc
            } // END Main Loop

            // !!! At this point the main array has the pointer of the output_array !!!

            // The output array is made with dynamically allocated memory, this swaps the main array with the output one
            // so when it exits from the function the main array wont be the output_array by the pointer

            swapArrays(&array, &output_array);
            for (i = 0; i <= array_length; i++)
                array[i] = output_array[i];

        } // Memory successfully allocated ELSE END
    } // No negative numbers ELSE END
} // FUNCTION END
//========================================================================
void swapArrays(long **array, long **swap_with)
{
    long *temp = *array;
    *array = *swap_with;
    *swap_with = temp;
}
//========================================================================
