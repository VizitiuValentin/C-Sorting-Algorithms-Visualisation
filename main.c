#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#define ARRAY_SIZE 10000 // Change size for sorting larger lists

void randomize     ( int *array); // Fills the array with random numbers - or +
void printArray    ( int *array, int array_length); // Prints the numbers from the array
void ArraySum      ( int *array, int array_length); // Shows the sum of the element of the array

void MyBubbleSort   ( int *array, int array_length);
void MySelectionSort( int *array, int array_length);
void myShellsort    ( int *array, int array_length);
void MyRadixSort    ( int *array, int array_length);
void MyCountingSort ( int *array, int array_length);
void CocktailSort   ( int *array, int array_length);
void MyQuickSort    ( int *array, int start, int end);

//============================================================================================================================
int main()
{
    srand(time(0));
    long start, end;
    long array[ARRAY_SIZE];

    printf("The array will be randomized before each sort begins.\nSize of the list to be sorted: %d\n", ARRAY_SIZE);
    printf("\nTime taken to sort:\n");
//============================================================================================================================
// MY Quick Sort =============================================================================================================
    start = clock();

    randomize(array);
    MyQuickSort(array, 0, ARRAY_SIZE);

    end = clock();

    printf("\nMy Quick Sort sort time: %.2lf seconds\n", ((double)end-start)/CLOCKS_PER_SEC);
    printf("============================================\n");
//============================================================================================================================
// MY Radix Sort =============================================================================================================
    start = clock();

    randomize(array);
    MyRadixSort(array, ARRAY_SIZE);

    end = clock();

    printf("\nMy Radix Sort sort time: %.2lf seconds\n", ((double)end-start)/CLOCKS_PER_SEC);
    printf("============================================\n");
//=============================================================================================================================
// MY Counting Sort ===========================================================================================================
    start = clock();

    randomize(array);

    MyCountingSort(array, ARRAY_SIZE);

    end = clock();

    printf("\nMy Counting Sort sort time: %.2lf seconds\n", ((double)end-start)/CLOCKS_PER_SEC);
    printf("============================================\n");
//============================================================================================================================
// MY Selection Sort =========================================================================================================
    start = clock();

    randomize(array);
    MySelectionSort(array, ARRAY_SIZE);

    end = clock();

    printf("\nMy Selection Sort time: %.2lf seconds\n", ((double)end-start)/CLOCKS_PER_SEC);
    printf("============================================\n");
//============================================================================================================================
// MY Shell Sort =============================================================================================================
    start = clock();

    randomize(array);
    myShellsort(array, ARRAY_SIZE);

    end = clock();

    printf("\nMy Shell Sort sort time: %.2lf seconds\n", ((double)end-start)/CLOCKS_PER_SEC);
    printf("============================================\n");
//=============================================================================================================================
// MY Cocktail Sort =============================================================================================================
    start = clock();

    randomize(array);
    CocktailSort(array, ARRAY_SIZE);

    end = clock();
    printf("\nMy Cocktail Sort sort time: %.2lf seconds\n", ((double)end-start)/CLOCKS_PER_SEC);
    printf("============================================\n");
//=============================================================================================================================
// MY Bubble Sort =============================================================================================================
    start = clock();

    randomize(array);
    MyBubbleSort(array, ARRAY_SIZE);

    end = clock();

    printf("\nMy Bubble Sort sort time: %.2lf seconds\n", ((double)end-start)/CLOCKS_PER_SEC);
    printf("============================================\n");
    printf("Sorting finished.");

    while (1) getch();
}//END MAIN

//==============================================================================================
void randomize( int *array )
{
    short sign;
    int o = 0;
    for (; o <= ARRAY_SIZE ; o++)
    {
        sign = rand() % 2;
        if (sign == 0) array[o] = (rand() % ARRAY_SIZE);
        else if (sign == 1) array[o] = 1*(rand() % ARRAY_SIZE+1); // Add a - to the 1 to add negative numbers
    }
}
//==============================================================================================
void printArray    ( int *array, int array_length)
{
    printf("\n\n");
    for (int i =0; i <= array_length; i++)
        printf("%d, ", array[i]);
    printf("\n\n");
}
//==============================================================================================
void ArraySum( int *array, int array_length )
{
    unsigned long long sum = 0;
    for (int i = 0; i<=array_length ; i++)
        sum += array[i];
    printf("\nThe sum of the array is %llu.\n", sum);
}
