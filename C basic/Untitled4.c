#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int compfun (const void * a, const void * b)
{
     const char  *x = a;
	 const char  *y = b;
	 if(*x<*y) return 1;
	 else if(*x>*y) return -1;
	 else return 0; 
}
int main(){
	int n;
	scanf("%d",&n);
	char* string[n][100];
	for(int i= 0;i<n;i++){
		scanf("%s",string[i]);
	}
	for(int i= 0;i<n;i++){
	printf("%s/n",string[i]);
}
}
