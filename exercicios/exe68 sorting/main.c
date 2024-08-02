#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[], int max);
void swap(int *a, int *b);
void bubbleSort(int arr[], int max);
void insertionSort(int arr[], int max);
void selectionSort(int arr[], int max);

int main(void)
{
    system("cls");

    int array[5] = {15, 16, 6, 8, 5};
    const int size = sizeof(array) / sizeof(array[0]);

    printf("Before: ");
    printArray(array, size);

    //bubbleSort(array, size);
    //insertionSort(array, size);
    selectionSort(array, size);

    printf("After: ");
    printArray(array, size);

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

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int max)
{
    int temp, flag;
     
    for (int i = 0; i < max - 1; i++)
    {
        flag = 0;
        for (int j = 0; j < max - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 1;
            }
        }

        if (flag == 0)
            break;
    }
}

void insertionSort(int arr[], int max)
{
    int temp, index;
    
    for (int i = 1; i < max; i++)
    {
        temp = arr[i];
        index = i;

        while (index > 0 && arr[index - 1] > temp)
        {
            arr[index] = arr[index - 1];
            index--;
        }
        arr[index] = temp;
    }
}

void selectionSort(int arr[], int max)
{
    for (int i = 0; i < max - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < max; j++)
        {
           if (arr[min] > arr[j]) 
           {
               min = j;
           }
        }

        if (min != i)
        {
            swap(&arr[i], &arr[min]);
        }
    }
}

