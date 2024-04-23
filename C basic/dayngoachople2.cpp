#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// �inh nghia cau truc cua mot node trong ngan xep
typedef struct node {
    char data; 
    struct node *next; // Con tro tro den node tiep theo
} node;

// �inh nghia cau tr�c cua ngan xep
typedef struct stack {
    node *top; // Con tro tro den node o dinh ngan xep
    int size; // Kich thuoc cua ngan xep
} stack;

// H�m khoi tao ngan xep rong
stack *create_stack() {
    stack *s = (stack *)malloc(sizeof(stack)); // Cap phat bo nho dong cho ngan xep
    s->top = NULL; // �at con tro top bang NULL
    s->size = 0; // �at kich thuic bang 0
    return s; // Tro ve con tro ngan xep
}

// H�m kiem tra ngan xep co rong hay khong
int is_empty(stack *s) {
    return s->size == 0; // Tro ve 1 neu kich thuoc bang 0, nguoc lai tro ve 0
}

// H�m them mot node v�o dinh ngan xep
void push(stack *s, char data) {
    node *new_node = (node *)malloc(sizeof(node)); // Cap phat bo nho dong cho node moi
    new_node->data = data; // Gan du lieu cho node moi
    new_node->next = s->top; // G�n con tro next cua node moi bang con tro top cua ngan xep
    s->top = new_node; // Cap nhat con tro top cua ngan xep bang con tro node moi
    s->size++; // Tang kich thuoc cua ngan xep l�n 1
}

// H�m lay mot node ra khoi dinh ngan xep v� tra ve du lieu cua node d�
char pop(stack *s) {
    if (is_empty(s)) { 
        printf("Stack underflow\n"); 
        return '\0';
    }
    else { 
        char data = s->top->data; // Lay du lieu cua node o dinh ngan xep
        node *temp = s->top; // Tao mot con tro tam de luu con tro top cua ngan xep
        s->top = s->top->next; // Cap nhat con tro top cua ngan xep bang con tro next cua node o dinh ngan xep
        free(temp); // Giai phong bo nho d� cap phat cho node o dinh ngan xep
        s->size--; // Gi?m k�ch thu?c c?a ngan x?p di 1
        return data; // Tra ve du lieu cua node da lay ra khoi ngan xep
    }
}

// H�m kiem tra hai k� tu ngoac c� khop nhau hay kh�ng
int is_match(char a, char b) {
    if (a == '(' && b == ')') return 1; 
    if (a == '[' && b == ']') return 1; 
    if (a == '{' && b == '}') return 1;
    return 0; 
}

// H�m kiem tra t�nh hop le cua mot d�y ngoac
int is_valid(char *str) {
    stack *s = create_stack(); // Tao mot ngan xep rong
    int i = 0; 
    while (str[i] != '\0') { // Lap cho den khi gap k� tu NULL
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') { // Neu k� tu hien tai l� ngoac mo
            push(s, str[i]); // Th�m k� tu do vao ngan xep
        }
        else if (str[i] == ')' || str[i] == ']' || str[i] == '}') { // Neu k� tu hien tai l� ngoac dong
            if (is_empty(s)) return 0; // Neu ngan xep rong, kh�ng co ngoac mo n�o de khop, tra ve 0
            char top = pop(s); // Lay ra k� tu o dinh ngan xep
            if (!is_match(top, str[i])) return 0; // Neu k� tu d� kh�ng khop voi k� tu hien tai, tra ve 0
        }
        i++; // Tang bien dem i l�n 1
    }
    return is_empty(s); // Tra ve ket qua kiem tra ngan xep c� rong hay kh�ng
}


int main() {
    char str[100]; 
    scanf("%s", str); 
    int result = is_valid(str);
    printf("%d\n", result); 
    return 0; 
}
