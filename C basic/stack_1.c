#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Khai báo cau trúc node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Khai báo cau trúc stack
typedef struct {
    Node* top;
} Stack;

// Hàm tao stack
void initializeStack(Stack* stack) {
    stack->top = NULL;
}

// Hàm kiem tra stack có rong hay không
int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

// Hàm thêm mot phan tu vào stack
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

// Hàm bot mot phan tu khoi stack
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

// Hàm chèn mot phan tu giua hai giá tri cu the trong stack
void insertBetweenValues(Stack* stack, int value, int value1, int value2) {
    Node* current = stack->top;
    Node* previous = NULL;

    // Tìm vi trí cua value1 và value2 trong stack
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


