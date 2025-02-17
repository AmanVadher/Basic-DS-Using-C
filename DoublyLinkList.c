#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct {
    Node* head;
    Node* tail;
} DoublyLinkedList;

// Function prototypes
DoublyLinkedList* createList();
void insertFront(DoublyLinkedList* list, int data);
void insertRear(DoublyLinkedList* list, int data);
void deleteFront(DoublyLinkedList* list);
void deleteRear(DoublyLinkedList* list);
void display(DoublyLinkedList* list);

int main() {
    DoublyLinkedList* list = createList();
    int choice, data;

    do {
        printf("\nDoubly Linked List Operations:\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete at Front\n");
        printf("4. Delete at Rear\n");
        printf("5. Display\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert at the front: ");
                scanf("%d", &data);
                insertFront(list, data);
                break;

            case 2:
                printf("Enter the element to insert at the rear: ");
                scanf("%d", &data);
                insertRear(list, data);
                break;

            case 3:
                deleteFront(list);
                break;

            case 4:
                deleteRear(list);
                break;

            case 5:
                display(list);
                break;

            case 0:
                break;

            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 0);

    // Free the allocated memory
    Node* current = list->head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }

    free(list);

    return 0;
}

DoublyLinkedList* createList() {
    DoublyLinkedList* list = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));
    if (!list) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }

    list->head = list->tail = NULL;

    return list;
}

void insertFront(DoublyLinkedList* list, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }

    newNode->data = data;
    newNode->next = list->head;
    newNode->prev = NULL;

    if (list->head == NULL) {
        list->tail = newNode;
    } else {
        list->head->prev = newNode;
    }

    list->head = newNode;
}

void insertRear(DoublyLinkedList* list, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }

    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = list->tail;

    if (list->tail == NULL) {
        list->head = newNode;
    } else {
        list->tail->next = newNode;
    }

    list->tail = newNode;
}

void deleteFront(DoublyLinkedList* list) {
    if (list->head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    Node* temp = list->head;
    list->head = list->head->next;

    if (list->head == NULL) {
        list->tail = NULL;
    } else {
        list->head->prev = NULL;
    }

    free(temp);
}

void deleteRear(DoublyLinkedList* list) {
    if (list->tail == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    Node* temp = list->tail;
    list->tail = list->tail->prev;

    if (list->tail == NULL) {
        list->head = NULL;
    } else {
        list->tail->next = NULL;
    }

    free(temp);
}

void display(DoublyLinkedList* list) {
    if (list->head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* current = list->head;
    printf("Doubly Linked List: ");
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }

    printf("(null)\n");
}
