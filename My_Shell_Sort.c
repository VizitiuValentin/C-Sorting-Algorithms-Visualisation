// The same as Bubble sort, but it starts comparing elements from a distance of half the array size--; every run
// Will be faster than bubble sort

void myShellsort (int *array, int array_length)
{
    unsigned long int runs=0, comparasions=0;
    unsigned int i;
    int temp = 0;
    short flag=0;
    int distance_compare = array_length / 2; // Starts to compare numbers at a distance of half the array size

    for(;;)
    {
        if (distance_compare > 2) distance_compare--;
        for (i = 0, flag = 1, runs++; i <= array_length; i++) // Runs through the array once, sorting if needed
        {
            if (distance_compare-1+i > array_length) break;
            comparasions++; // Number of elements compared
            if (array[i] < array[i+distance_compare-1])
            {
                temp = array[i+distance_compare-1];
                array[i+distance_compare-1] = array[i];
                array[i] = temp;
                flag = 0;
            }

        }

        if (flag == 1) // If no comparisons are made break
        {
            /// printf("\nNumbers compared: %d\nRuns: %d", comparasions, runs); // To show how many things the sort did
            break;
        }
    }
}
