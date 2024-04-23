#include<stdlib.h>
#include<stdio.h>
int main (){
	int *arr1 = malloc(10 * sizeof(int));
	int *arr2 = calloc(10, sizeof(int));
	printf("%p\n",arr1);
	int *p=realloc(arr1,15*sizeof(int));
	printf("%p\n",p);
	free(arr1);
}
