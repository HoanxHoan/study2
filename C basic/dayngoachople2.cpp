#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Ðinh nghia cau truc cua mot node trong ngan xep
typedef struct node {
    char data; 
    struct node *next; // Con tro tro den node tiep theo
} node;

// Ðinh nghia cau trúc cua ngan xep
typedef struct stack {
    node *top; // Con tro tro den node o dinh ngan xep
    int size; // Kich thuoc cua ngan xep
} stack;

// Hàm khoi tao ngan xep rong
stack *create_stack() {
    stack *s = (stack *)malloc(sizeof(stack)); // Cap phat bo nho dong cho ngan xep
    s->top = NULL; // Ðat con tro top bang NULL
    s->size = 0; // Ðat kich thuic bang 0
    return s; // Tro ve con tro ngan xep
}

// Hàm kiem tra ngan xep co rong hay khong
int is_empty(stack *s) {
    return s->size == 0; // Tro ve 1 neu kich thuoc bang 0, nguoc lai tro ve 0
}

// Hàm them mot node vào dinh ngan xep
void push(stack *s, char data) {
    node *new_node = (node *)malloc(sizeof(node)); // Cap phat bo nho dong cho node moi
    new_node->data = data; // Gan du lieu cho node moi
    new_node->next = s->top; // Gán con tro next cua node moi bang con tro top cua ngan xep
    s->top = new_node; // Cap nhat con tro top cua ngan xep bang con tro node moi
    s->size++; // Tang kich thuoc cua ngan xep lên 1
}

// Hàm lay mot node ra khoi dinh ngan xep và tra ve du lieu cua node dó
char pop(stack *s) {
    if (is_empty(s)) { 
        printf("Stack underflow\n"); 
        return '\0';
    }
    else { 
        char data = s->top->data; // Lay du lieu cua node o dinh ngan xep
        node *temp = s->top; // Tao mot con tro tam de luu con tro top cua ngan xep
        s->top = s->top->next; // Cap nhat con tro top cua ngan xep bang con tro next cua node o dinh ngan xep
        free(temp); // Giai phong bo nho dã cap phat cho node o dinh ngan xep
        s->size--; // Gi?m kích thu?c c?a ngan x?p di 1
        return data; // Tra ve du lieu cua node da lay ra khoi ngan xep
    }
}

// Hàm kiem tra hai ký tu ngoac có khop nhau hay không
int is_match(char a, char b) {
    if (a == '(' && b == ')') return 1; 
    if (a == '[' && b == ']') return 1; 
    if (a == '{' && b == '}') return 1;
    return 0; 
}

// Hàm kiem tra tính hop le cua mot dãy ngoac
int is_valid(char *str) {
    stack *s = create_stack(); // Tao mot ngan xep rong
    int i = 0; 
    while (str[i] != '\0') { // Lap cho den khi gap ký tu NULL
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') { // Neu ký tu hien tai là ngoac mo
            push(s, str[i]); // Thêm ký tu do vao ngan xep
        }
        else if (str[i] == ')' || str[i] == ']' || str[i] == '}') { // Neu ký tu hien tai là ngoac dong
            if (is_empty(s)) return 0; // Neu ngan xep rong, không co ngoac mo nào de khop, tra ve 0
            char top = pop(s); // Lay ra ký tu o dinh ngan xep
            if (!is_match(top, str[i])) return 0; // Neu ký tu dó không khop voi ký tu hien tai, tra ve 0
        }
        i++; // Tang bien dem i lên 1
    }
    return is_empty(s); // Tra ve ket qua kiem tra ngan xep có rong hay không
}


int main() {
    char str[100]; 
    scanf("%s", str); 
    int result = is_valid(str);
    printf("%d\n", result); 
    return 0; 
}
