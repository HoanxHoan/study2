#include <stdio.h>
int queue[100];
int front=0,rear=0;

void Enqueue(int n) {
	
         queue[rear] = n;    
         rear++;
}
void Dequeue() {
        queue[front] = 0;       
        front++;
    
}
int Front() {
    return queue[front];
}
int main() 
{ 
char op[10]; 
    int x,y[100],i=0; 
    while (1) {
        scanf("%s", op); 
        if (op[0] == '#') break; 
        if (op[0] == 'A') { 
            scanf("%d", &x); 
            Enqueue(x); 
        }
        if (op[0] == 'R') { 
            i++;
            y[i-1] = Front();
            Dequeue();
        }
    }
   for(int j=0;j<=i-1;j++){printf("%d\n",y[j]); }        
    return 0;

}
