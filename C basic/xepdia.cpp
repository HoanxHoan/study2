#include <stdio.h>
#define MAX 100 // S? dia t?i da

// Khai b�o bi?n to�n c?c
int stack[MAX]; // M?ng luu tr? c�c dia
int top = -1; // Bi?n luu tr? s? lu?ng dia hi?n c�

// H�m ki?m tra ngan x?p r?ng
int isEmpty() {
    return top == -1;
}

// H�m ki?m tra ngan x?p d?y
int isFull() {
    return top == MAX - 1;
}

// H�m th�m m?t dia v�o ngan x?p
void push(int x) {
    if (isFull()) {
        printf("Ngan x?p d� d?y!\n");
        return;
    }
    top++; // Tang s? lu?ng dia l�n 1
    stack[top] = x; // Luu s? x v�o v? tr� m?i
}

// H�m l?y m?t dia ra kh?i ngan x?p
int pop() {
    if (isEmpty()) {
        printf("Ngan x?p d� r?ng!\n");
        return -1;
    }
    int x = stack[top]; // L?y s? ? v? tr� d?nh ngan x?p
    top--; // Gi?m s? lu?ng dia di 1
    return x;
}
int main() {
    char op[10]; // M?ng luu tr? thao t�c
    int x; // Bi?n luu tr? s? tr�n dia
    while (1) {
        scanf("%s", op); // Nh?p thao t�c t? b�n ph�m
        if (op[0] == '#') break; // N?u l� k� t? # th� d?ng v�ng l?p
        if (op[0] == 'I') { // N?u l� thao t�c INPUT
            scanf("%d", &x); // Nh?p s? tr�n dia t? b�n ph�m
            push(x); // Th�m dia v�o ngan x?p
        }
        if (op[0] == 'O') { // N?u l� thao t�c OUTPUT
            x = pop(); // L?y dia ra kh?i ngan x?p
            if (x != -1) printf("%d\n", x); // In ra s? tr�n dia n?u c�
        }
    }
    return 0;
}
