#include <stdio.h>
#include <time.h>

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    } 
}

void swap(int* p1, int* p2)
{
    int temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int partition(int arr[], int low, int high)
{
    // choose the pivot
    int pivot = arr[high];

    // Index of smaller element and Indicate the right position of pivot found so far
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than the pivot
        if (arr[j] < pivot) {
            // Increment index of smaller element
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// The Quicksort function Implement

void quickSort(int arr[], int low, int high)
{
    // when low is less than high
    if (low < high) {
        // pi is the partition return index of pivot
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main () {
    clock_t start, end;
    printf("Quick Sort using Divide & Conquer\n");
    printf("Enter the size of the array: ");
    int size;
    scanf("%d", &size);
    int arr[size];
    int key;

    for (int i = 0; i < size; i++) {
        printf("Enter the element %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    printf("\nSorting array...time starts now:\n\n");
    start = clock();
    quickSort(arr, 0, size-1);
    end = clock();
    printf("The sorted array is: ");
    printArray(arr, size);
    printf("\n\nTime taken to sort the array: %f\n", (double)(end-start)/CLOCKS_PER_SEC);

    return 0;
}