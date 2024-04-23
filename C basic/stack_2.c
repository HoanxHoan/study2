#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Khai b�o cau tr�c stack
typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

// H�m tao stack
void initializeStack(Stack *stack) {
    stack->top = -1; // �inh cua stack duoc khoi tao l� -1 de d�nh dau stack rong
}

// H�m kiem tra stack c� rong hay kh�ng
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

// H�m kiem tra stack c� day hay kh�ng
int isFull(Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

// H�m th�m mot phan tu v�o stack
void push(Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
    } else {
        stack->top++;
        stack->items[stack->top] = value;
        printf("Pushed %d to the stack\n", value);
    }
}

// H�m bot mot phan tu khoi stack
void pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
    } else {
        printf("Popped %d from the stack\n", stack->items[stack->top]);
        stack->top--;
    }
}
// H�m ch�n mot phan tu v�o vi tr� cu the trong stack
void insertAt(Stack *stack, int value, int position) {
    if (isFull(stack) || position < 0 || position > stack->top + 1) {
        printf("Invalid insertion position or stack overflow\n");
    } else {
        // Dich chuyen phan tu ph�a sau vi tr� can ch�n de tao khoang trong
        for (int i = stack->top + 1; i > position; i--) {
            stack->items[i] = stack->items[i - 1];
        }

        // Ch�n phan tu moi v�o vi tr� can ch�n
        stack->items[position] = value;

        // Tang dinh cua stack
        stack->top++;

        printf("Inserted %d at position %d\n", value, position);
    }
}
// H�m ch�n mot phan tu giua hai gi� tri cu the trong stack
void insertBetweenValues(Stack *stack, int value, int value1, int value2) {
    int position = -1;

    // T�m vi tr� cua value1 v� value2 trong stack
    for (int i = 0; i <= stack->top; i++) {
        if (stack->items[i] == value1 && i < stack->top && stack->items[i + 1] == value2) {
            position = i + 1; // Ch�n giua value1 v� value2
            break;
        }
    }

    if (position != -1) {
        insertAt(stack, value, position);
    } else {
        printf("Values not found in the stack\n");
    }
}
