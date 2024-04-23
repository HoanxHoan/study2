#include<stdio.h>
#include<stdlib.h>
#include <string.h>
int icmp(const void *p1,const void *p2){
	return *(const int *)p2 - *(const int *)p1;
}
typedef int (*cmp_t)(const void*,const void*);
void selsort(void*a,int n,int sz,cmp_t cmp){
	char *buff = malloc(sz);
	for(int i=0;i<n;i++){
		for(int j=i+1; j<n;j++){
			void *pi=a+i*sz,*pj=a+j*sz;
			if(cmp(pi,pj)>0){
				memcpy(buff,pi,sz);
				memcpy(pi,pj,sz);
				memcpy(pj,buff,sz);
			}
		}
	}
	free(buff);
}

int main(){
	int a[]={3,6,5,7,8,9,2,4,10};
	int n=sizeof(a)/sizeof(a[0]);
	selsort(a,n,sizeof(a[0]),icmp);
	for(int i=0;i<n;i++){
		printf("%d ",a[i]);
	}
}
