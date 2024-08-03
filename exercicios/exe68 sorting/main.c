#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[], int max);
void swap(int *a, int *b);
void bubbleSort(int arr[], int max);
void insertionSort(int arr[], int max);
void selectionSort(int arr[], int max);
int partition(int arr[], int start, int end);
void quickSort(int arr[], int start, int end);
void merge(int leftArray[], int leftSize, int rightArray[], int rightSize, int arr[]);
void mergeSort(int arr[], int max);

int main(void)
{
    system("cls");

    int array[5] = {15, 16, 6, 8, 5};
    const int size = sizeof(array) / sizeof(array[0]);

    printf("Before: ");
    printArray(array, size);

    //bubbleSort(array, size);
    //insertionSort(array, size);
    //selectionSort(array, size);
    //quickSort(array, 0, size - 1);
    mergeSort(array, size);

    printf("After: ");
    printArray(array, size);

    return 0;
}

void printArray(int arr[], int max)
{
    for (int i = 0; i < max; i++)
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

int partition(int arr[], int start, int end)
{
    int pivot = arr[end];
    int i = start - 1;

    for (int j = start; j <= end - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    i++;
    swap(&arr[i], &arr[end]);

    return i;
}

void quickSort(int arr[], int start, int end)
{
    if (end <= start) return; // Base case

    int pivot = partition(arr, start, end);
    quickSort(arr, start, pivot - 1);
    quickSort(arr, pivot + 1, end);

}

void merge(int leftArray[], int leftSize, int rightArray[], int rightSize, int arr[])
{
    int i = 0, l = 0, r = 0; // Indices

    while (l < leftSize && r < rightSize)
    {
        if (leftArray[l] < rightArray[r])
        {
            arr[i] = leftArray[l];
            i++;
            l++;
        }
        else
        {
            arr[i] = rightArray[r];
            i++;
            r++;
        }
    }
    while (l < leftSize)
    {
        arr[i] = leftArray[l];
        i++;
        l++;
    }
    while (r < rightSize)
    {
        arr[i] = rightArray[r];
        i++;
        r++;
    }
}

void mergeSort(int arr[], int max)
{
    if (max <= 1) return; // Base case

    int middle = max / 2;

    int leftSize = middle;
    int rightSize = max - middle;

    int *leftArray = malloc(leftSize * sizeof(int));
    int *rightArray = malloc(rightSize * sizeof(int));
    if(leftArray == NULL || rightArray == NULL)
    {
        printf("Erro ao alocar memoria\n");
        return;
    }
    
    int j = 0; // Right array
    for (int i = 0; i < max; i++) // Left array
    {
        if (i < middle)
        {
            leftArray[i] = arr[i];
        }
        else
        {
            rightArray[j] = arr[i];
            j++;
        }
    }

    mergeSort(leftArray, leftSize);
    mergeSort(rightArray, rightSize);

    merge(leftArray, leftSize, rightArray, rightSize, arr);

    free(leftArray);
    free(rightArray);
}

