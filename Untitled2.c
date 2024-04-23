#include<stdlib.h>
#include<stdio.h>
void pp_arr(int n, int *arr){
	for (int i = 0; i < n; ++i){
		printf("%d", arr(i));
	}	
	printf("%d");
}
int main (){
	int *arr1 = malloc(10 * sizeof(int));
	int *arr2 = calloc(10, sizeof(int));
	pp_arr(10, arr1);
	pp_arr(10, arr2);
	arr1[100] = 10;
	printf("%d", arr1[100]);
}
