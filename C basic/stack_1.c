#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Khai b�o cau tr�c node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Khai b�o cau tr�c stack
typedef struct {
    Node* top;
} Stack;

// H�m tao stack
void initializeStack(Stack* stack) {
    stack->top = NULL;
}

// H�m kiem tra stack c� rong hay kh�ng
int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

// H�m th�m mot phan tu v�o stack
void push(Stack* stack, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;

    printf("Pushed %d to the stack\n", value);
}

// H�m bot mot phan tu khoi stack
void pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
    } else {
        Node* temp = stack->top;
        stack->top = stack->top->next;
        printf("Popped %d from the stack\n", temp->data);
        free(temp);
    }
}

// H�m ch�n mot phan tu giua hai gi� tri cu the trong stack
void insertBetweenValues(Stack* stack, int value, int value1, int value2) {
    Node* current = stack->top;
    Node* previous = NULL;

    // T�m vi tr� cua value1 v� value2 trong stack
    while (current != NULL) {
        if (current->data == value1 && current->next != NULL && current->next->data == value2) {
            Node* newNode = (Node*)malloc(sizeof(Node));
            if (newNode == NULL) {
                printf("Memory allocation failed\n");
                return;
            }

            newNode->data = value;
            newNode->next = current->next;
            current->next = newNode;

            printf("Inserted %d between %d and %d\n", value, value1, value2);
            return;
        }

        previous = current;
        current = current->next;
    }

    printf("Values not found in the stack\n");
}


