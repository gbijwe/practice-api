// Implementation of Merge Sort and Quick Sort using Divide & Conquer method. 
// Determine the time required to sort the elements in array.

// mergeSort function will be recursive so that the array can be divided multiple times until each element is in its own array.

#include <stdio.h>
#include <time.h>

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    } 
}

void merge(int arr[], int left, int mid, int right) {
    int h1 = mid - left + 1;
    int h2 = right - mid;

    int LEFT[h1], RIGHT[h2];

    for (int i = 0; i < h1; i++) 
        LEFT[i] = arr[left+i];
    for (int j = 0; j < h2; j++)
        RIGHT[j] = arr[mid + 1 +j];

    int i = 0, j = 0, k = left;

    while(i < h1 && j < h2) {
        if (LEFT[i] <= RIGHT[j]) {
            arr[k] = LEFT[i];
            i++;
        } else {
            arr[k] = RIGHT[j];
            j++;
        }
        k++;
    }

    while (i < h1) {
        arr[k] = LEFT[i];
        i++;
        k++;
    }

    while (j < h2) {
        arr[k] = RIGHT[j];
        j++;
        k++;
    }

}


void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        // Here we performed the first division part of divide and conquer method.
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);

        // Here we perform the conquer part of divide and conquer. 
        // Conquering means that we merge the divided arrays. The array is merged using merge function.

        merge(arr, left, mid, right);
    }
}

int main () {
    clock_t start, end;
    printf("Merge Sort using Divide & Conquer\n");
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
    mergeSort(arr, 0, size-1);
    end = clock();
    printf("The sorted array is: ");
    printArray(arr, size);
    printf("\n\nTime taken to sort the array: %f\n", (double)(end-start)/CLOCKS_PER_SEC);

    return 0;
}