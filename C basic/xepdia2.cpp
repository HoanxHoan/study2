#include <stdio.h> 
int stack[100];
int top;
void push(int x) {
    top++;
    stack[top] = x;
}
int pop() {
    int x = stack[top]; 
    top--;
    return x;
}
int main() 
{ 
char op[10]; 
    int x,y[100],i=0; 
    while (1) {
        scanf("%s", op); 
        if (op[0] == '#') break; 
        if (op[0] == 'I') { 
            scanf("%d", &x); 
            push(x); 
        }
        if (op[0] == 'O') { 
            x = pop();
            i++;
            y[i-1] = x;
        }
    }
   for(int j=0;j<=i-1;j++){printf("%d\n",y[j]); }        
    return 0;

}

