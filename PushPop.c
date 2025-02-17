#include <stdio.h>
#include <stdlib.h>

#define size 100 

int stack[size];
int top = -1;

void push(int value) {
    if (top == size - 1) {
        printf("Stack is full. Cannot push more elements.\n");
    } else {
        top++;
        stack[top] = value;
        printf("%d pushed onto the stack.\n", value);
    }
}

int pop() {
    if (top == -1) {
        printf("Stack is empty. Cannot pop.\n");
        return -1; 
    } else {
        int x = stack[top];
        top--;
        return x;
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a value to push onto the stack: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                value = pop();
                if (value != -1) {
                    printf("%d popped from the stack.\n", value);
                }
                break;
            case 3:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}