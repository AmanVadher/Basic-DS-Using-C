#include <stdio.h>
#include <stdlib.h>

#define INITIAL_SIZE 5

typedef struct {
    int *arr;
    int front, rear;
    int capacity;
} CircularQueue;

// Function prototypes
CircularQueue* createQueue();
int isFull(CircularQueue* queue);
int isEmpty(CircularQueue* queue);
void enqueue(CircularQueue* queue, int data);
int dequeue(CircularQueue* queue);
void display(CircularQueue* queue);
void resizeQueue(CircularQueue* queue);

int main() {
    CircularQueue* queue = createQueue();
    int choice, data;

    do {
        printf("\nCircular Queue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &data);
                enqueue(queue, data);
                break;

            case 2:
                data = dequeue(queue);
                if (data != -1) {
                    printf("Dequeued element: %d\n", data);
                }
                break;

            case 3:
                display(queue);
                break;

            case 0:
                break;

            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 0);

    free(queue->arr);
    free(queue);

    return 0;
}

CircularQueue* createQueue() {
    CircularQueue* queue = (CircularQueue*)malloc(sizeof(CircularQueue));
    if (!queue) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }

    queue->arr = (int*)malloc(INITIAL_SIZE * sizeof(int));
    if (!queue->arr) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }

    queue->front = queue->rear = -1;
    queue->capacity = INITIAL_SIZE;

    return queue;
}

int isFull(CircularQueue* queue) {
    return ((queue->rear + 1) % queue->capacity == queue->front);
}

int isEmpty(CircularQueue* queue) {
    return (queue->front == -1);
}

void enqueue(CircularQueue* queue, int data) {
    if (isFull(queue)) {
        resizeQueue(queue);
    }

    if (isEmpty(queue)) {
        queue->front = queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % queue->capacity;
    }

    queue->arr[queue->rear] = data;
}

int dequeue(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }

    int data = queue->arr[queue->front];

    if (queue->front == queue->rear) {
        // Only one element in the queue
        queue->front = queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % queue->capacity;
    }

    return data;
}

void display(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }

    int i = queue->front;
    printf("Queue elements: ");
    do {
        printf("%d ", queue->arr[i]);
        i = (i + 1) % queue->capacity;
    } while (i != (queue->rear + 1) % queue->capacity);

    printf("\n");
}

void resizeQueue(CircularQueue* queue) {
    int newCapacity = 2 * queue->capacity;
    int *newArr = (int*)malloc(newCapacity * sizeof(int));

    if (!newArr) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }

    int i = 0, j = queue->front;
    do {
        newArr[i++] = queue->arr[j];
        j = (j + 1) % queue->capacity;
    } while (j != (queue->rear + 1) % queue->capacity);

    free(queue->arr);
    queue->arr = newArr;
    queue->front = 0;
    queue->rear = queue->capacity - 1;
    queue->capacity = newCapacity;
}
