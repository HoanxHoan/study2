#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Khai báo cau trúc stack
typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

// Hàm tao stack
void initializeStack(Stack *stack) {
    stack->top = -1; // Ðinh cua stack duoc khoi tao là -1 de dánh dau stack rong
}

// Hàm kiem tra stack có rong hay không
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Hàm kiem tra stack có day hay không
int isFull(Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

// Hàm thêm mot phan tu vào stack
void push(Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
    } else {
        stack->top++;
        stack->items[stack->top] = value;
        printf("Pushed %d to the stack\n", value);
    }
}

// Hàm bot mot phan tu khoi stack
void pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
    } else {
        printf("Popped %d from the stack\n", stack->items[stack->top]);
        stack->top--;
    }
}
// Hàm chèn mot phan tu vào vi trí cu the trong stack
void insertAt(Stack *stack, int value, int position) {
    if (isFull(stack) || position < 0 || position > stack->top + 1) {
        printf("Invalid insertion position or stack overflow\n");
    } else {
        // Dich chuyen phan tu phía sau vi trí can chèn de tao khoang trong
        for (int i = stack->top + 1; i > position; i--) {
            stack->items[i] = stack->items[i - 1];
        }

        // Chèn phan tu moi vào vi trí can chèn
        stack->items[position] = value;

        // Tang dinh cua stack
        stack->top++;

        printf("Inserted %d at position %d\n", value, position);
    }
}
// Hàm chèn mot phan tu giua hai giá tri cu the trong stack
void insertBetweenValues(Stack *stack, int value, int value1, int value2) {
    int position = -1;

    // Tìm vi trí cua value1 và value2 trong stack
    for (int i = 0; i <= stack->top; i++) {
        if (stack->items[i] == value1 && i < stack->top && stack->items[i + 1] == value2) {
            position = i + 1; // Chèn giua value1 và value2
            break;
        }
    }

    if (position != -1) {
        insertAt(stack, value, position);
    } else {
        printf("Values not found in the stack\n");
    }
}
