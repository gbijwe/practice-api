#include <stdio.h>

int binarySearcy(int arr[], int key, int size) {
    int low = 0;
    int high = size - 1;
    int mid;

    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

void sortArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}   

int main () {
    printf("Binary Search using Divide & Conquer\n");
    printf("Enter the size of the array: ");
    int size;
    scanf("%d", &size);
    int arr[size];
    int key;

    for (int i = 0; i < size; i++) {
        printf("Enter the element %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    printf("Sorting array...\n");
    sortArray(arr, size);

    printf("Enter the key to search: ");
    scanf("%d", &key);

    int index = binarySearcy(arr, key, size);

    if (index == -1) 
        printf("Element not found in array\n");
    else 
        printf("Element found at index %d\n", index);

    return 0;
}