#include<stdlib.h>
#include<stdio.h>
int main(){
	int n;
	scanf("%d", &n);
	int *arr=malloc(n*sizeof(int));
	for(int i=0;i<n;++i){
		scanf("%d",arr+i);
	}
 for(int j=n-1;j>=0;--j){
 	printf("%d",arr[j]);//a[i] = *(a+i)//
 }	
 free(arr);
}
