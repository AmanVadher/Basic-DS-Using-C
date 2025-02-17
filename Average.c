#include <stdio.h>

int main() {
    int arr[100]; 
    int size, i;
    double sum = 0.0;  

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter the elements of the array:\n");
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    double average = sum / size;

    printf("The average of the elements is: %.1lf\n", average);

    return 0;
}
