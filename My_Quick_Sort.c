// Quick Sort - VIZITIU VALENTIN IULIAN
// Sometimes a bug appears with the value returned by the main, but still sorts the array correctly

/* 1. Picks the last element in the list as a "pivot"
*  2. Goes through the list and swaps the smallest elements from the left side with the largest elements on the right side
*    ,when it reaches the same point in the array, swaps the number at that point with the pivot
*  3. Splits the main array into 2 smaller arrays, one from 0 to the pivot-1, and the other array from pivot+1 to the end of the array
*  4. RECURSIVELY sorts the 2 new arrays with Quick Sort, applying the same algorithm
*  5. If the array size to be sorted is 1, it stops, as this array is already sorted
*/
void MyQuickSort    ( int *array, int start, int end)
{
        // Takes the last element as pivot, so array[end]

        int i = start, j = end; // Sets the pointers, one at the start of the array, and j at the end
        int temp;

        while (i < j)
        {
            while (array[i] <  array[end]) i++; // Finds the first element greater then the pivot
            while (array[j] >= array[end] && j > i) j--; // Finds the first element smaller then the pivot

            if (i != j) // If j and i are "pointing" to the same position, it skips the swap
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
        // Swaps the pivot and the element on array[i]
        temp = array[i];
        array[i] = array[end];
        array[end] = temp;

        // Recursively sorts the 2 new arrays, excluding the pivot
        // IF the array to be sorted would have only 1 element, it skips sorting it
        if (i - start > 1)
        MyQuickSort(array, start, i-1); // Array from start of array TO pivot-1

        if (end - i > 1)
        MyQuickSort(array, i+1, end); // Array from pivot+1 TO end of array
}

