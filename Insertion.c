#include <stdio.h>

int main() {
    int arr[100]; 
    int size, pos, element, i;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter the elements of the array:\n");
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to insert: ");
    scanf("%d", &element);

    printf("Enter the position to insert the element (1-%d): ", size + 1);
    scanf("%d", &pos);

    if (pos < 1 || pos > size + 1) {
        printf("Invalid position. Insertion failed.\n");
    } else {
        
        for (i = size; i >= pos; i--) {
            arr[i] = arr[i - 1];
        }
        arr[pos - 1] = element; 
        size++; 

        printf("Element inserted successfully.\n");

        printf("Updated array:\n");
        for (i = 0; i < size; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    return 0;
}
