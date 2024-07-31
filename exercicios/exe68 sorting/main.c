#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[], int max);
void bubbleSort(int arr[], int max);

int main(void)
{
    system("cls");

    int array[5] = {15, 16, 6, 8, 5};

    printf("Before: ");
    printArray(array, 5);

    bubbleSort(array, 5);
    
    printf("After: ");
    printArray(array, 5);

    return 0;
}

void printArray(int arr[], int max)
{
    for (int i = 0; i <= max - 1; i++)
    {
        printf("%i ", arr[i]);
    }
    printf("\n");
}

void bubbleSort(int arr[], int max)
{
    int temp;
     
    for (int i = 0; i < max - 1; i++)
    {
        for (int j = 0; j < max - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

