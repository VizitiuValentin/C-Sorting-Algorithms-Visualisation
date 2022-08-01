// Goes from left to right swapping the elements if needed, then puts the largest element in place
// Then goes from right to left doing the same and putting the smallest element in place

void CocktailSort( int *array, int array_length)
{
    unsigned long int runs=0, comparasions=0;
    unsigned int i;
    int temp = 0;
    short flag=0;

    for(;;)
    {

        // LEFT -->>
        for (i = 0+runs, flag = 1; i < array_length; i++) // Runs through the array once, sorting if needed
        {
            comparasions++; // Number of elements compared
            if (array[i] > array[i+1])
            {
                temp = array[i+1];
                array[i+1] = array[i];
                array[i] = temp;
                flag = 0;
            }
        }

        // <<-- RIGHT
        for (i = array_length-runs, flag = 1; i >= 1; i--) // Runs through the array once, sorting if needed
        {
            comparasions++; // Number of elements compared
            if (array[i-1] > array[i])
            {
                temp = array[i-1];
                array[i-1] = array[i];
                array[i] = temp;
                flag = 0;
            }
        }

        if (runs+5 > array_length) runs = array_length-4;
        else runs++; // Number of times the array was read start to end
        if (flag == 1) // If no comparisons are made break
            break;
    }
}
