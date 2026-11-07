/*program to sort array elements in ascending order. */
#include <stdio.h>

/** function :   readArray() 
    input   :   arr ( array of integers ), size 
    to read a one-dimensional integer array from the standard input device (keyboard). 
**/
void readArray(int arr[], int size)
{
    int i = 0;

    printf("\nEnter elements : \n");

    for (i = 0; i < size; i++) {
        printf("Enter [%d] : ", i);
        scanf("%d", &arr[i]);
    }
}

/** funtion :   printArray() 
    input   :   arr ( array of integers ), size 
    to display a one-dimensional integer array on the standard output device (screen). 
**/
void printArray(int arr[], int size)
{
    int i = 0;

    printf("\nElements are : ");

    for (i = 0; i < size; i++) {
        printf("\n\t arr[%d] : %d", i, arr[i]);  // Note the symbol ‘\t’ produces a tab spacing in the screen output
    }
    printf("\n");
}

void sortArray(int arr[], int size)
{
    int i = 0, j = 0, temp;
    
    // This nested ‘for’ loop rearranges pairs of elements in ascending order by swapping them
   // Note that is uses a temporary variable for the swap
   // Note that the inner loop runs faster than the outer loop
    for (i = 0; i < size - 1; i++) {
        for (j = i + 1; j < size; j++) {
            if (arr[i] < arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main()
{
    int arr[5];

    readArray(arr, 5); 	//call to function for reading in the array elements values

    printf("\nBefore Sorting");
    printArray(arr, 5); 	//call to function to print array elements

    sortArray(arr, 5);	//call to function which sorts the array in ascending order

    printf("\nAfter Sorting");
    printArray(arr, 5);	//call to function to print array elements

    return 0;
}
