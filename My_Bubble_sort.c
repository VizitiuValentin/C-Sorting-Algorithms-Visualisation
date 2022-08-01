// MY Bubble Sort =============================================================================================================
void MyBubbleSort( int *array, int array_length)
{
    unsigned long int runs=0, comparasions=0;
    unsigned int i;
    int temp = 0;
    short flag=0;

    for(;;)
    {
        runs++; // Number of times the array was read start to end
        for (i = 0, flag = 1; i <= array_length; i++) // Runs through the array once, sorting if needed
        {
            comparasions++; // Number of elements compared
            if (array[i] < array[i+1])
            {
                temp = array[i+1];
                array[i+1] = array[i];
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
