#include <stdio.h>
#define MAX 100 // S? dia t?i da

// Khai báo bi?n toàn c?c
int stack[MAX]; // M?ng luu tr? các dia
int top = -1; // Bi?n luu tr? s? lu?ng dia hi?n có

// Hàm ki?m tra ngan x?p r?ng
int isEmpty() {
    return top == -1;
}

// Hàm ki?m tra ngan x?p d?y
int isFull() {
    return top == MAX - 1;
}

// Hàm thêm m?t dia vào ngan x?p
void push(int x) {
    if (isFull()) {
        printf("Ngan x?p dã d?y!\n");
        return;
    }
    top++; // Tang s? lu?ng dia lên 1
    stack[top] = x; // Luu s? x vào v? trí m?i
}

// Hàm l?y m?t dia ra kh?i ngan x?p
int pop() {
    if (isEmpty()) {
        printf("Ngan x?p dã r?ng!\n");
        return -1;
    }
    int x = stack[top]; // L?y s? ? v? trí d?nh ngan x?p
    top--; // Gi?m s? lu?ng dia di 1
    return x;
}
int main() {
    char op[10]; // M?ng luu tr? thao tác
    int x; // Bi?n luu tr? s? trên dia
    while (1) {
        scanf("%s", op); // Nh?p thao tác t? bàn phím
        if (op[0] == '#') break; // N?u là ký t? # thì d?ng vòng l?p
        if (op[0] == 'I') { // N?u là thao tác INPUT
            scanf("%d", &x); // Nh?p s? trên dia t? bàn phím
            push(x); // Thêm dia vào ngan x?p
        }
        if (op[0] == 'O') { // N?u là thao tác OUTPUT
            x = pop(); // L?y dia ra kh?i ngan x?p
            if (x != -1) printf("%d\n", x); // In ra s? trên dia n?u có
        }
    }
    return 0;
}
