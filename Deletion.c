#include <stdio.h>

int main() {
    int arr[100]; 
    int size, pos, i;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter the elements of the array:\n");
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the position of the element to delete (1-%d): ", size);
    scanf("%d", &pos);

    if (pos < 1 || pos > size) {

        printf("Invalid position. Deletion failed.\n");

    } else {

        for (i = pos - 1; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--; 

        printf("Element at position %d deleted successfully.\n", pos);

        printf("Updated array:\n");
        for (i = 0; i < size; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    return 0;
}

// degtu.ac.in  or  open design tool
// aeiou framework
// mind map 
// ideation canvas
