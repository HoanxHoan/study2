#include <stdio.h>
typedef struct Node{
char c;
struct Node* next;
}Node;
Node* top;
typedef struct stack {
    node *top; 
    int size; 
} stack;
stack *create_stack() {
    stack *s = (stack *)malloc(sizeof(stack)); 
    s->top = NULL; 
    s->size = 0; 
    return s;
}
int is_empty(stack *s) {
    return s->size == 0; // Tr? v? 1 n?u kích thu?c b?ng 0, ngu?c l?i tr? v? 0
}
int stackEmpty(){
return top == NULL;
}
void push(char x){
Node* p = makeNode(x);
p->next = top; top = p;
}

char pop(){
if(stackEmpty()) return ' ';
char x = top->c;
Node* tmp = top; top = top->next; free(tmp);
return x;
}
int match(char a, char b){
if(a == '(' && b == ')') return 1;
if(a == '[' && b == ']') return 1;
if(a == '{' && b == '}') return 1;
return 0;
}
int check(char* s){
stack *s = create_stack();
for(int i = 0; i < strlen(s); i++){
if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
push(s[i]);
}else{
if(stackEmpty()) return 0;
char x = pop();
if(!match(x,s[i])) {
printf("0\n");
break;}
}
 else if (str[i] == ')' || str[i] == ']' || str[i] == '}') {
}
if (is_empty(s)) return 0;
return stackEmpty();
}
int main()
{
	char stack[100];
	scanf("%s",stack);
	check(stack);
}
