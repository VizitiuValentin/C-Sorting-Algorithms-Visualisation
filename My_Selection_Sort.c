// Created this before I knew how the sort is called
// Its called selection sort.

// MY SORT 1 =============================================================================================================
void MySelectionSort ( int *array, int array_length)
{
    int temp, highest = -2147483646, highest_pos=0, runs=0;

    for (;;)
    {
        for (int i=runs; i <= array_length; i++) // Gaseste cel mai mare numar din array si il schimba cu primul din lista+nr_iteratii
        {
            if (array[i] > highest)
            {
                highest_pos = i;
                highest = array[highest_pos];
            }
        }

        temp = array[highest_pos];
        array[highest_pos] = array[runs];
        array[runs] = temp;

        runs++;
        highest = -2147483646;
        if (runs == array_length) break;
    }

}

