#include <stdio.h>

// Function to perform linear search
int linear_search(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;  // Return -1 if the element is not found
}

int main() {
    int array[] = {1, 4, 7, 9, 12};
    int size = sizeof(array) / sizeof(array[0]);
    int target = 9;

    int index = linear_search(array, size, target);

    if (index != -1) {
        printf("Element found at index: %d\n", index);
    } else {
        printf("Element not found\n");
    }

    return 0;
}