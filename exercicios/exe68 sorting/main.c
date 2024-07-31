#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[], int max);
void bubbleSort(int arr[], int max);

int main(void)
{
    system("cls");

    int array[5] = {15, 16, 6, 8, 5};
    const int size = sizeof(array) / sizeof(array[0]);

    printf("Before: ");
    printArray(array, size);

    bubbleSort(array, size);
    
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

